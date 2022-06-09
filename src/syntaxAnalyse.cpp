#include "main.h"
#include "syntaxAnalyse.h"
#include <string>
#include <algorithm>
constexpr std::uint32_t hash_str_to_uint32(const char *data) {
    std::uint32_t h(0);
    for (int i = 0; data && ('\0' != data[i]); i++)
        h = (h << 6) ^ (h >> 26) ^ data[i];
    return h;
}



//IDlist
void GetParseItem::get(Type *now, record_vec &res) {
    if (now->children[0]->str == "") {
        res.emplace_back(now->children[2]->str, now->children[2]->lineNum);
        GetParseItem::get(now->children[0], res);
    } else {
        res.emplace_back(now->children[0]->str, now->children[0]->lineNum);
    }
}

void GetParseItem::ArrayRange(Type *now, array_vec &_arrayRangeList) {
    int loc = int(now->children.size() - 3);
    _arrayRangeList.emplace_back(stoi(now->children[loc]->str), stoi(now->children[loc + 2]->str));
    if (loc == 2)
        GetParseItem::ArrayRange(now->children[0], _arrayRangeList);
    else
        reverse(_arrayRangeList.begin(), _arrayRangeList.end());
}

//type
_Type *GetParseItem::getType(Type *now) {
    auto *_type = new _Type;
    int loc = int(now->children.size() - 1);
    _type->type = make_pair(now->children[loc]->str, now->children[loc]->lineNum);
    if (loc == 5) {
        _type->isArray = true;
        GetParseItem::ArrayRange(now->children[2], _type->arrayRangeList);
    } else
        _type->isArray = false;
    return _type;
}

//var
void GetParseItem::get(Type *now, vector<_Var *> &_variantList) {
    record_vec _idList;
    int loc = int(now->children.size() - 3);
    GetParseItem::get(now->children[loc], _idList);
    _Type *_type = GetParseItem::getType(now->children[loc + 2]);
    for (auto & i : _idList)
        _variantList.emplace_back(new _Var(i, _type));
    if (loc == 2)
        GetParseItem::get(now->children[0], _variantList);
    else
        reverse(_variantList.begin(), _variantList.end());
}

//var list
void GetParseItem::get(Type *now, vector<_Var *> &_variantList,string label) {
    if (!now->children.empty())
        GetParseItem::get(now->children[1], _variantList);
}



void setConst(Type *now, _Const *&_constant) {//pascal在定义常量时，并没有指定常量的类型，所以需要自行判断
    int loc = 1;
    if (now->children.size() == 1)
        loc = 0;
    string locToken = now->children[loc]->token;
    string rightToken = now->children[0]->token;
    if (locToken == "IDENTIFIER" || "identifier" == rightToken) {//如果右值是标识符
        ConstInfo(_constant,"id",now->children[loc]->str,(loc == 1 && now->children[0]->token == "-"));
    } else if (locToken == "UINUM" || rightToken == "uinum") {
        ConstInfo(_constant,"integer",now->children[loc]->str,(loc == 1 && now->children[0]->token == "-"));
    } else if (locToken == "UFNUM" || rightToken == "ufnum") {
        ConstInfo(_constant,"real",now->children[loc]->str,(loc == 1 && rightToken == "-"));
    } else if (locToken == "CHAR" || rightToken == "char") {
        ConstInfo(_constant,"char",now->children[loc]->str);
    }
}

//const
void GetParseItem::get(Type *now, vector<_Const *> &_constantList) {
    int loc = int(now->children.size() - 3);
    auto *_constant = new _Const;
    _constant->ID = make_pair(now->children[loc]->str, now->children[loc]->lineNum);
    setConst(now->children[loc + 2], _constant);
    _constantList.emplace_back(_constant);
    if (loc == 2)
        GetParseItem::get(now->children[0], _constantList);
    else
        reverse(_constantList.begin(), _constantList.end());
}

//const list
void GetParseItem::get(Type *now, vector<_Const *> &_constantList,string label) {
    if (!now->children.empty())
        GetParseItem::get(now->children[1], _constantList);
}

