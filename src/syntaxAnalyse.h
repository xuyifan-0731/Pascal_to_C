//
// Created by 86159 on 2022/5/21.
//

#ifndef SYNTAXANALYSE_H
#define SYNTAXANALYSE_H
#include "main.h"
#include <utility>
#include <vector>
#include <string>
using namespace std;

class _Expression;

class _FunctionCall;

class _Reference;

class _Statement;

class _Compound;

class _Repeat;

class _While;

class _For;

class _If;

class _Assign;

class _Call;

class _Type;

class _Parameter;

class _Function;

class _Var;

class _Const;

class _ProgramBody;

class _Program;

typedef pair<string, int> IDpair;

class _Expression {
public:
    string type;//表达式类型,"var"表示变量,"integer"表示整数,"real"表示浮点数,"char"表示常量字符
    //"function"表示函数调用,"compound"表示复合表达式,
    //compound有普通的二目运算符，还有"minus"、"not"、"bracket"等单目运算符

    _Reference *variantReference{};//变量或常量或数组

    //所有形式都使用string进行存储
    string info;

    _FunctionCall *functionCall{};//函数调用

    string op;//具体操作符
    bool isSingle{};//记录操作符是否是单操作数
    _Expression *operand1{}, *operand2{};

    int lineNum{};//行号, 用表达式中最先出现的操作数的行号表示
    struct intInfo {
        int valueIntOnly;
        bool isIntCompleted;
    } intInfo{};

    string expressionType;//区别于type，这个值表示表达式的具体类型，即"integer"、"real"、"char"、"boolean"、"error"，其中error表示表达式中包含类型不一致的操作数
public:
    inline _Expression(){intInfo.isIntCompleted = false;};
};

class _FunctionCall {
public:
    IDpair ID;//函数标识符
    vector<_Expression *> argumentList;//实际参数列表，由表达式组成
};

class _Reference {
public:
    IDpair ID;//变量或常量标识符和行号
    bool isArray;
    vector<_Expression *> dimList;//各维引用表达式列表
public:
    inline int getArrayDim() const {
        if (isArray) {
            return this->dimList.size();
        }
        return -1;
    }
public:
    string kind;//"array","var","constant","function call","function return"
    string variantType;//"integer"、"real"、"char"、"boolean"、"error"
};

class _Statement {
public:
    string type;//"compound","repeat","while","for","if","assign","procedure"
};

class _Compound : public _Statement {
public:
    vector<_Statement *> statementList;//语句列表
};

class _Repeat : public _Statement {
public:
    _Expression *condition{};//条件表达式
    _Statement *_do{};//循环体语句
};

class _While : public _Statement {
public:
    _Expression *condition{};//条件表达式
    _Statement *body{};//循环体语句
};

class _For : public _Statement {
public:
    IDpair id;//循环变量
    _Expression *start;//起始值
    _Expression *end;//终止值
    _Statement *body;//循环体语句
};

class _If : public _Statement {
public:
    _Expression *condition{};//条件表达式
    _Statement *then{};//满足条件时执行的语句
    _Statement *els{};//不满足条件时执行的语句，如果为NULL，则没有else部分
public:
    inline bool getElseInfo() const {
        if (this->els != nullptr) return true;
        return false;
    }
};

class _Assign : public _Statement {
public:
    _Reference *variantReference{};//左值变量
    _Expression *expression{};//右值表达式
};

class _Call : public _Statement {
public:
    IDpair ID;//过程标识符
    vector<_Expression *> argumentList;//实际参数列表，由表达式组成
};

class _Type//类型
{
public:
    IDpair type;//基本类型及行号 "integer"、"char"、"real"、"boolean"
    bool isArray;
    vector<pair<int, int> > arrayRangeList;//isArray=1时，表示数组各维上下界
};

class _Parameter//形式参数
{
public:
    IDpair ID;//形式参数标识符和行号
    string type;//形式参数类型，形式参数一定是基本类型，所以改为string
    bool isRef;//传值还是引用
public:
    _Parameter(IDpair _paraId, string _type, int _flag): ID(std::move(_paraId)), type(std::move(_type)), isRef(_flag){};
};

