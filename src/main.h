/*
主头文件
*/
#ifndef MAIN_H
#define MAIN_H
#define YYERROR_VERBOSE
#define YYDEBUG 1


//#define LEXDEBUG 词法分析DEBUG开关
extern void outputErrors();

extern int errorCount;
extern int errorBound;


#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstring>
#include <vector>
#include <set>

extern int yydebug;
extern FILE *yyin;
using namespace std;
typedef pair<string, bool> FormalParaInfo;


//重新定义属性类型(yylval实际上应由yacc定义)
class Type {
public:
    string str;//终结符号的具体名称(m,n这种)
    string token;//终结符号或非终结符号本身的名称
    int lineNum{};//终结符号的行号
    vector<Type *> children; //对应产生式下面的结点

    Type() {}

    Type(string typ, string name, int ln) : str(typ), token(name), lineNum(ln) {}

    Type(string name, vector<Type *> cdn) : token(name), children(cdn) {}
};

// extern "C"是C++特有的指令（C无法使用该指令），目的在于支持C++与C混合编程。
extern "C" {
int yyparse();
}
void preProcess(string inName);
string process(string str);
bool outputLexErrorInformation();
bool outputSyntaxErrorInformation();
bool outputSemanticErrorInformation();
void outputErrors();

void preProcessing(string inName);
int lex_parse(string preName);
int semAna();
void codeGen(string outName);



class _SemanticError {
public:
    vector<pair<string, string>> semanticErrorInfo;

    _SemanticError() {
        semanticErrorInfo.clear();
    }
};

#define YYSTYPE Type*

#endif //!MAIN_H