//paraval
void GetParseItem::get(Type *now, vector<_Parameter *> &_formalParaList, int flag) {
    record_vec _idList;
    GetParseItem::get(now->children[0], _idList);
    for (auto & i : _idList){
        _formalParaList.emplace_back(new _Parameter(i, now->children[2]->str, flag));
    }

}


void getFormalPara(Type *now, vector<_Parameter *> &_formalParaList) {
    int loc = int(now->children.size() - 1);
    auto nc = now->children[loc];
    if (nc->children[0]->token == "var_parameter")
        GetParseItem::get(nc->children[0]->children[1], _formalParaList, 1);
    else if (nc->children[0]->token == "value_parameter")
        GetParseItem::get(nc->children[0], _formalParaList, 0);
    else
        cout << "error" << endl;

    if (loc == 2)
        getFormalPara(now->children[0], _formalParaList);
    else
        reverse(_formalParaList.begin(), _formalParaList.end());
}

void GetParseItem::get(Type *now, vector<_Parameter *> &_formalParaList,string label) {
    if (!now->children.empty())
        getFormalPara(now->children[1], _formalParaList);
}

void getProgramBodyHead(Type *now, IDpair &functionID, vector<_Parameter *> &_formalParaList,
                        string &_type) {
    functionID.first = now->children[1]->str;
    functionID.second = now->children[1]->lineNum;
    GetParseItem::get(now->children[2], _formalParaList,"multi");
    _type = "";
    if ( 5 == now->children.size() )
        _type = now->children[4]->str;
}



//"var"表示变量,"integer"表示整数,"real"表示浮点数,"char"表示字符常量
//"function"表示函数调用,"compound"表示复合表达式
//compound有普通的二目运算符，还有minus、not、bracket等单目运算符
_Expression *getFactor(Type *now) {
    auto *_expression = new _Expression;
    _expression->operand1 = _expression->operand2 = nullptr;
    auto nct = now->children[0]->token;
    switch(hash_str_to_uint32(nct.c_str())){
        case hash_str_to_uint32("UINUM"):
        case hash_str_to_uint32("uinum"):{
            ExpBasicInfo(_expression,"integer",now->children[0]->lineNum);
            _expression-> info = now->children[0]->str;
            break;
        }
        case hash_str_to_uint32("variable"):{
            _expression->variantReference = getReference(now->children[0]);
            ExpBasicInfo(_expression,"var",_expression->variantReference->ID.second);
            break;
        }
        case hash_str_to_uint32("IDENTIFIER"):{
            ExpBasicInfo(_expression,"function",_expression->functionCall->ID.second);
            _expression->functionCall = new _FunctionCall;
            _expression->functionCall->ID = make_pair(now->children[0]->str, now->children[0]->lineNum);
            getExpressionList(now->children[2], _expression->functionCall->argumentList);
            break;
        }
        case hash_str_to_uint32("("):{
            ExpSingleInfo(_expression,true,"bracket",getExpression(now->children[1]));
            ExpBasicInfo(_expression,"compound",_expression->operand1->lineNum);
            break;
        }
        case hash_str_to_uint32("NOT"):{
            ExpSingleInfo(_expression,true,"not",getFactor(now->children[1]));
            ExpBasicInfo(_expression,"compound",_expression->operand1->lineNum);
            break;
        }
        case hash_str_to_uint32("-"):{
            ExpSingleInfo(_expression,true,"minus",getFactor(now->children[1]));
            ExpBasicInfo(_expression,"compound",_expression->operand1->lineNum);
            break;
        }
        case hash_str_to_uint32("char"):
        case hash_str_to_uint32("CHAR"):{
            ExpBasicInfo(_expression,"char",now->children[0]->lineNum);
            _expression-> info = now->children[0]->str[0];
            break;
        }
    }
    return _expression;

}

