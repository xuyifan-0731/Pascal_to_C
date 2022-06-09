//二元计算器
program test(input,output);
var a,b,c:integer;
op:char;
begin
    write('o','p','=');
    read(op);
    write('a','=');
    read(a);
    write('b','=');
    read(b);
    if op='+' then write(a+b);
    if op='-' then write(a - b);
    if op='*' then write(a * b);
    if (op='/')  or (op='%') or (op='|') then
    begin
        if  (b=0) then write('e','r','r','o','r')
        else
        begin
            if (op='/') then write(a / b);
            if (op='%') then write(a mod b);
        end;
        if (op='|') and not(b=0) then write(a div b);
    end;
end.