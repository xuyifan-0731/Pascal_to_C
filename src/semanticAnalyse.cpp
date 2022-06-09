#include <string>
#include <utility>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include "symTable.h"
#include "syntaxAnalyse.h"
#include "codeGeneration.h"
#include "semanticAnalyse.h"

using namespace std;

constexpr std::uint32_t hash_str_to_uint32(const char *data) {
    std::uint32_t h(0);
    for (int i = 0; data && ('\0' != data[i]); i++)
        h = (h << 6) ^ (h >> 26) ^ data[i];
    return h;
}

void SemanticAnalyse(_Program *ASTRoot) {
    _Semantic SA(ASTRoot);
    SA.run();
}

void _Semantic::run() {
    nowSymbolTable = mainSymbolTable = new _SymTable("main");
    this->Program(this->ASTRoot);
    SemanticError.semanticErrorInfo = this->Errors.ErrorList;
}

//�Գ�������������
void _Semantic::Program(_Program *program) {
    //�����������Ϣ
    mainSymbolTable->addItem(program->programId.first, program->programId.second, "procedure",
                             int(program->paraList.size()), "");
    if (mainSymbolTable->addItem(program)) {
        this->Errors.RedefinedError(program->programId.first, program->programId.second);
    }
    //�Գ���������������
    this->ProgramBody(program->programBody);
}

//�Գ���������������
void _Semantic::ProgramBody(_ProgramBody *programBody) {
    int i = 0;
    while (i < programBody->constList.size()) {
        if (checkIsUsed(programBody->constList[i]->ID.first)) {
            i++;
            continue;
        }
        _SymRecord *record = searchsymbolRecord(nowSymbolTable, programBody->constList[i]->ID.first, 1);
        if (record != nullptr) {
            this->Errors.RedefinedError(record->id, record->lineNum, record->flag, record->type,
                                        programBody->constList[i]->ID.second);
            i++;
            continue;
        }
        this->Const(programBody->constList[i++]);
    }
    i = 0;
    while (i < programBody->variantList.size()) {
        if (checkIsUsed(programBody->variantList[i]->ID.first)) {
            i++;
            continue;
        }
        _SymRecord *record = searchsymbolRecord(nowSymbolTable, programBody->variantList[i]->ID.first,
                                                1);
        if (record != nullptr) {
            this->Errors.RedefinedError(record->id, record->lineNum, record->flag, record->type,
                                        programBody->variantList[i]->ID.second);
            i++;
            continue;
        }
        this->Variant(programBody->variantList[i++]);
    }
    i = 0;
    while (i < programBody->FunctionProcedureList.size()) {
        _SymRecord *record = searchsymbolRecord(nowSymbolTable,
                                                programBody->FunctionProcedureList[i]->ID.first, 1);
        if (record != nullptr) {
            this->Errors.RedefinedError(record->id, record->lineNum, record->flag, record->type,
                                        programBody->FunctionProcedureList[i]->ID.second);
            i++;
            continue;
        }
        this->FunctionDefinition(programBody->FunctionProcedureList[i++]);
        nowSymbolTable = mainSymbolTable;//���ű��ض�λ
    }
    // ���Ǳ任һ��ָ�����ͣ���compound���͵�ָ������statement���͵�
    this->Compound(programBody->compound);
}


//�Ա������ý����������
string _Semantic::LeftReference(_Reference *variantReference) {
    _SymRecord *record = searchsymbolRecord(nowSymbolTable, variantReference->ID.first);
    if (record == nullptr) {
        this->Errors.UndefinedError(variantReference->ID.first, variantReference->ID.second);
        return variantReference->variantType = "error";//�޷��ҵ��������õ�����
    }

    switch (hash_str_to_uint32(record->flag.c_str())) {
        case hash_str_to_uint32("now program name"): {
            //�������ֵ����ô�Ƿ�����䣬����Ҫ��ע����
            variantReference->kind = "function return";
            return variantReference->variantType = record->type;
        }
        case hash_str_to_uint32("function"): {
            //������Ϊ��ֵ��������Ϊ��ֵ
            this->Errors.AssignLeftValueError(record->id,
                                              variantReference->ID.second);
            return variantReference->variantType = "error";
        }
        case hash_str_to_uint32("constant"): {
            variantReference->kind = "constant";
            return variantReference->variantType = record->type;
        }
        case hash_str_to_uint32("value parameter"):
        case hash_str_to_uint32("var parameter"):
        case hash_str_to_uint32("normal variant"): {
            variantReference->kind = "var";
            return variantReference->variantType = record->type;
        }
        case hash_str_to_uint32("array"): {
            return this->ArrayVariantCheck(variantReference, record);
        }
    }
    return "error";
}

