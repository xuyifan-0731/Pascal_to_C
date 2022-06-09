/*
符号表实现代码
*/
#include "symTable.h"
#include <iostream>
#include <algorithm>


using namespace std;

_SymTable *mainSymbolTable;//主符号表
_SymTable *nowSymbolTable;//当前符号表

_SymRecord *searchsymbolRecord(_SymTable *nowSymbolTable, string id, int mode = 0);

_SymRecord::_SymRecord(string id, int lineNum) {
    this->arrayRangeList.clear();
    this->subSymbolTable = NULL;
    this->flag = "parameter of program";
    this->id = id;
    this->lineNum = lineNum;
}

_SymRecord::_SymRecord(string id, int lineNum, string type, string label) {
    this->arrayRangeList.clear();
    this->subSymbolTable = NULL;
    if(label=="Para"){
        flag = "value parameter";
        this->id = id;
        this->lineNum = lineNum;
        this->type = type;
    }
    else if(label=="VarPara"){
        flag = "var parameter";
        this->id = id;
        this->lineNum = lineNum;
        this->type = type;
    }
    else if(label=="Var"){
        flag = "normal variant";
        this->id = id;
        this->lineNum = lineNum;
        this->type = type;
    }
    else cout<<"error";
}

_SymRecord::_SymRecord(string id, int lineNum, string type, bool isNegative, string value){
    this->arrayRangeList.clear();
    this->subSymbolTable = NULL;
    flag = "constant";
    this->id = id;
    this->lineNum = lineNum;
    this->type = type;
    this->isNegative = isNegative;
    if (type == "char"){
        this->value += ("'" + value + "'");
    }
    else this->value += value;
}

_SymRecord::_SymRecord(string id, int lineNum, string type, int amount, vector< pair<int, int> > arrayRangeList){
    this->arrayRangeList.clear();
    this->subSymbolTable = NULL;
    flag = "array";
    this->id = id;
    this->lineNum = lineNum;
    this->type = type;
    this->amount = amount;
    this->arrayRangeList = arrayRangeList;
}

_SymRecord::_SymRecord(string id, int lineNum, int amount, _SymTable *subSymbolTable){
    this->arrayRangeList.clear();
    this->subSymbolTable = NULL;
    flag = "procedure";
    this->id = id;
    this->lineNum = lineNum;
    this->amount = amount;
    this->subSymbolTable = subSymbolTable;
}

_SymRecord::_SymRecord(string id, int lineNum, string type, int amount, _SymTable *subSymbolTable){
    this->arrayRangeList.clear();
    this->subSymbolTable = NULL;
    flag = "function";
    this->id = id;
    this->lineNum = lineNum;
    this->type = type;
    this->amount = amount;
    this->subSymbolTable = subSymbolTable;
    this->isReturnExist = false;
}

_SymRecord::_SymRecord(string id, int lineNum, string subprogramType, int amount, string returnType){
    this->arrayRangeList.clear();
    this->subSymbolTable = NULL;
    flag = "now program name";
    this->id = id;
    this->lineNum = lineNum;
    this->subprogramType = subprogramType;
    this->amount = amount;
    this->type = returnType;
}



bool _SymTable::isIDRepeat(string id){
    for (int i = 0; i <= this->symbolList[0]->amount + 3 && i < this->symbolList.size(); i++){
        if(!this->symbolList[i]) break;
        if(this->symbolList[i]->id==id)return true;
    }
    return false;
}

void _SymTable::addItem(string id, int lineNum, string type, bool e) {
    if (this->allDef.count(id)) {
        id = "[__Duplicate Name__]" + id;
    }
    if (e) {
        string label = "Para";
        _SymRecord *tempR = new _SymRecord(id, lineNum, type, label);
        this->symbolList.push_back(tempR);
        this->idList.push_back(tempR->id);
        this->allDef.insert(tempR->id);

    } else {
        string label = "VarPara";
        _SymRecord *tempR = new _SymRecord(id, lineNum, type, label);
        this->symbolList.push_back(tempR);
        this->idList.push_back(tempR->id);
        this->allDef.insert(tempR->id);

    }
}

void _SymTable::addItem(string id, int lineNum, string type) {
    string label = "Var";
    _SymRecord *tempR = new _SymRecord(id, lineNum, type,label) ;
    this->symbolList.push_back(tempR);
    this->idList.push_back(tempR->id);
    this->allDef.insert(tempR->id);

}

void _SymTable::addItem(string id, int lineNum, string type, bool isNegative, string value) {
    _SymRecord *tempR = new _SymRecord(id, lineNum, type, isNegative, value);
    this->symbolList.push_back(tempR);
    this->idList.push_back(tempR->id);
    this->allDef.insert(tempR->id);

}

