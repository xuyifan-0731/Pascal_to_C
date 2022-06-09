//  输出三者中最大数
program max(input,output);
var a,b:boolean;
c,d,e:integer;
begin
    read(c,d,e);
    a := c>=e;
    b:= d<=c;
    if a and b then write(c)
    else
    begin
        if ((d>c) and (e<d)) or (e=d) then write(d);      
        if (e>d) and (e<>c) then write(e);
    end;
end.