string _Semantic::RightReference(_Reference *variantReference) {
    _SymRecord *record = searchsymbolRecord(nowSymbolTable, variantReference->ID.first);
    if (record == nullptr) {//δ���� //checked
        this->Errors.UndefinedError(variantReference->ID.first, variantReference->ID.second);
        return variantReference->variantType = "error";//�޷��ҵ��������õ�����
    }
    //������Ϊ��ֵ����������⺯�������ݹ����Ҳ���ԣ�
    //����ֵ������ֵ���ǹ��̻��Ǻ������ǵ�ǰ���ű��Ӧ���ӳ������ơ����Ǳ���ӳ�������

    switch (hash_str_to_uint32(record->flag.c_str())) {
        case hash_str_to_uint32("now program name"): {
            //�޲κ����ĵݹ����
            variantReference->kind = "function call";
            return variantReference->variantType = record->type;
        }
        case hash_str_to_uint32("function"): {
            variantReference->kind = "function";
            return variantReference->variantType = record->type;
        }
        case hash_str_to_uint32("constant"): {
            variantReference->kind = "constant";
            return variantReference->variantType = record->type;
        }
        case hash_str_to_uint32("value parameter"):
        case hash_str_to_uint32("var parameter"):
        case hash_str_to_uint32("normal variant"): {
            variantReference->kind = "var";
            return variantReference->variantType = record->type;
        }
        case hash_str_to_uint32("array"): {
            return this->ArrayVariantCheck(variantReference, record);
        }
    }
    return "error";
}

//�����������
//��������±�ά���ͷ��ű����治һ�£��±��int������Խ��
string _Semantic::ArrayVariantCheck(_Reference *variantReference, _SymRecord *record) {
    variantReference->kind = "array";
    int arrayDim = record->amount;
    int varArrayDim = variantReference->getArrayDim();
    if (varArrayDim != arrayDim) {//�������ʱ���±�ά���ͷ��ű����治һ��
        this->Errors.NumberError(variantReference->ID.first, variantReference->ID.second,
                                 int(varArrayDim), arrayDim, "Array");
        variantReference->variantType = "error";
        return record->type;
    }
    variantReference->variantType = record->type;
    for (int i = 0; i < variantReference->dimList.size(); i++) {
        string indexType = this->Expression(variantReference->dimList[i]);
        //����±���ʽ�������Ƿ�������
        if (indexType != "integer") {
            this->Errors.ExpressionTypeError(variantReference->dimList[i], indexType, "integer",
                                             integer2string(i + 1) + "th index of array \"" +
                                             variantReference->ID.first + "\"");
            variantReference->variantType = "error";
        }
        //���Խ��
        if (variantReference->dimList[i]->intInfo.isIntCompleted) {
            int arrayIndex = variantReference->dimList[i]->intInfo.valueIntOnly;
            if (arrayIndex < record->arrayRangeList[i].first || arrayIndex > record->arrayRangeList[i].first) {
                this->Errors.ArrayRangeOutOfBoundError(variantReference->dimList[i],
                                                       variantReference->ID.first, i,
                                                       record->arrayRangeList[i]);
                variantReference->variantType = "error";
            }
        }
    }
    return record->type;
}


void _Semantic::Repeat(_Repeat *repeat) {
    string type = this->Expression(repeat->condition);
    switch (hash_str_to_uint32(type.c_str())) {
        case hash_str_to_uint32("boolean"): {
            break;
        }
        default: {
            this->Errors.ExpressionTypeError(repeat->condition, type, "boolean",
                                             "condition of repeat-until statement");
        }
    }
    this->Statement(repeat->_do);//��ѭ�����������������
}

void _Semantic::While(_While *pWhile) {
    string type = this->Expression(pWhile->condition);
    switch (hash_str_to_uint32(type.c_str())) {
        case hash_str_to_uint32("boolean"): {
            break;
        }
        default: {
            this->Errors.ExpressionTypeError(pWhile->condition, type, "boolean",
                                             "condition of while-do statement");
        }
    }
    this->Statement(pWhile->body);//��ѭ�����������������
}

