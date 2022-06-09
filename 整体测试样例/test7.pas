// 词法+语法错误 2
program test(input,output);
var a,b,c:integer;

function func(var);//参数列表错误：不完整的形参列表,函数定义错误：缺失返回
begin
    while a=1  //while语句结构错误，缺失do
        b:=2;
end;


procedure pro(var a:integer b:real);   //参数列表错误：缺少分号
begin
    if a=1  //if语句结构错误：缺失then
       b:=2
end;

begin
    pro(a,b;  //过程调用语句错误，缺失右括号
    c:=a-+b;  //表达式错误：缺少操作数
    repeat a:=1;  //repeat结构错误：缺失until
end.