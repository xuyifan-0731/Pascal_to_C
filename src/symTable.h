/*
���ű�ͷ�ļ�
*/
//ͨ�����﷨��������һ�������ں�����Ƕ�׶��壬�����ӷ��ű�ֻ�������ű�������һЩ�ֶΣ���������ű���ӷ��ű������ͬһ���ṹ
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
extern string integer2string(int num);//������ת��Ϊ�ַ���
extern _SemanticError SemanticError;
class _SymTable;

class _SymRecord {
public:
	string flag;
	string id;
	int lineNum;//�к�
	string type;
    //����Ǳ���/���������ʾ����/�������ͣ�
	//��������飬���ʾ����Ԫ�ص����ͣ�
	//����Ǻ��������ʾ��������ֵ����
	string value;//����ȡֵ
	bool isNegative;//�Ƿ������
	int amount;
	//��������飬��ʾ����ά��������Ǻ���/���̣���ʾ��������
	vector< pair<int,int> > arrayRangeList;//�����ά���½�
	_SymTable* subSymbolTable;//ָ�����/������Ӧ���ӷ��ű��ָ��
	string subprogramType;//��ʾ�����Ǻ������ǹ���
    bool isReturnExist;//function�Ƿ����return

    FormalParaInfo getFormalParaInfo(int x);//��ȡ��x���βε���Ϣ�����ر�������һ��bool����ʾ�Ƿ������ò���

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
	string tableType;//"main"����"sub"
    set<string> allDef;
	vector<_SymRecord*> symbolList;
    vector<string> idList;//�������ٲ�ѯ����λ��
    //�����ڷ��ű����������Ŀ
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