void _Semantic::For(_For *pFor) {
    //���ѭ�������Ƿ��Ѿ����壬���Ѿ����壬�Ƿ�Ϊinteger�ͱ���
    _SymRecord *record = searchsymbolRecord(nowSymbolTable, pFor->id.first);
    if (record == nullptr) {//ѭ������δ���壬������Ϣ checked
        this->Errors.UndefinedError(pFor->id.first, pFor->id.second);
        return;
    }
    if (record->type != "integer") {
        this->Errors.ForConditionError(pFor->id.first, pFor->id.second, record->type,
                                    "cyclic variable of for statement", "integer");
        return;
    }
    //for������ͼ��,start��end���ʽ���ͼ��
    string type_start = this->Expression(pFor->start);
    string type_end = this->Expression(pFor->end);
    if (type_start != "integer" || type_end != "integer") {
        string errorType;
        _Expression *errorExp;
        if (type_start != "integer") {
            errorType = type_start;
            errorExp = pFor->start;
        }
        if (type_end != "integer") {
            errorType = type_end;
            errorExp = pFor->end;
        }
        this->Errors.ExpressionTypeError(errorExp, errorType, "integer", "start value of for statement");
    }
    //��ѭ�����������������
    this->Statement(pFor->body);
}

void _Semantic::If(_If *pIf) {
    string type = this->Expression(pIf->condition);
    switch (hash_str_to_uint32(type.c_str())) {
        case hash_str_to_uint32("boolean"): {
            break;
        }
        default: {
            this->Errors.ExpressionTypeError(pIf->condition, type, "boolean", "condition of if statement");
        }
    }
    this->Statement(pIf->then);//��then�������������
    if (pIf->getElseInfo())//��else������������
        this->Statement(pIf->els);
}


void _Semantic::Assign(_Assign *assign) {
    //assign��䲻֧���κ�����ת��
    //����ֵ����ֵ�ֱ�����������
    string leftType = this->LeftReference(assign->variantReference);
    string rightType = this->Expression(assign->expression);
    //��ֵ����Ϊ����
    if (assign->variantReference->kind == "constant") {

        this->Errors.AssignLeftValueError(assign->variantReference->ID.first,
                                          assign->variantReference->ID.second);
        return;
    }
    //����Ƿ���ֵ��䣬���鷵��ֵ���ʽ�Ƿ�ͺ�������ֵ����һ��
    if (assign->variantReference->kind == "function return") {
        if (assign->variantReference->variantType != rightType) {
            this->Errors.FunctionReturnMismatch(assign, rightType);
        }
        _SymRecord *record = searchsymbolRecord(mainSymbolTable, assign->variantReference->ID.first);
        record->isReturnExist = true;
        return;
    }
    //�Ƚ���ֵ����ֵ����
    if (leftType != rightType) {
        this->Errors.AssignTypeMismatchError(assign->variantReference, assign->expression);
    }
}

_SymRecord *searchFromAllSymbolRecord(const string &id) {
    _SymRecord *record = searchsymbolRecord(mainSymbolTable, id);
    if (record == nullptr) record = searchsymbolRecord(nowSymbolTable, id);
    return record;
}

void _Semantic::Procedure(_Call *procedure) {
    //ͨ��procedureId�����ò����������������͵���Ϣ
    _SymRecord *record = searchFromAllSymbolRecord(procedure->ID.first);
    if (record == nullptr) {//δ����
        this->Errors.UndefinedError(procedure->ID.first, procedure->ID.second);
        return;
    }
    if (record->flag != "procedure") {//������ǹ���
        this->Errors.TypeMismatchError(procedure->ID.first, procedure->ID.second, "procedure",
                                       record->lineNum, record->flag);
        return;
    }
    //read,write����Ϊ0���޷�ͨ���������
    if (record->id == "read") {//read����:����������Ԫ��
        for (int i = 0; i < procedure->argumentList.size(); i++) {
            string actualType = this->Expression(procedure->argumentList[i]);
            if (!(procedure->argumentList[i]->type == "var" &&
                  (procedure->argumentList[i]->variantReference->kind == "var" ||
                   procedure->argumentList[i]->variantReference->kind == "array")))
                this->Errors.ReadError(procedure->argumentList[i]->lineNum, record->id,
                                       i + 1, procedure->argumentList[i]);
        }
        return;
    }
    if (record->id == "write") {//write��������error��ѭ����������
        for (int i = 0; i < procedure->argumentList.size(); i++) {
            this->Expression(procedure->argumentList[i]);
        }
        return;
    }
    //������������
    if (procedure->argumentList.size() != record->amount) {
        this->Errors.NumberError(procedure->ID.first, procedure->ID.second,
                                 int(procedure->argumentList.size()), record->amount, "Procedure");
        return;
    }
    // �β��ڷ��ű��еĶ�λ
    for (int i = 0; i < procedure->argumentList.size(); i++) {//���actualParaList�����ʽ�����ͣ����ʵ�κ��βε�����һ����
        string actualType = this->Expression(procedure->argumentList[i]);
        FormalParaInfo info = record->getFormalParaInfo(i);
        string formalType = info.first;
        if (actualType != formalType) { //������Ͳ�һ��
            this->Errors.ExpressionTypeError(procedure->argumentList[i], actualType, formalType,
                                             integer2string(i + 1) +
                                             "th actual parameter of procedure call of \"" +
                                             procedure->ID.first + "\"");
        }
    }
}