class _Function {//函数/过程定义
public:
    IDpair ID;//函数/过程标识符及行号
    vector<_Parameter *> parameterList;//形式参数列表
    string retType;//如果retType是空串，则为过程，否则为函数,取值为"integer","real","boolean","char"四种
    vector<_Const *> constList;//常数定义列表
    vector<_Var *> variantList;//变量定义列表
    _Compound *compound;
};

class _Var//变量定义
{
public:
    IDpair ID;//变量标识符ID及行号
    _Type *type;//变量类型
public:
    _Var(IDpair _variantId, _Type *_type): ID(std::move(_variantId)), type(_type){};
};

class _Const//常量定义
{
public:
    IDpair ID;
    string type;//常数类型,分为"id","integer","real","char"
    string info;//所有常量取值的字符串表示
    bool isNegative;
};

class _ProgramBody//分程序
{
public:
    vector<_Const *> constList;//常数定义列表
    vector<_Var *> variantList;//变量定义列表
    vector<_Function *> FunctionProcedureList;//子程序和子函数定义列表
    _Compound *compound;//主程序体
};

class _Program//程序
{
public:
    IDpair programId;//PASCAL程序名称标识符及行号
    vector<IDpair > paraList;//PASCAL程序参数列表及行号
    _ProgramBody *programBody;//分程序
};

typedef vector<IDpair > record_vec;
typedef vector<pair<int, int> > array_vec;

class GetParseItem{
private:
    GetParseItem(); // 单例模式
public:
    static GetParseItem& GetInstance(){
        static GetParseItem a;
        return a;
    }
    static void get(Type *now, record_vec &res);
    static void ArrayRange(Type *now, array_vec &_arrayRangeList);
    static void get(Type *now, vector<_Var *> &_variantList);
    static void get(Type *now, vector<_Var *> &_variantList,string label);
    static _Type *getType(Type *now);
    static void get(Type *now, vector<_Const *> &_constantList);
    static void get(Type *now, vector<_Const *> &_constantList,string label);
    static void get(Type *now, vector<_Parameter *> &_formalParaList, int flag = 0);
    static void get(Type *now, vector<_Parameter *> &_formalParaList,string label);
};

void setConst(Type *now, _Const *&_constant);

void getFormalPara(Type *now, vector<_Parameter *> &_formalParaList);

void getProgramBodyHead(Type *now, IDpair &functionID, vector<_Parameter *> &_formalParaList,
                        string &_type);

_Expression *getFactor(Type *now);

_Expression *getTerm(Type *now);

_Expression *getSimpleExpression(Type *now);

_Expression *getExpression(Type *now);

void getExpressionList(Type *now, vector<_Expression *> &_expressionList);

_Reference *getReference(Type *now);

_Statement *getElseStatement(Type *now);

_Statement *getProcedureCall(Type *now);

_Statement *getStatement(Type *now);

void getStatementList(Type *now, vector<_Statement *> &_statementList);

_Compound *getCompoundStatement(Type *now);

void getProgramCompound(Type *now, vector<_Const *> &_constList, vector<_Var *> &_variantList, _Compound *&_compound);

_Function *getProgramDefinition(Type *now);

void getProgramBodyList(Type *now, vector<_Function *> &_subprogramDefinitionList);

_ProgramBody *getProgramBody(Type *now);

void ConstInfo(_Const *&_constant,string type,string info,bool isN);
void ConstInfo(_Const *&_constant,string type,string info);
void ExpBasicInfo(_Expression *&_expression,string type,int lineNum);
void ExpSingleInfo(_Expression *&_expression,bool isS,string op,_Expression *op1);
void ExpDoubleInfo(_Expression *&_expression,bool isS,string op,_Expression *op1,_Expression *op2);

_Program *getProgram(Type *now);
_Program *getProgram(Type *now);
void getProgramHead(Type *now, IDpair &_programId, vector<IDpair > &_paraList);
_ProgramBody *getProgramBody(Type *now);
void getProgramBodyList(Type *now, vector<_Function *> &_subprogramDefinitionList);
_Function *getProgramDefinition(Type *now);
void getProgramCompound(Type *now, vector<_Const *> &_constList, vector<_Var *> &_variantList, _Compound *&_compound);
_Compound *getCompoundStatement(Type *now);
void getStatementList(Type *now, vector<_Statement *> &_statementList);

#endif