_Expression *getTerm(Type *now) {
    _Expression *_expression = nullptr;
    if (now->children.size() == 3) {
        _expression = new _Expression;
        ExpDoubleInfo(_expression,false,now->children[1]->str,getTerm(now->children[0]),getFactor(now->children[2]));
        ExpBasicInfo(_expression,"compound",_expression->operand1->lineNum);
    } else
        _expression = getFactor(now->children[0]);
    return _expression;
}

_Expression *getSimpleExpression(Type *now) {
    _Expression *_expression = nullptr;
    if (now->children.size() - 3 == 0) {
        _expression = new _Expression;
        ExpDoubleInfo(_expression,false,now->children[1]->str,getSimpleExpression(now->children[0]),getTerm(now->children[2]));
        ExpBasicInfo(_expression,"compound",_expression->operand1->lineNum);
    } else{
        _expression = getTerm(now->children[0]);
    }
    return _expression;
}

_Expression *getExpression(Type *now) {
    _Expression *_expression;
    if (now->children.size() == 3) {
        _expression = new _Expression;
        ExpDoubleInfo(_expression,false,now->children[1]->str,getSimpleExpression(now->children[0]),getSimpleExpression(now->children[2]));
        ExpBasicInfo(_expression,"compound",_expression->operand1->lineNum);
    } else
        _expression = getSimpleExpression(now->children[0]);
    auto copy = _expression;
    return copy;
}

void getExpressionList(Type *now, vector<_Expression *> &_expressionList) {
    int loc = int(now->children.size()) - 1;
    _expressionList.emplace_back(getExpression(now->children[loc]));
    if (loc == 2)
        getExpressionList(now->children[0], _expressionList);
    else
        reverse(_expressionList.begin(), _expressionList.end());
}



_Reference *getReference(Type *now) {
    _Reference *_variantReference = new _Reference;
    _variantReference->ID = make_pair(now->children[0]->str, now->children[0]->lineNum);
    auto nc = now->children[1];
    if (nc->children.size())
        getExpressionList(nc->children[1], _variantReference->dimList);

    if (_variantReference->dimList.size())
        _variantReference->isArray = true;
    else
        _variantReference->isArray = false;
    return _variantReference;
}

_Statement *getElseStatement(Type *now) {
    if (now->children.empty())
        return nullptr;
    return getStatement(now->children[1]);
}

_Statement *getProcedureCall(Type *now) {
    auto *_procedureCall = new _Call;
    _procedureCall->type = "procedure";
    _procedureCall->ID = make_pair(now->children[0]->str, now->children[0]->lineNum);
    if (4 == now->children.size())
        getExpressionList(now->children[2], _procedureCall->argumentList);
    return _procedureCall;
}

_Statement *getStatement(Type *now) {
    if (now->children.empty())
        return nullptr;
    switch(hash_str_to_uint32(now->children[0]->token.c_str())){
        case hash_str_to_uint32("variable"):{
            auto *_assignStatement = new _Assign;
            _assignStatement->type = "assign";
            _assignStatement->variantReference = getReference(now->children[0]);
            _assignStatement->expression = getExpression(now->children[2]);
            return _assignStatement;
        }
        case hash_str_to_uint32("procedure_call"):{
            return getProcedureCall(now->children[0]);
        }
        case hash_str_to_uint32("compound_statement"):{
            return getCompoundStatement(now->children[0]);
        }
        case hash_str_to_uint32("IF"):
        case hash_str_to_uint32("if"):{
            auto *_ifStatement = new _If;
            _ifStatement->type = "if";
            _ifStatement->condition = getExpression(now->children[1]);
            _ifStatement->then = getStatement(now->children[3]);
            _ifStatement->els = getElseStatement(now->children[4]);
            return _ifStatement;
        }
        case hash_str_to_uint32("FOR"):
        case hash_str_to_uint32("for"):{
            auto *_forStatement = new _For;
            _forStatement->type = "for";
            _forStatement->id = make_pair(now->children[1]->str, now->children[1]->lineNum);
            _forStatement->start = getExpression(now->children[3]);
            _forStatement->end = getExpression(now->children[5]);
            _forStatement->body = getStatement(now->children[7]);
            return _forStatement;
        }
        case hash_str_to_uint32("WHILE"):
        case hash_str_to_uint32("while"):{
            auto *_whileStatement = new _While;
            _whileStatement->type = "while";
            _whileStatement->condition = getExpression(now->children[1]);
            _whileStatement->body = getStatement(now->children[3]);
            return _whileStatement;
        }
        case hash_str_to_uint32("REPEAT"):
        case hash_str_to_uint32("repeat"):{
            auto *_repeatStatement = new _Repeat;
            _repeatStatement->type = "repeat";
            _repeatStatement->condition = getExpression(now->children[3]);
            _repeatStatement->_do = getStatement(now->children[1]);
            return _repeatStatement;
        }
        default:return nullptr;

    }
}