void _Semantic::Compound(_Compound *compound) {
    for (auto &i: compound->statementList) {
        this->Statement(i);
    }

}

//���������������
void _Semantic::Statement(_Statement *statement) {
    // ��Statement���;���Ϊ��ͳһ��ʽ��������ʱ�򶼱��statement�������Ժ��ٸ���type��ת��
    int type = getStatementType(statement);
    switch (type) {
        case COMPOUNDNUM: {
            _Compound *compound = reinterpret_cast<_Compound *>(statement);
            this->Compound(compound);
            break;
        }
        case REPEATNUM: {
            _Repeat *repeatStatement = reinterpret_cast<_Repeat *>(statement);
            this->Repeat(repeatStatement);
            break;
        }
        case WHILENUM: {
            _While *whileStatement = reinterpret_cast<_While *>(statement);
            this->While(whileStatement);
            break;
        }
        case FORNUM: {
            _For *forStatement = reinterpret_cast<_For *>(statement);
            this->For(forStatement);
            break;
        }
        case IFNUM: {
            _If *ifStatement = reinterpret_cast<_If *>(statement);
            this->If(ifStatement);
            break;
        }
        case ASSNUM: {
            _Assign *assignStatement = reinterpret_cast<_Assign *>(statement);
            this->Assign(assignStatement);
            break;
        }
        case PRODNUM: {
            _Call *procedureCall = reinterpret_cast<_Call *>(statement);
            this->Procedure(procedureCall);
            break;
        }
        default :
            cout << "[SemanticAnalyseStatement] statement Type error" << endl;
            return;
    }
}

//����ʽ�������������������ʽ����һ���ǻ�������
void _Semantic::Parameter(_Parameter *Parameter) {
    //����Ƿ������������������������������ͬ��
    _SymRecord *record = searchsymbolRecord(nowSymbolTable, Parameter->ID.first, 1);
    if (!checkIsUsed(Parameter->ID.first)) {
        if (record != nullptr) //����ض���
            this->Errors.RedefinedError(record->id, record->lineNum, record->flag, record->type,
                                        Parameter->ID.second);
    }
    //����Ƿ��뵱ǰ�������Լ�����֮ǰ������β�ͬ�������ͬ�������token���лָ�����add�����н��У�
    bool isVar = false;
    if (!Parameter->isRef) {
        isVar = true;
    }
    nowSymbolTable->addItem(Parameter->ID.first, Parameter->ID.second,
                            Parameter->type, isVar);

}

//���ӳ���������������
void _Semantic::FunctionDefinition(_Function *functionDefinition) {
    string programBodyType;
    if (functionDefinition->retType.empty())
        programBodyType = "procedure";
    else
        programBodyType = "function";
    nowSymbolTable = new _SymTable("sub");//��������λ���ӷ��ű�
    //���ӳ���������Ϣ��ӵ��ӷ��ű���
    nowSymbolTable->addItem(functionDefinition->ID.first, functionDefinition->ID.second,
                            programBodyType, int(functionDefinition->parameterList.size()),
                            functionDefinition->retType);

    switch (hash_str_to_uint32(programBodyType.c_str())) {
        case hash_str_to_uint32("procedure"): {
            mainSymbolTable->addItem(functionDefinition->ID.first, functionDefinition->ID.second,
                                     int(functionDefinition->parameterList.size()), nowSymbolTable);
            break;
        }
        case hash_str_to_uint32("function"): {
            mainSymbolTable->addItem(functionDefinition->ID.first, functionDefinition->ID.second,
                                     functionDefinition->retType, int(functionDefinition->parameterList.size()),
                                     nowSymbolTable);
            break;
        }
    }
    for (int i = 0; i < functionDefinition->parameterList.size(); i++)
        this->Parameter(functionDefinition->parameterList[i]);

    for (int i = 0; i < functionDefinition->constList.size(); i++)
        this->Const(functionDefinition->constList[i]);

    for (int i = 0; i < functionDefinition->variantList.size(); i++)
        this->Variant(functionDefinition->variantList[i]);

    //��compound�����������
    this->Compound(functionDefinition->compound);
    //�Ժ������з���ֵ���Ĵ����Լ��
    if (programBodyType == "function") //checked
        this->Errors.ReturnExistedWarning(functionDefinition);
}

