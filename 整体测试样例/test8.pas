//test8 语义错误
program test(input,output);
const n=10;
var a:integer;
    b:real;
    c:char;
    d:boolean;
    e:array[1..5] of integer;

function fun1:integer;
begin
    v:=a*2;//v未定义
    fun1:=v;
end;

function fun2:integer;
begin
    fun2:=e[6];//数组下标越界
end;

procedure pro1(a:integer;b:real);
var c:integer;
begin 
    for c:=b to 1 do a:=a+1 //循环判断变量初始值不为实数
end;

begin
    a:=1;
    n:=a;//常量赋值语句右值不为常量	
    c:=3;//变量赋值语句左右类型不匹配	
    b:=3.2;
    d:=b+a;       //算术运算左右类型不匹配
    d:= d and a;//逻辑运算左右类型不匹配 无
    d:=c <a;     //关系运算左右类型不匹配 无
    d:= not a;   //关系运算类型不匹配 无
    if a then a:=a+1;    //if条件表达式不为boolean
    a:=pro1(a,b);          //pro1为过程，没有返回值
    pro1(a);                  //pro1有两个参数
end.