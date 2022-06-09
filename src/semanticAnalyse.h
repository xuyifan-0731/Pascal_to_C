//
// Created by 徐逸凡 on 2022/5/13.
//

#ifndef MAIN_CPP_SEMANTICANALYSE_H
#define MAIN_CPP_SEMANTICANALYSE_H
#define COMPOUNDNUM 0
#define REPEATNUM 1
#define WHILENUM 2
#define FORNUM 3
#define IFNUM 4
#define ASSNUM 5
#define PRODNUM 6

extern _SymTable *mainSymbolTable;//主符号表
extern _SymTable *nowSymbolTable;//当前符号表
extern _SymRecord *searchsymbolRecord(_SymTable *nowSymbolTable, string id, int mode = 0);//从符号表中找出id对应的记录
extern _SemanticError SemanticError;
extern string integer2string(int num);//将整数转化为字符串
extern bool checkIsUsed(string id);
typedef pair<string,string> ErrorInfo;

using namespace std;

class _SemanticErrorProcessing{
public:
    vector<ErrorInfo> ErrorList;
    Generator semanticGenerator;
    _SemanticErrorProcessing(){
        ErrorList.clear();
        this->semanticGenerator = Generator();
    }
    void RedefinedError(const string& preId, int preLineNumber);//添加重定义错误信息
    void RedefinedError(const string& preId, int preLineNumber, const string& preFlag, const string& preType,int curLineNumber);
    void UndefinedError(const string& id, int curLineNumber);//添加未定义错误信息
    void ForConditionError(const string& curId, int curLineNumber, const string& curType, const string& usage, const string& correctType);//添加标识符类型错误信息
    void NumberError(const string& curId, int curLineNumber, int curNumber, int correctNumber, const string& usage);//添加数量错误错误信息
    void TypeMismatchError(const string& curId, int curLineNumber, const string& curFlag, int preLineNumber, const string& preFlag);//添加标识符种类错误信息
    void ExpressionTypeError(_Expression *exp, const string& curType, const string& correctType, const string& description);//添加表达式类型错误信息
    void AssignTypeMismatchError(_Reference *leftVariantReference, _Expression *rightExpression);//添加赋值语句左值和右值类型不匹配错误信息
    void ArrayRangeOutOfBoundError(_Expression *expression, const string& arrayId, int X, pair<int, int> range);//添加数组下标越界错误信息
    void ArrayRangeBoundError(const string &curId, int curLineNumber, int X, int lowBound, int highBound);//添加数组下界比上界大的错误信息
    void ReadError(int curLineNumber, const string& procedureId, int X, _Expression *exp);//添加read的实参错误信息
    void DivideZeroError(const string& operation, _Expression *exp);//添加除0错误信息
    void AssignLeftValueError(const string& preId, int preLineNumber);//左值错误
    void FunctionReturnMismatch(_Assign *assignStatement, const string& rightType);//函数返回值错误
    void IntDivisionError(_Expression *exp,string leftType,string rightType);//整除错误
    void ReturnExistedWarning(_Function *function);//函数不存在返回值 warning
    void MismatchWarning(_Expression *exp,string leftType,string rightType);//计算符号左右类型不一致 warning
};

class _Semantic{
public:
    _SemanticErrorProcessing Errors;
    _Program *ASTRoot;
public:
    _Semantic(_Program *ASTRoot){
        this->ASTRoot = ASTRoot;
    }
    void run();
    void Statement(_Statement *statement);//对语句进行语义分析
    void FunctionDefinition(_Function *functionDefinition);//对子程序定义进行语义分析
    void Variant(_Var *variant);//对变量定义进行语义分析
    void Const(_Const *constant);//对常量定义进行语义分析
    void ProgramBody(_ProgramBody *programBody);//对分程序进行语义分析
    void Program(_Program *program);//对程序进行语义分析
    void Parameter(_Parameter *Parameter);//对形式参数进行语义分析
    void Repeat(_Repeat *repeat);
    void While(_While *pWhile);
    void For(_For *pFor);
    void If(_If *pIf);
    void Assign(_Assign *assign);
    void Procedure(_Call *procedureCall);
    void Compound(_Compound *compound);
    string LeftReference(_Reference *variantReference);//对左值变量引用进行语义分析
    string RightReference(_Reference *variantReference);//对右值变量引用进行语义分析
    string ArrayVariantCheck(_Reference *variantReference, _SymRecord *record);//对数组变量引用进行语义分析
    string FunctionCall(_FunctionCall *functionCall);//对函数调用进行语义分析
    string Expression(_Expression *expression);//对表达式进行语义分析
};

//几个工具小函数
int getStatementType(_Statement *statement);
constexpr std::uint32_t hash_str_to_uint32(const char* data);
string integer2string(int num);//将int转化为string
string returnCalculateType(const string& x,const string& y);
string returnLogicType(const string& x,const string& y);
int calculateOP(int x, int y, const string& op);
bool typeChangable(const string& x, const string& y);

#endif //MAIN_CPP_SEMANTICANALYSE_H