//�Ա�����������������
void _Semantic::Variant(_Var *variant) {
    switch (variant->type->isArray) {
        case 0: {
            nowSymbolTable->addItem(variant->ID.first, variant->ID.second, variant->type->type.first);
            break;
        }
        case 1: {
            //���鶨��ʱ�����½���������Ͻ������ڵ����½�
            for (int i = 0; i < variant->type->arrayRangeList.size(); i++) {
                int down = variant->type->arrayRangeList[i].first, up = variant->type->arrayRangeList[i].second;
                if (down > up) {
                    this->Errors.ArrayRangeBoundError(variant->ID.first, variant->ID.second, i + 1,
                                                      down, up);
                }
            }
            nowSymbolTable->addItem(variant->ID.first, variant->ID.second, variant->type->type.first,
                                    int(variant->type->arrayRangeList.size()), variant->type->arrayRangeList);
        }
    }
}

//�Գ�����������������
void _Semantic::Const(_Const *constant) {
    nowSymbolTable->addItem(constant->ID.first, constant->ID.second, constant->type,
                            constant->isNegative, constant->info);
}


string _Semantic::FunctionCall(_FunctionCall *functionCall) {
    //�����ű��ǰ���ű� ����һ���ҵõ���
    _SymRecord *record = searchFromAllSymbolRecord(functionCall->ID.first);
    if (record == nullptr) {//δ���� checked
        this->Errors.UndefinedError(functionCall->ID.first, functionCall->ID.second);
        return "error";
    }
    if (record->flag != "function") {//���Ǻ��� checked
        this->Errors.TypeMismatchError(functionCall->ID.first, functionCall->ID.second, "function",
                                       record->lineNum, record->flag);
        return "error";
    }
    int funParaNum = functionCall->argumentList.size();
    if (funParaNum != record->amount) {//����������һ�� checked
        this->Errors.NumberError(functionCall->ID.first, functionCall->ID.second,
                                 int(functionCall->argumentList.size()), record->amount, "Function");
        return record->type;
    }
    //����λ�õ�ʵ�κ��β������Ƿ�һ�� �β��ڷ��ű��еĶ�λ
    for (int i = 0; i < funParaNum; i++) {
        string actualType = this->Expression(functionCall->argumentList[i]);
        FormalParaInfo info = record->getFormalParaInfo(i);
        string formalType = info.first;
        if (actualType != formalType && !(actualType == "integer" && formalType == "real")) //checked
            this->Errors.ExpressionTypeError(functionCall->argumentList[i], actualType, formalType,
                                             integer2string(i + 1) + "th actual parameter of function call of \"" +
                                             functionCall->ID.first + "\"");
    }
    return record->type;
}


