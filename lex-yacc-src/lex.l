%{
#include "main.h"
#include "yacc.tab.h"
#include <sstream>
#include<iomanip>

#define MAXIDLEN 20   #最大标识符长度
extern YYLTYPE yylloc;
#define YY_USER_ACTION yylloc.first_line = yylloc.last_line = yylineno; \
    yylloc.first_column = yycolumn; yylloc.last_column = yycolumn+yyleng-1; \
    yycolumn += yyleng;

int yycolumn = 1;    
int char_start_column = 0;
int comment_start_line = 0;
int comment_start_column = 0;
vector<string> lexErrorInfo;   #存储错误信息

void addLexError(string type,string error,int l,int r); 

extern "C"
{
	int yywrap();
	int yylex();
}
%}

%option yylineno   # 开启行号

%x CH SCOMMENT MCOMMENT1 MCOMMENT2


letter [a-z]
digit [0-9]
id {letter}({letter}|{digit})*
digits {digit}+
float {digits}\.{digits}
relop (>=|>|<=|<>|<)
addop (\+|or)
mulop (\*|\/|div|mod|and)
delimiter (\(|\)|\[|\]|:|,|;|\.)
_type (integer|real|boolean|char)
blank [ \f\r\t\v]+

%%

{blank} {}

"program" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="PROGRAM";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return PROGRAM;
}

"const" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="CONST";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
  cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return CONST;
}

"var" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="VAR";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return VAR;
}

"array" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="ARRAY";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
   cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return ARRAY;
}

"of" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="OF";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
   cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return OF;
}

"procedure" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="PROCEDURE";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
   cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return PROCEDURE;
}

"function" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="FUNCTION";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return FUNCTION;
}

"begin" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="BEGIN";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return _BEGIN;
}

"end" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="END";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return END;
}

"if" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="IF";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
   cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return IF;
}

"then" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="THEN";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return THEN;
}

"for" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="FOR";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return FOR;
}

"to" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="TO";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
   cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return TO;
}

"do" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="DO";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
   cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return DO;
}

"else" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="ELSE";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return ELSE;
}

"repeat" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="REPEAT";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return REPEAT;
}

"until" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="UNTIL";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return UNTIL;
}

"while" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="WHILE";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return WHILE;
}


{_type} {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="TYPE";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return TYPE;
}

{relop} {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="RELOP";
    yylval->lineNumber = yylineno;

#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return RELOP;
}

"=" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token = yytext;
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return yytext[0];
}

{addop} {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="ADDOP";
    yylval->lineNumber = yylineno;

#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return ADDOP;
}

"-" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token = yytext;
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
	return yytext[0];
}

{mulop} {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token = "MULOP";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return MULOP;
}

"not" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token=yytext;
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return NOT;
}


{id} {
    if(yyleng>MAXIDLEN){
        addLexError("[Error]", "The identifier exceeds the limit length.     ", yylineno, yycolumn-yyleng);
        yytext[MAXIDLEN] = 0; //截断处理
    }
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="IDENTIFIER";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return IDENTIFIER;
}

{digits} {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="UINUM";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return UINUM;	
}

{float} {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="UFNUM";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return UFNUM;
}

":=" {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="ASSIGNOP";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return ASSIGNOP;
}

"\.\." {
    yylval=new Type;
    yylval->str=yytext;
    yylval->token="RANGEDOT";
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return RANGEDOT;
}


{delimiter} {
    yylval=new Type;
    yylval->str = yytext;
    yylval->token = yytext;
    yylval->lineNumber = yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    return yytext[0];
}



"'" {//进入字符常量识别
    BEGIN CH;
    char_start_column = yycolumn-1;
}

"\/\/" {//进入//单行注释
    	BEGIN SCOMMENT;
}

"\{" {//进入{...}多行注释
	comment_start_column = yycolumn - yyleng;
	comment_start_line = yylineno;
	BEGIN MCOMMENT1;	
}

"\(\*" {//进入(*...*)多行注释
	comment_start_column = yycolumn - yyleng;
	comment_start_line = yylineno;
    	BEGIN MCOMMENT2;
}

"\n" {
    yycolumn=1;
}

. {//非法字符 
    string c = yytext;
    addLexError("[Error]", "Invalid character "+c, yylineno, yycolumn-yyleng);
}

<CH><<EOF>> {
    addLexError("[Error]", "Unexpected end of file when reading a char constant,lacking '     ", yylineno, char_start_column);
    return 0;
}

<CH>"'" {
    int len = strlen(yytext);
    string c(1,yytext[0]);
    // 处理异常情况 
    if (len==1){   //空字符
        addLexError("[Error]","empty character constant.     ",yylineno, char_start_column);
        c = "\0";
     }
    if(len>2){   //多字符
         addLexError("[Warning]","multi-character character constant.     ",yylineno, char_start_column);
    }

    yylval = new Type;
    yylval->str=c;
    yylval->token="CHAR";
    yylval->lineNumber=yylineno;
#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif
    BEGIN INITIAL;
    return CHAR;
}

<CH>"\n" {
    // 报错
    addLexError("[Error]","missing terminating ' character     ",yylineno-1, char_start_column);
   
    // 处理字符常量
    int len = strlen(yytext);
    string c(1,yytext[0]);
    if(len==1) c="\0";
    
    // 创建yylval
    yylval = new Type;
    yylval->str = c;
    yylval->token="CHAR";
    yylval->lineNumber=yylineno;

#ifdef LEXDEBUG
    cout <<  setw(10) << setiosflags(ios::left)<< yylval->token << " | "<<yylval->str << endl;
#endif

    BEGIN INITIAL;
    yycolumn=1;
    return CHAR;
}



<CH>. {
    yymore();
}

<SCOMMENT><<EOF>> { //单行注释遇到文件尾
    return 0;
}

<SCOMMENT>"\n" {
    yycolumn=1;
    BEGIN INITIAL;
}

<SCOMMENT>. {}

<MCOMMENT1><<EOF>> { //单行注释遇到文件尾
     addLexError("[Error]", "Unexpected end of file when reading a multiple line comment,lacking }     ", comment_start_line, comment_start_column);
    return 0;
}

<MCOMMENT1>"\n" {
    yycolumn=1;
}
<MCOMMENT1>"\}" { //多行注释正常结束
    BEGIN INITIAL;
}

<MCOMMENT1>. {}

<MCOMMENT2><<EOF>> { //多行注释遇到文件尾 
    addLexError("[Error]", "Unexpected end of file when reading a multiple line comment, lacking *)     ", comment_start_line, comment_start_column);
    return 0;
}

<MCOMMENT2>"\*\)" {  //多行注释正常结束
    BEGIN INITIAL;
}

<MCOMMENT2>"\n" {
    yycolumn=1;
}

<MCOMMENT2>. {}

%%
void addLexError(string type,string error,int l,int r){  //添加错误信息
    stringstream sin1,sin2;
    sin1 <<l;
    sin2 <<r;
    string info = type+ error + "  line " + sin1.str() + " , column " +sin2.str();
    lexErrorInfo.push_back(info);
}
int yywrap() { return 1; }

