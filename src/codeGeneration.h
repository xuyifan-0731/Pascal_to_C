//
// Created by Nebulous on 2022/5/9.
//

#ifndef MAIN_CPP_CODEGENERATION_H
#define MAIN_CPP_CODEGENERATION_H

#include "symTable.h"
#include "syntaxAnalyse.h"
#include "main.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <set>
#include <utility>
#include <cstdarg>
//�ӳ�������
typedef struct subProgramDeclaration{
    string returnType;
    string id;
    vector<string> paramIdList;
    vector<bool> paramIsRefList;
    vector<string> paramTypeList;
    void clear(){
        paramIdList.clear();
        paramIsRefList.clear();
        paramTypeList.clear();
    }
}subProDeclare;

//�ӳ�����
typedef struct subProgramDefinition{
    vector<string> constIdList;     //���������б�
    vector<string> constTypeList;   //���������б�
    vector<string> constValueList;  //����ֵ�б�

    vector<string> varIdList;       //�ֲ��������б�
    vector<string> varTypeList;     //�ֲ����������б�
    vector<vector<int>> arraySizes; //ÿ���������͵�ά���б�

    vector<pair<string, int>> sentences;    //�������+����
}subProDef;

class Generator{
public:
    Generator(string out_file_name, _Program *ASTRoot){
        this->ASTRoot = ASTRoot;
        this->file_name = move(out_file_name);
        this->func2header["read"] = "stdio.h";
        this->func2header["write"] = "stdio.h";
        this->func2header["writeln"] = "stdio.h";
        this->func2header["boolean"] = "stdbool.h";
        this->mainFuncDeclare = "void "+ASTRoot->programId.first+"()";
    }
    Generator(){
        this->func2header["read"] = "stdio.h";
        this->func2header["write"] = "stdio.h";
        this->func2header["writeln"] = "stdio.h";
        this->func2header["boolean"] = "stdbool.h";
    };
    void init(string out_file_name, _Program *ASTRoot){
        this->ASTRoot = ASTRoot;
        this->file_name = move(out_file_name);
        this->mainFuncDeclare = "void "+ASTRoot->programId.first+"()";
    }
    void run();

    string getExpression(_Expression *expression, int parentLevel=9, bool isReferred = false);

    //��ȡ���ʽ�������ã�Ӧ��parenLevel=9
    string getVariant(_Reference *variant, bool isReferredActual = false);

private:
    string file_name;
    _Program *ASTRoot;
    ofstream f_out;
    map<string, string> func2header;    //������Ҫ��ͷ�ļ���ӳ��
    //------------------variables------------------------
    vector<string> headers;                    //��Ҫ��ӵ�ͷ�ļ��ļ���
    vector<subProDeclare> subProDecList;    //�ӳ��������б�
    vector<subProDef> subProDefList;        //�ӳ������б�
    string mainFuncDeclare;                 //�����������
    vector<pair<string, int>> main_sentences;       //����������
    _SymTable *currentSymbolTabPtr = nullptr;    //���ű�ָ��
    //����
    vector<string> global_constIds;
    vector<string> global_constTypes;
    vector<string> global_constVals;
    //����
    vector<string> global_varIds;
    vector<string> global_varTypes;
    //����ά��
    vector<vector<int>> main_arraySizes;
    //-------------------functions------------------------
    //���ߺ���
    void mapHeaders(const string& func_name);          //��ȡ��������Ӧ��ͷ�ļ�
    static string pascalType2cType(const string& pascalType); //pascal��������תc��������
    static string pascalOp2cOp(string op);  //pascal�����תc�����
    static string pascalType2outputFormat(const string& type);    //������������תΪ��ʽ�ַ��� e.g. integer=>%d
    static int isEqual(int num,...);
    static int biOpLevel(const string& cOperand);

    bool LibraryFunctionCall(_Call* procedureCall,
                             vector< pair<string, int> > &sentences, int retract); //��鲢��ȡ�����
    void statementOfWrite(vector<_Expression *> actualParams,
                            vector< pair<string, int> > &sentences, int retract);//����write���Ļ�ȡ
    void statementOfBool(const string& expression,vector< pair<string, int> > &sentences, int retract);//����bool����������Ļ�ȡ

    //��ȡpascal������Ϣ
    void getSubProDecList();    //��ȡ�����ӳ�������
    void getSubProDefList(const vector<_Function *>& subProList);     //��ȡ�����ӳ�����
    void getSubMainFunction();  //��ȡ������

    static void getConstList(vector<_Const*> &constList, vector<string> &constIds,
                             vector<string> &constTypes, vector<string> &constVals,
                             _SymTable* symbolTablePtr);     //��ȡ�����б�
    static void getVarList(vector<_Var*> &varList, vector<string> &varIds,
                           vector<string> &varTypes, vector<vector<int>> &varArraySizes,
                           _SymTable* symbolTablePtr);       //��ȡ�����б�
    void getStatementList(_Statement * statementNode,
                          vector<pair<string, int>> &sentences,int retract, int flag=0);

    void getFunctionCall(_FunctionCall *funcCall, string &target);
    //��ȡ����

    //���c���Գ���
    void outputHeaders();       //���ͷ�ļ�
    void outputMain(const string& programName); //���main����
    void outputSubProDefList(); //����ӳ�����

    void outputConsts(vector<string> &constIds, vector<string> &constTypes,
                      vector<string> &constVals, int tabs);     //��������б�
    void outputVars(vector<string> &varIds, vector<string> &varTypes,
                    vector<vector<int>> &arraySizes, int tabs); //��������б�
    void outputStatementList(vector< pair<string, int> > &sentences);   //������

    void outputSubProDeclareHead(subProDeclare &declare);   //����ӳ���������ͷ�� e.g. int func()
    void outputSubProDeclareList();     //��������ӳ�������
};
#endif //MAIN_CPP_CODEGENERATION_H
