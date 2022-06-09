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
//子程序声明
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

//子程序定义
typedef struct subProgramDefinition{
    vector<string> constIdList;     //常量名称列表
    vector<string> constTypeList;   //常量类型列表
    vector<string> constValueList;  //常量值列表

    vector<string> varIdList;       //局部变量名列表
    vector<string> varTypeList;     //局部变量类型列表
    vector<vector<int>> arraySizes; //每个数组类型的维度列表

    vector<pair<string, int>> sentences;    //程序，语句+缩进
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

    //获取表达式，若调用，应设parenLevel=9
    string getVariant(_Reference *variant, bool isReferredActual = false);

private:
    string file_name;
    _Program *ASTRoot;
    ofstream f_out;
    map<string, string> func2header;    //函数需要的头文件的映射
    //------------------variables------------------------
    vector<string> headers;                    //需要添加的头文件的集合
    vector<subProDeclare> subProDecList;    //子程序声明列表
    vector<subProDef> subProDefList;        //子程序定义列表
    string mainFuncDeclare;                 //主程序的声明
    vector<pair<string, int>> main_sentences;       //主程序的语句
    _SymTable *currentSymbolTabPtr = nullptr;    //符号表指针
    //常量
    vector<string> global_constIds;
    vector<string> global_constTypes;
    vector<string> global_constVals;
    //变量
    vector<string> global_varIds;
    vector<string> global_varTypes;
    //数组维度
    vector<vector<int>> main_arraySizes;
    //-------------------functions------------------------
    //工具函数
    void mapHeaders(const string& func_name);          //获取函数名对应的头文件
    static string pascalType2cType(const string& pascalType); //pascal基础类型转c基础类型
    static string pascalOp2cOp(string op);  //pascal运算符转c运算符
    static string pascalType2outputFormat(const string& type);    //根据数据类型转为格式字符串 e.g. integer=>%d
    static int isEqual(int num,...);
    static int biOpLevel(const string& cOperand);

    bool LibraryFunctionCall(_Call* procedureCall,
                             vector< pair<string, int> > &sentences, int retract); //检查并获取库程序
    void statementOfWrite(vector<_Expression *> actualParams,
                            vector< pair<string, int> > &sentences, int retract);//关于write语句的获取
    void statementOfBool(const string& expression,vector< pair<string, int> > &sentences, int retract);//关于bool类型输出语句的获取

    //获取pascal程序信息
    void getSubProDecList();    //获取所有子程序声明
    void getSubProDefList(const vector<_Function *>& subProList);     //获取所有子程序定义
    void getSubMainFunction();  //获取主程序

    static void getConstList(vector<_Const*> &constList, vector<string> &constIds,
                             vector<string> &constTypes, vector<string> &constVals,
                             _SymTable* symbolTablePtr);     //获取常量列表
    static void getVarList(vector<_Var*> &varList, vector<string> &varIds,
                           vector<string> &varTypes, vector<vector<int>> &varArraySizes,
                           _SymTable* symbolTablePtr);       //获取变量列表
    void getStatementList(_Statement * statementNode,
                          vector<pair<string, int>> &sentences,int retract, int flag=0);

    void getFunctionCall(_FunctionCall *funcCall, string &target);
    //获取变量

    //输出c语言程序
    void outputHeaders();       //输出头文件
    void outputMain(const string& programName); //输出main函数
    void outputSubProDefList(); //输出子程序定义

    void outputConsts(vector<string> &constIds, vector<string> &constTypes,
                      vector<string> &constVals, int tabs);     //输出常量列表
    void outputVars(vector<string> &varIds, vector<string> &varTypes,
                    vector<vector<int>> &arraySizes, int tabs); //输出变量列表
    void outputStatementList(vector< pair<string, int> > &sentences);   //输出语句

    void outputSubProDeclareHead(subProDeclare &declare);   //输出子程序声明的头部 e.g. int func()
    void outputSubProDeclareList();     //输出所有子程序声明
};
#endif //MAIN_CPP_CODEGENERATION_H