string _Semantic::Expression(_Expression *expression) {
    switch (hash_str_to_uint32(expression->type.c_str())) {
        case hash_str_to_uint32("var"): {
            string varType = this->RightReference(expression->variantReference);
            if (varType == "integer" && expression->variantReference->kind == "constant") {//int���͵ĳ���
                //����ű�������ֵ
                _SymRecord *record = searchsymbolRecord(nowSymbolTable, expression->variantReference->ID.first);
                expression->intInfo.valueIntOnly = stoi(record->value);
                if (record->isNegative)
                    expression->intInfo.valueIntOnly = (-1) * expression->intInfo.valueIntOnly;
                expression->intInfo.isIntCompleted = true;
            }
            expression->expressionType = varType;
            return varType;
        }
        case hash_str_to_uint32("integer"): {
            expression->intInfo.valueIntOnly = atoi(expression->info.c_str());
            expression->intInfo.isIntCompleted = true;
            return expression->expressionType = "integer";
        }
        case hash_str_to_uint32("real"): {
            return expression->expressionType = "real";
        }
        case hash_str_to_uint32("char"): {
            return expression->expressionType = "char";
        }
        case hash_str_to_uint32("function"): {
            return expression->expressionType = this->FunctionCall(expression->functionCall);
        }
        case hash_str_to_uint32("compound"): {
            switch (hash_str_to_uint32(expression->op.c_str())) {
                case hash_str_to_uint32("bracket"): {
                    expression->expressionType = this->Expression(expression->operand1);
                    if (expression->expressionType == "integer" && expression->operand1->intInfo.isIntCompleted) {
                        expression->intInfo.valueIntOnly = expression->operand1->intInfo.valueIntOnly;
                        expression->intInfo.isIntCompleted = true;
                    }
                    return expression->expressionType;
                }
                case hash_str_to_uint32(">"):
                case hash_str_to_uint32(">="):
                case hash_str_to_uint32("<"):
                case hash_str_to_uint32("<="):
                case hash_str_to_uint32("<>"):
                case hash_str_to_uint32("="): {
                    string leftType = this->Expression(expression->operand1);
                    string rightType = this->Expression(expression->operand2);
                    if (leftType != "error" && rightType != "error") {
                        if (leftType != rightType) {
                            if (!typeChangable(leftType, rightType))
                                return expression->expressionType = "error";
                        }
                        return expression->expressionType = "boolean";
                    }
                    break;
                }
                case hash_str_to_uint32("not"): {
                    string type = this->Expression(expression->operand1);
                    if (type == "boolean")
                        return expression->expressionType = "boolean";
                    break;
                }
                case hash_str_to_uint32("minus"): {
                    string epType = this->Expression(expression->operand1);

                    if (epType == "integer" || epType == "real") {
                        if (epType == "integer" && expression->operand1->intInfo.isIntCompleted) {
                            expression->intInfo.valueIntOnly = -expression->operand1->intInfo.valueIntOnly;
                            expression->intInfo.isIntCompleted = true;
                        }
                        return expression->expressionType = epType;
                    }
                    break;
                }
                case hash_str_to_uint32("+"):
                case hash_str_to_uint32("-"):
                case hash_str_to_uint32("*"):
                case hash_str_to_uint32("/"): {
                    string leftType = this->Expression(expression->operand1);
                    string rightType = this->Expression(expression->operand2);
                    if (expression->op == "/" && rightType == "integer" &&
                        expression->operand2->intInfo.isIntCompleted &&
                        expression->operand2->intInfo.valueIntOnly == 0)
                        this->Errors.DivideZeroError(expression->op, expression->operand2);
                    if (leftType == "integer" && rightType == "integer") {
                        if (expression->operand1->intInfo.isIntCompleted &&
                            expression->operand2->intInfo.isIntCompleted) {
                            expression->intInfo.isIntCompleted = true;
                            expression->intInfo.valueIntOnly = calculateOP(expression->operand1->intInfo.valueIntOnly,
                                                                           expression->operand2->intInfo.valueIntOnly,
                                                                           expression->op);
                        }

                    }
                    if (leftType != rightType && returnCalculateType(leftType, rightType) != "error") {
                        this->Errors.MismatchWarning(expression, leftType, rightType);
                    }
                    return returnCalculateType(leftType, rightType);
                }
                case hash_str_to_uint32("div"):
                case hash_str_to_uint32("mod"): {
                    string leftType = this->Expression(expression->operand1);
                    string rightType = this->Expression(expression->operand2);
                    if (rightType == "integer" && expression->operand2->intInfo.isIntCompleted &&
                        expression->operand2->intInfo.valueIntOnly == 0)
                        this->Errors.DivideZeroError(expression->op, expression->operand2);
                    if (leftType == "integer" && rightType == "integer") {
                        if (expression->operand1->intInfo.isIntCompleted &&
                            expression->operand2->intInfo.isIntCompleted) {
                            expression->intInfo.valueIntOnly = calculateOP(expression->operand1->intInfo.valueIntOnly,
                                                                           expression->operand2->intInfo.valueIntOnly,
                                                                           expression->op);
                            expression->intInfo.isIntCompleted = true;
                        }
                        return expression->expressionType = "integer";
                    } else {
                        this->Errors.IntDivisionError(expression, leftType, rightType);
                    }
                    break;
                }
                case hash_str_to_uint32("and"):
                case hash_str_to_uint32("or"): {
                    string leftType = this->Expression(expression->operand1);
                    string rightType = this->Expression(expression->operand2);
                    if (leftType != rightType && returnLogicType(leftType, rightType) != "error") {
                        this->Errors.MismatchWarning(expression, leftType, rightType);
                    }
                    return returnLogicType(leftType, rightType);
                }
                default: {
                    return expression->expressionType = "error";
                }
            }

        }
        default: {
            return expression->expressionType = "error";
        }
    }
}