void getStatementList(Type *now, vector<_Statement *> &_statementList) {
    int loc = int(now->children.size() - 1);
    _Statement *statement = getStatement(now->children[loc]);
    if (statement != nullptr)
        _statementList.emplace_back(statement);
    if (loc == 2)
        getStatementList(now->children[0], _statementList);
    else
        reverse(_statementList.begin(), _statementList.end());
}

_Compound *getCompoundStatement(Type *now) {
    auto *_compound = new _Compound;
    _compound->type = "compound";
    getStatementList(now->children[1], _compound->statementList);
    return _compound;
}

void getProgramCompound(Type *now, vector<_Const *> &_constList, vector<_Var *> &_variantList, _Compound *&_compound) {
    GetParseItem::get(now->children[0], _constList,"multi");
    GetParseItem::get(now->children[1], _variantList, "multi");
    _compound = getCompoundStatement(now->children[2]);
}

_Function *getProgramDefinition(Type *now) {
    _Function *_functionDefinition = new _Function;
    getProgramBodyHead(now->children[0], _functionDefinition->ID, _functionDefinition->parameterList,
                       _functionDefinition->retType);
    getProgramCompound(now->children[2], _functionDefinition->constList, _functionDefinition->variantList,
                       _functionDefinition->compound);
    return _functionDefinition;
}

void getProgramBodyList(Type *now, vector<_Function *> &_subprogramDefinitionList) {
    if (!now->children.empty()) {
        _subprogramDefinitionList.emplace_back(getProgramDefinition(now->children[1]));
        getProgramBodyList(now->children[0], _subprogramDefinitionList);
    }
}

_ProgramBody *getProgramBody(Type *now) {
    auto *_subProgram = new _ProgramBody;
    GetParseItem::get(now->children[0], _subProgram->constList,"multi");
    GetParseItem::get(now->children[1], _subProgram->variantList,"multi");
    getProgramBodyList(now->children[2], _subProgram->FunctionProcedureList);
    _subProgram->compound = getCompoundStatement(now->children[3]);
    return _subProgram;
}

_Program *getProgram(Type *now) {
    auto *ASTRoot = new _Program;
    ASTRoot->programId = make_pair(now->children[0]->children[1]->str, now->children[0]->children[1]->lineNum);
    GetParseItem::get(now->children[0], ASTRoot->paraList);
    ASTRoot->programBody = getProgramBody(now->children[2]);
    return ASTRoot;
}

void ConstInfo(_Const *&_constant,string type,string info,bool isN){
    _constant->type = type;
    _constant->info = info;
    _constant->isNegative = isN;
}

void ConstInfo(_Const *&_constant,string type,string info){
    _constant->type = type;
    _constant->info = info;
}

void ExpBasicInfo(_Expression *&_expression,string type,int lineNum){
    _expression->type = type;
    _expression->lineNum = lineNum;
}

void ExpSingleInfo(_Expression *&_expression,bool isS,string op,_Expression *op1){
    _expression->isSingle = isS;
    _expression->op = op;
    _expression->operand1 = op1;
}

void ExpDoubleInfo(_Expression *&_expression,bool isS,string op,_Expression *op1,_Expression *op2){
    _expression->isSingle = isS;
    _expression->op = op;
    _expression->operand1 = op1;
    _expression->operand2 = op2;
}