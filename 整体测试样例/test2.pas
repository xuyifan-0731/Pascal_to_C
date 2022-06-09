// 把1到n中，所有数的约数数量相加。
program test(input,output);
var n,i,t:integer;
begin
    read(n);
    t:=0;
    for i:=1 to n do
    t:=t+(n div i);
    write(t);
end.