void _SemanticErrorProcessing::AssignLeftValueError(const string &preId, int preLineNumber) {
    ErrorInfo error;
    error.first = "[Left value error] Constant or Function Name \"" + preId +
                  "\" can't be referenced as l-value.";
    error.second = "<Line" + integer2string(preLineNumber) +
                   ">";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::RedefinedError(const string &preId, int preLineNumber) {
    ErrorInfo error;
    error.first = "[Redefined error]  parameter of program \"" + preId +
                  "\" is the same as name of program.";
    error.second = "<Line" + integer2string(preLineNumber) +
                   ">";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::RedefinedError(const string &preId, int preLineNumber, const string &preFlag,
                                              const string &preType,
                                              int curLineNumber) {
    ErrorInfo error;
    error.first = "[Redefined error] \"" + preId + "\"" + " has already been defined as a " + preFlag + " at line " +
                  integer2string(preLineNumber) + ".";
    error.second = "<Line" + integer2string(preLineNumber) +
                   ">";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::UndefinedError(const string &id, int LineNumber) {
    ErrorInfo error;
    error.first = "[Undefined identifier]" + id + " has not been defined.";
    error.second = "<Line" + integer2string(LineNumber) +
                   ">";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::ForConditionError(const string &curId, int curLineNumber, const string &curType,
                                              const string &usage, const string &correctType) {
    ErrorInfo error;
    error.first = "[For Condition error]" + curId + " (used in  " +
                  usage +
                  " ) correct Type is " + correctType + ", but in a wrong Type: " + curType + ".";
    error.second = "<Line" + integer2string(curLineNumber) +
                   ">";
    this->ErrorList.push_back(error);
}

//�����±������ƥ�䡢��������̵�ʵ�κ��βεĸ�����ƥ��
void _SemanticErrorProcessing::NumberError(const string &curId, int curLineNumber, int curNumber, int correctNumber,
                                           const string &usage) {
    ErrorInfo error;
    string errorInformation;
    if (usage == "Array")
        error.first = "[" + usage + "index number mismatch] Array \"" + curId +
                      "\"" +
                      " ( correct indices number is " + integer2string(correctNumber) + ") but now in " +
                      integer2string(curNumber) + " indices.";
    else {
        error.first = "[" + usage + "parameter number mismatch] " + usage + " \"" + curId +
                      "\"" + " ( correct parameters number is " + integer2string(correctNumber) + " but now in " +
                      integer2string(curNumber) +
                      " parameters.";
    }
    error.second = "<Line" + integer2string(curLineNumber) +
                   ">";
    this->ErrorList.push_back(error);

}

void
_SemanticErrorProcessing::TypeMismatchError(const string &curId, int curLineNumber, const string &curFlag, int preLineNumber,
                                            const string &preFlag) {
    ErrorInfo error;
    error.first = "[Symbol kinds mismatch] \"" + curId + "\"" + " defined at line " + integer2string(preLineNumber) +
                  "( correct Type is " + preFlag +
                  " ) but now is " +
                  curFlag + ".";
    error.second = "<Line" + integer2string(curLineNumber) +
                   ">";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::ExpressionTypeError(_Expression *exp, const string &curType, const string &correctType,
                                                   const string &description) {
    string expression = this->semanticGenerator.getExpression(exp);
    ErrorInfo error;
    error.first =
            "[Expression Type error]" "Expression \"" + expression + "\" used for " + description + " should be " +
            correctType + " but not " +
            curType + ".";
    error.second = "<Line" + integer2string(exp->lineNum) +
                   ">";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::AssignTypeMismatchError(_Reference *leftVariantReference,
                                                       _Expression *rightExpression) {
    auto varRef = this->semanticGenerator.getVariant(leftVariantReference);
    auto exp = this->semanticGenerator.getExpression(rightExpression);
    ErrorInfo error;
    error.first = "[Assign statement Type mismatch] Left \"" + varRef + "\" Type is " +
                  leftVariantReference->variantType + ", right \"" + exp +
                  "\" Type is wrong" + rightExpression->expressionType + ".";
    error.second = "<Left at line " + integer2string(leftVariantReference->ID.second) + ", right at line " +
                   integer2string(rightExpression->lineNum) + "> ";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::ArrayRangeOutOfBoundError(_Expression *expression, const string &arrayId, int X,
                                                         pair<int, int> range) {
    auto exp = this->semanticGenerator.getExpression(expression);
    ErrorInfo error;
    error.first = "[Array range out of bound] The value of expression \"" + exp + "\"" + " is " +
                  integer2string(expression->intInfo.valueIntOnly) +
                  ", out of the range of array \"" + arrayId + "\" ( correct range of " + integer2string(X) +
                  "th index is " +
                  integer2string(range.first) + " to " +
                  integer2string(range.second) + " )";
    error.second = "<Line " + integer2string(expression->lineNum) + "> ";
    this->ErrorList.push_back(error);
}


void _SemanticErrorProcessing::ArrayRangeBoundError(const string &curId, int curLineNumber, int X, int lowBound,
                                                    int highBound) {
    ErrorInfo error;
    error.first = "[Array range error] " + integer2string(X) + "th range of array \"" + curId +
                  "\", low bound is larger than high bound, respectively" +
                  integer2string(lowBound) + " and " + integer2string(highBound) + ".";
    error.second = "<Line " + integer2string(curLineNumber) + "> ";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::ReadError(int curLineNumber, const string &procedureId, int X, _Expression *exp) {
    string expression = this->semanticGenerator.getExpression(exp);
    ErrorInfo error;
    error.first = "[Read parameter error] " + semanticGenerator.getExpression(exp) + " \"" + procedureId + "\" " +
                  integer2string(X) + "th expression parameter \"" + expression +
                  "\" can not be read, please input a variant or an array element.";
    error.second = "<Line " + integer2string(curLineNumber) + "> ";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::DivideZeroError(const string &operation, _Expression *exp) {
    string expression = this->semanticGenerator.getExpression(exp);
    ErrorInfo error;
    error.first = "[[Divide zero error] " + semanticGenerator.getExpression(exp) + " The value of expression \"" +
                  expression + "\" is 0, which can not be divided.";
    error.second = "<Line " + integer2string(exp->lineNum) + "> ";
    this->ErrorList.push_back(error);
}


void _SemanticErrorProcessing::FunctionReturnMismatch(_Assign *assignStatement, const string &rightType) {
    ErrorInfo error;
    error.first =
            "[Return Type of function mismatch]  The Type of return expression is " + rightType + " ,but not " +
            assignStatement->variantReference->variantType + " as function \"" +
            assignStatement->variantReference->ID.first + "\" defined.";
    error.second = "<Line " +
                   integer2string(assignStatement->expression->lineNum) +
                   ">";
    this->ErrorList.push_back(error);
}

void _SemanticErrorProcessing::ReturnExistedWarning(_Function *function) {
    _SymRecord *record = searchsymbolRecord(mainSymbolTable, function->ID.first);
    if (record->isReturnExist) return;
    cout << "[Warning: Function has no return] No return in function " + function->ID.first << endl;
}

void _SemanticErrorProcessing::MismatchWarning(_Expression *exp, string leftType, string rightType) {
    string expression = this->semanticGenerator.getExpression(exp);
    string expression1 = this->semanticGenerator.getExpression(exp->operand1);
    string expression2 = this->semanticGenerator.getExpression(exp->operand2);
    cout << "[Warning:Operation mismatch] In " + expression + ", Left expression " + expression1 + " is a " + leftType +
            ", while Right expression " + expression2 + " is a " + rightType + ". <Line " +
            integer2string(exp->lineNum) + "> " << endl;
}

void _SemanticErrorProcessing::IntDivisionError(_Expression *exp, string leftType, string rightType) {
    string expression = this->semanticGenerator.getExpression(exp);
    string expression1 = this->semanticGenerator.getExpression(exp->operand1);
    string expression2 = this->semanticGenerator.getExpression(exp->operand2);
    ErrorInfo error;
    if (leftType == "integer") {
        error.first = "[Int division error] In int division " + expression + ", left expression " + expression1 +
                      "should be integer, but now is " + leftType + ".";
    } else if (rightType == "integer") {
        error.first = "[Int division error] In int division " + expression + ", right expression " + expression2 +
                      "should be integer, but now is " + rightType + ".";
    } else {
        error.first = "[Int division error] In int division " + expression +
                      ", expressions should both be integer, but now are " + leftType + " and " + rightType + ".";
    }
    error.second = "<Line " + integer2string(exp->lineNum) + "> ";
    this->ErrorList.push_back(error);
}


int getStatementType(_Statement *statement) {
    map<string, int> type2int;
    type2int["compound"] = 0;
    type2int["repeat"] = 1;
    type2int["while"] = 2;
    type2int["for"] = 3;
    type2int["if"] = 4;
    type2int["assign"] = 5;
    type2int["procedure"] = 6;
    if (type2int.find(statement->type) == type2int.end()) {
        return -1;
    }
    return type2int.find(statement->type)->second;
}


string integer2string(int num) {
    stringstream str;
    str << num;  // ���ǰ�intת����string����
    return str.str();
}

string returnCalculateType(const string &x, const string &y) {
    if (x == "integer" && y == "integer") return "integer";
    if (x == "integer" && y == "real") return "integer";
    if (x == "real" && y == "integer") return "integer";
    if (x == "real" && y == "real") return "real";
    return "error";
}

string returnLogicType(const string &x, const string &y) {
    if (x == "boolean" && y == "boolean") return "boolean";
    return "error";
}

int calculateOP(int x, int y, const string &op) {
    if (op == "+")return x + y;
    if (op == "-")return x - y;
    if (op == "*")return x * y;
    if (op == "/" || op == "div")return x / y;
    if (op == "%")return x % y;
    return 0;
}

bool typeChangable(const string &x, const string &y) {
    //ֻ��int��real�����໥ת��
    if (x == "real" && y == "integer")return true;
    if (y == "real" && x == "integer")return true;
    return false;
}