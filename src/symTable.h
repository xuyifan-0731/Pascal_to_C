/*
符号表头文件
*/
//通过了语法分析，则一定不存在函数的嵌套定义，而且子符号表只比主符号表少用了一些字段，因此主符号表和子符号表可以用同一个结构
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <string>
#include <vector>
#include <map>
#include <set>
#include "syntaxAnalyse.h"
#include "main.h"

using namespace std;

typedef pair<string,bool> FormalParaInfo;
extern string integer2string(int num);//将整数转化为字符串
extern _SemanticError SemanticError;
class _SymTable;

class _SymRecord {
public:
	string flag;
	string id;
	int lineNum;//行号
	string type;
    //如果是变量/常量，则表示变量/常量类型；
	//如果是数组，则表示数组元素的类型；
	//如果是函数，则表示函数返回值类型
	string value;//常量取值
	bool isNegative;//是否带负号
	int amount;
	//如果是数组，表示数组维数，如果是函数/过程，表示参数个数
	vector< pair<int,int> > arrayRangeList;//数组各维上下界
	_SymTable* subSymbolTable;//指向过程/函数对应的子符号表的指针
	string subprogramType;//表示程序是函数还是过程
    bool isReturnExist;//function是否存在return

    FormalParaInfo getFormalParaInfo(int x);//获取第x个形参的信息，返回变量名和一个bool，表示是否是引用参数

	_SymRecord(){
		arrayRangeList.clear();
		subSymbolTable = NULL;
	}
    _SymRecord(string id, int lineNum);
    _SymRecord(string id, int lineNum, string type, string label);
    _SymRecord(string id, int lineNum, string type, bool isNegative, string value);
    _SymRecord(string id, int lineNum, string type, int amount, vector< pair<int, int> > arrayRangeList);
    _SymRecord(string id, int lineNum, int amount, _SymTable *subSymbolTable);
    _SymRecord(string id, int lineNum, string type, int amount, _SymTable *subSymbolTable);
    _SymRecord(string id, int lineNum, string subprogramType, int amount, string returnType);
	~_SymRecord(){}
};

class _SymTable{
public:
	string tableType;//"main"或者"sub"
    set<string> allDef;
	vector<_SymRecord*> symbolList;
    vector<string> idList;//辅助快速查询符号位置
    //用于在符号表中添加新项目
    void addItem(string id, int lineNum, string type, bool e);
    void addItem(string id, int lineNum, string type);
    void addItem(string id, int lineNum, string type, bool isNegative, string value);
    void addItem(string id, int lineNum, string type, int amount, vector< pair<int, int> > arrayRangeList);
    void addItem(string id, int lineNum, int amount, _SymTable *subSymbolTable=NULL);
    void addItem(string id, int lineNum, string type, int amount, _SymTable *subSymbolTable=NULL);
    void addItem(string id, int lineNum, string subprogramType, int amount, string returnType);
    bool addItem(_Program *program);


    bool isIDRepeat(string id);

	_SymTable(string type = "sub");
	~_SymTable(){}
};

#endif //!SYMBOLTABLE_H