void
_SymTable::addItem(string id, int lineNum, string type, int amount, vector<pair<int, int> > arrayRangeList) {
    _SymRecord *tempR = new _SymRecord(id, lineNum, type, amount, arrayRangeList);
    this->symbolList.push_back(tempR);
    this->idList.push_back(tempR->id);
    this->allDef.insert(tempR->id);

}

void _SymTable::addItem(string id, int lineNum, int amount, _SymTable *subSymbolTable) {
    _SymRecord *tempR = new _SymRecord(id, lineNum, amount, subSymbolTable);
    this->symbolList.push_back(tempR);
    this->idList.push_back(tempR->id);
    this->allDef.insert(tempR->id);

}

void _SymTable::addItem(string id, int lineNum, string type, int amount, _SymTable *subSymbolTable) {
    _SymRecord *tempR = new _SymRecord(id, lineNum, type, amount, subSymbolTable);
    this->symbolList.push_back(tempR);
    this->idList.push_back(tempR->id);
    this->allDef.insert(tempR->id);

}


void _SymTable::addItem(string id, int lineNum, string subprogramType, int amount, string returnType) {
    if (this->allDef.count(id)) {
        id = "[__Duplicate Name__]" + id;
    }
    _SymRecord *tempR = new _SymRecord(id, lineNum, subprogramType, amount, returnType);
    this->symbolList.push_back(tempR);
    this->idList.push_back(tempR->id);
    this->allDef.insert(tempR->id);
}

bool _SymTable::addItem(_Program *program) {
    bool Err = false;
    for (int i = 0; i < program->paraList.size(); i++) {//检查主程序参数是否和主程序名同名
        if (program->paraList[i].first == program->programId.first) //与主程序名同名
            Err = true;
        else{
            string ParaID = program->paraList[i].first;
            int ParaNum = program->paraList[i].second;
            if (this->allDef.count(ParaID)) { // 符号表中有同名的
                ParaID = "[__Duplicate Name__]" + ParaID; // 把原来符号表里的都加上下划线予以区分
            }
            _SymRecord *tempR = new _SymRecord(ParaID, ParaNum);
            this->symbolList.push_back(tempR);
            this->idList.push_back(tempR->id);
        }
    }
    return Err;
}

_SymTable::_SymTable(string type) {
    symbolList.clear();
    idList.clear();
    this->tableType = type;
    if(type=="main"){
        //为主符号表添加read,write
        this->addItem("read", -1, -1, NULL);
        this->addItem("write", -1, -1, NULL);
    }
}


FormalParaInfo _SymRecord::getFormalParaInfo(int x){
    //第0个位置存储函数名，因此需要+偏移值1
    int bias = 1;
    if ((this->flag == "function" || this->flag == "procedure") && x + bias >= 1 && x + bias< this->amount + 1) {
        FormalParaInfo info(subSymbolTable->symbolList[x + bias]->type,
                            subSymbolTable->symbolList[x + bias]->flag == "var parameter");
        return info;
    }
    FormalParaInfo info("error",false);
    return info;
}



//找出标识符在符号表中的位置
_SymRecord *searchsymbolRecord(_SymTable *nowSymbolTable, string id, int mode) {
    if (nowSymbolTable->allDef.count(id)) {
        vector<string>::iterator it = find(nowSymbolTable->idList.begin(),nowSymbolTable->idList.end(),id);
        int index=&*it-&nowSymbolTable->idList[0];
        return nowSymbolTable->symbolList[index];
    }
    if (mode != 0)
        return NULL;
    if (nowSymbolTable->tableType == "sub" && mainSymbolTable->allDef.count(id)) {
        vector<string>::iterator it = find(mainSymbolTable->idList.begin(),mainSymbolTable->idList.end(),id);
        int index=&*it-&mainSymbolTable->idList[0];
        return mainSymbolTable->symbolList[index];
    }
    return NULL;
}


//检查id是否是引用参数
bool checkIsReferredPara(_SymTable *nowSymbolTable, string id) {
    if (nowSymbolTable->tableType == "main")
        return false;
    if (nowSymbolTable->allDef.count(id)) {
        vector<string>::iterator it = find(nowSymbolTable->idList.begin(),nowSymbolTable->idList.end(),id);
        int index=&*it-&nowSymbolTable->idList[0];
        _SymRecord *record = nowSymbolTable->symbolList[index];
        return record->flag == "var parameter";
    } else
        return false;
}

bool checkIsUsed(string id) {
    if (mainSymbolTable->isIDRepeat(id)) {
        return true;
    }
    return false;

}