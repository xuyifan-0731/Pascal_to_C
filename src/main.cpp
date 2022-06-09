/*
运行环境：WIN32 C++14
*/
#include "main.h"
#include <fstream>
#include "codeGeneration.h"
#include "syntaxAnalyse.h"

class _Program;
extern Type *ParseTreeHead;
extern FILE *yyin;
extern int yydebug;

extern bool haveSyntaxError;

extern void SemanticAnalyse(_Program *ASTRoot);

extern vector<string> syntaxErrorInfo;

extern vector<string> lexErrorInfo;
_SemanticError SemanticError;
_Program *ASTRoot;

int main() {

    string inName = "PascalProgram.pas";
    string preName = "preProcessed.pas";
    string outName = "test.c";

    /*预处理*/
    preProcessing(inName);

    /*词法+语法分析*/
    int ret = lex_parse(preName);
    if(ret<=0) return 0;

    /*语义分析*/
    ret = semAna();
    if(ret<=0) return 0;

    /*代码生成*/
    codeGen(outName);


    return 0;
}

void preProcessing(string inName){
    /*预处理*/
    ifstream fin(inName.c_str());
    if(!fin){
        cerr<<"Open File Fail!"<<endl;
        exit(0);
    }
    fin.close();
    preProcess(inName); //对源程序进行大小写预处理
    cout<<"finish preProcess"<<endl;
}

int lex_parse(string preName){
    FILE* fp = fopen(preName.c_str(), "r");
    if (fp == nullptr) {
        cout<<"Cannot open "<<preName<<endl;
        return -1;
    }

    yyin = fp; //通过将打开文件指针赋值为yyin，给词法分析程序提供输入
    cout << "-----begin parsing" << endl;
    yyparse(); //开始语法分析
    fclose(fp);

    bool canContinueToSemanticAnalyse = true;
    if (lexErrorInfo.size() or haveSyntaxError) //如果有词法或语法错误
        canContinueToSemanticAnalyse = false;

    if (!canContinueToSemanticAnalyse) { //如果有词法或语法错误
        outputErrors();
        system("pause");
        return 0;
    }
    ASTRoot = getProgram(ParseTreeHead); // 这个ParseTreeHead应该是yacc生成的，extern变量
    cout << "-----end parsing" << endl << endl;

    return 1;
}

int semAna(){
    cout << "-----begin semantic analysing" << endl;
    SemanticAnalyse(ASTRoot);//语义分析
    if (!SemanticError.semanticErrorInfo.empty()) { //如果有语义错误
        outputErrors();
        system("pause");
        return 0;
    }
    cout << "-----end Semantic analyse" << endl << endl;
    return 1;
}

void codeGen(string outName){
    cout << "-----begin generating C Program code" << endl;
    auto generator = Generator(outName, ASTRoot);
    generator.run();
    cout << "-----end Code Generate" << endl;
    cout << "Please check C code in " << outName << endl << endl;
}



void outputErrors() {
    outputLexErrorInformation();
    outputSyntaxErrorInformation();
    outputSemanticErrorInformation();
}
void preProcess(string inName){
    ifstream fin(inName);
    ofstream fout("preProcessed.pas");
    string str;
    while (getline(fin,str)){
        if (!fin.eof())
            fout << process(str) << endl;
        else
            fout << process(str);
    }
    fin.close();
    fout.close();
}
string process(string str) {//由于PASCAL大小写不敏感，所以需要将所有字母转化为小写
    for (char & i : str) {
        if (i >= 'A' && i <= 'Z')
            i = i + ('a' - 'A');
    }
    return str;
}

/*输出词法分析中的错误信息*/
bool outputLexErrorInformation() {
    if (lexErrorInfo.empty())
        return false;
    cout << endl << "Here is the lex error information" << endl;
    for (auto & i : lexErrorInfo)
        cout << i << endl;
    cout << "Please correct your lexical errors" << endl << endl;
    return true;
}

/*输出语法分析中的错误信息*/
bool outputSyntaxErrorInformation() {
    if (syntaxErrorInfo.empty()) return false;
    else  {
        cout << "Here are the syntax errors*" << endl;
        for (auto & i : syntaxErrorInfo)
            cout << i << endl;
        cout << "Please correct your syntax errors" << endl << endl;
        return true;
    }
}

/*输出语义分析中的错误信息*/
bool outputSemanticErrorInformation(){
    if (SemanticError.semanticErrorInfo.empty()) return false;
    else  {
        cout << "Here are the semantic errors" << endl;
        for (auto & i : SemanticError.semanticErrorInfo)
            cout << i.first <<"  "<<i.second << endl;
        cout << "Please correct your semantic errors" << endl << endl;
        return true;
    }
}
