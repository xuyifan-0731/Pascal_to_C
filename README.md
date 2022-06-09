# Pascal_to_C
Pascal-S语言编译为C语言的程序的设计与实现。  
按照所给出的Pascal-S语言文法，设计将其编译为C语言的程序。  


lex-yacc-src：  
lex.l:lex生成源文件  
yacc.y:yacc生成源文件  

src:  
main.h,main.cpp:主程序  
lex.yy.cpp:lex执行文件  
yacc.tab.h,yacc.tab.cpp:yacc执行文件  
syntaxAnalyse.h,syntaxAnalyse.cpp:语法分析（yacc以外部分）执行文件  
semanticAnalyse.h，semanticAnalyse.cpp:语义分析执行文件  
codeGeneration.h,codeGeneration.cpp:代码生成执行文件 

运行环境  
1.词法分析器：flex  
2.语法分析器：bison  
3.整体工程语言：C++14  
4.整体工程运行环境：windows Clion2022.1  
 

1.确保自己的电脑上安装有gcc  
2.使用clion打开code/src/main.cpp，或者其他具有c++14以上环境的ide打开  
3.如果使用clion打开，请将需要执行的代码（命名为PascalProgram.pas，或者在代码中修改相应命名）移到cmake-build-debug中  
4.运行程序，输出代码在test.c中  