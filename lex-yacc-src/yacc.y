%{
#include "main.h"
#include "yacc.tab.h"
extern "C"
{
	void yyerror(const char *s);
	int yyparse();
	extern int yylex();
}

void yyerror(const char *s, int line, int col);
void yyerror(const char *s, int startLine, int startCol, int endLine, int endCol);
string haveError(const char *s);

extern int yylineno;
extern char* yytext;
extern int yyleng;
extern int yycolumn;
extern string integer2string(int num);

bool haveSyntaxError=false;
Type* ParseTreeHead=NULL;
vector<string> syntaxErrorInfo;
%}

%token PROGRAM
%token CONST
%token VAR
%token ARRAY
%token OF
%token PROCEDURE
%token FUNCTION
%token _BEGIN
%token END
%token IF
%token THEN
%token FOR
%token TO
%token DO
%token ELSE
%token REPEAT
%token UNTIL
%token WHILE

%token IDENTIFIER
%token UINUM
%token UFNUM
%token CHAR
%token TYPE
%token ASSIGNOP
%token RELOP
%token ADDOP
%token MULOP
%token NOT
%token RANGEDOT

%start programstruct

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%%
programstruct: program_head ';' program_body '.'{
			   		$$=new Type;
			   		ParseTreeHead = $$;
			   		$$->token = "programstruct";
			   		$$->children.emplace_back($1);
			   		$$->children.emplace_back($2);
					$$->children.emplace_back($3);
					$$->children.emplace_back($4);
					YYACCEPT;
			   	}|program_head error program_body '.'{ //缺少分号
			   		$$=new Type;
			   		ParseTreeHead = $$;
			   		$$->token = "programstruct";
					yyerror("missing a semicolon here", @1.last_line, @1.last_column+1);
			   	}|program_head ';' program_body error{ //缺少点号
			   		$$=new Type;
                                        ParseTreeHead = $$;
			   		$$->token = "programstruct";
					yyerror("missing a dot here", @3.last_line, @3.last_column+1);
			   	}|error ';' program_body '.'{ //program_head识别失败
			   		$$=new Type;
                                        ParseTreeHead = $$;
			   		$$->token = "programstruct";
					yyerror("failed to get program head",@1.first_line, @1.first_column, @1.last_line, @1.last_column);
			   	};

program_head: 	PROGRAM IDENTIFIER '(' idlist ')'{
					$$=new Type;
					$$->token = "program_head";
					$$->children.emplace_back($1);
					$$->children.emplace_back($2);
					$$->children.emplace_back($3);
					$$->children.emplace_back($4);
					$$->children.emplace_back($5);
				}|PROGRAM error '(' idlist ')'{ //缺少主程序名
					$$=new Type;
					$$->token = "program_head";
					yyerror("missing program name here", @1.last_line, @1.last_column+1);
				}|PROGRAM IDENTIFIER error idlist ')'{ //缺少左括号
					$$=new Type;
					$$->token = "program_head";
					yyerror("missing a left bracket here", @4.first_line, @4.first_column-1);
				};

program_body: const_declarations var_declarations subprogram_declarations compound_statement{
					$$=new Type;
					$$->token = "program_body";
					$$->children.emplace_back($1);
					$$->children.emplace_back($2);
					$$->children.emplace_back($3);
					$$->children.emplace_back($4);
				};

idlist: IDENTIFIER{
			$$=new Type;
			$$->token = "idlist";
			$$->children.emplace_back($1);
		}|idlist ',' IDENTIFIER{
                  	$$=new Type;
                  	$$->token = "idlist";
                  	$$->children.emplace_back($1);
                  	$$->children.emplace_back($2);
                  	$$->children.emplace_back($3);
                  };

const_declarations: CONST const_declaration ';' {
						$$=new Type;
						$$->token = "const_declarations";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|{
						$$=new Type;
						$$->token = "const_declarations";
					};

const_declaration: IDENTIFIER '=' const_value{
                   				$$=new Type;
                   				$$->token = "const_declaration";
                   				$$->children.emplace_back($1); $$->children.emplace_back($2); $$->children.emplace_back($3);
                   			}|const_declaration ';' IDENTIFIER '=' const_value{
						$$=new Type;
						$$->token = "const_declaration";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
						$$->children.emplace_back($4);
						$$->children.emplace_back($5);
					}|const_declaration ';' IDENTIFIER '=' error{ //右值缺失
						$$=new Type;
						$$->token = "const_declaration";
						yyerror("constant definition missing initial r-value", @4.first_line, @4.first_column, @4.last_line, @4.last_column);
					}|IDENTIFIER '=' error{ //右值缺失
						$$=new Type;
						$$->token = "const_declaration";
						yyerror("constant definition missing initial r-value", @3.first_line, @3.first_column, @3.last_line, @3.last_column);
					};

const_value: '+' IDENTIFIER {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1);
					$$->children.emplace_back($2);
				}|'-' IDENTIFIER {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1);
					$$->children.emplace_back($2);
				}|IDENTIFIER {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1);
				}|'+' UINUM {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1);
					$$->children.emplace_back($2);
				}|'-' UINUM {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1); $$->children.emplace_back($2);
				}|UINUM {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1);
				}|'+' UFNUM {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1); $$->children.emplace_back($2);
				}|'-' UFNUM {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1); $$->children.emplace_back($2);
				}|UFNUM {
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1);
				}|CHAR{
					$$=new Type;
					$$->token = "const_value";
					$$->children.emplace_back($1);
				};

var_declarations: 	VAR var_declaration ';'{
						$$=new Type;
						$$->token = "var_declarations";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|{
						$$=new Type;
						$$->token = "var_declarations";
					}|VAR var_declaration error{ //缺少分号
						$$=new Type;
						$$->token = "var_declarations";
						yyerror("missing a semicolon here", @2.last_line, @2.last_column+1);
					}|error var_declaration ';'{ //缺少关键字VAR
                                                $$=new Type;
                                                $$->token = "const_value";
                                                yyerror("missing keyword \"VAR\" here", @1.last_line, @1.last_column+1);
                                        };

var_declaration: var_declaration ';' idlist ':' type {
						$$=new Type;
						$$->token = "var_declaration";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
						$$->children.emplace_back($4);
						$$->children.emplace_back($5);
					}|idlist ':' type {
						$$=new Type;
						$$->token ="var_declaration";
						$$->children.emplace_back($1);$$->children.emplace_back($2); $$->children.emplace_back($3);
					}|var_declaration ';' idlist error type { //缺少冒号
                                         	$$=new Type;
                                         	$$->token = "var_declaration";
                                         	yyerror("missing a colon here", @3.last_line, @3.last_column+1);
                                        }|var_declaration error idlist ':' type { //缺少分号
						$$=new Type;
						$$->token = "var_declaration";
						yyerror("missing a semicolon here", @1.last_line, @1.last_column+1);
					}|var_declaration ';' idlist ':' error { //type识别失败
						$$=new Type;
						$$->token = "var_declaration";
						yyerror("missing a type here", @4.last_line, @4.last_column+1);
					}|idlist ':' error {
						$$=new Type;
						$$->token ="var_declaration";
						yyerror("missing a type here", @3.last_line, @3.last_column+1);
					};

type: 	TYPE{
			$$=new Type;
			$$->token = "type";
			$$->children.emplace_back($1);
		}|ARRAY '[' period ']' OF TYPE{
			$$=new Type;
			$$->token = "type";
			$$->children.emplace_back($1);
			$$->children.emplace_back($2);
			$$->children.emplace_back($3);
			$$->children.emplace_back($4);
			$$->children.emplace_back($5);
			$$->children.emplace_back($6);
		}|ARRAY '[' period ']' error TYPE{ //缺少OF关键字
			$$=new Type;
			$$->token = "type";
			yyerror("missing keyword \"OF\" here", @4.last_line, @4.last_column+1, @6.first_line, @6.first_column-1);
		}|ARRAY '[' period ']' OF error{ //数组元素类型识别失败
			$$=new Type;
			$$->token = "type";
			yyerror("failed to get Array-type", @5.last_line, @5.last_column+1);
		};

period: period ',' UINUM RANGEDOT UINUM{
			$$=new Type;
			$$->token="period";
			$$->children.emplace_back($1);
			$$->children.emplace_back($2);
			$$->children.emplace_back($3);
			$$->children.emplace_back($4);
			$$->children.emplace_back($5);
		}|UINUM RANGEDOT UINUM{
                 	$$=new Type;
                 	$$->token="period";
                 	$$->children.emplace_back($1);
                 	$$->children.emplace_back($2);
                 	$$->children.emplace_back($3);
                }|period error UINUM RANGEDOT UINUM{ //缺少逗号
			$$=new Type;
			$$->token="period";
			yyerror("missing a comma here", @1.last_line, @1.last_column+1);
		}|period ',' UINUM error UINUM{ //缺少双点号
			$$=new Type;
			$$->token="period";
			yyerror("missing range dot .. here", @3.last_line, @3.last_column+1);
		};

subprogram_declarations: 	subprogram_declarations subprogram ';'{
								$$=new Type;
								$$->token="subprogram_declarations";
								$$->children.emplace_back($1);
								$$->children.emplace_back($2);
								$$->children.emplace_back($3);
							}|subprogram_declarations subprogram error{ //缺少分号
								$$=new Type;
								$$->token="subprogram_declarations";
								yyerror("missing a semicolon here", @2.last_line, @2.last_column+1);
							}|{
								$$=new Type;
								$$->token ="subprogram_declarations";
							};

subprogram: subprogram_head ';' subprogram_body{
				$$=new Type;
				$$->token="subprogram";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
			};

subprogram_head: 	PROCEDURE IDENTIFIER formal_parameter{
						$$=new Type;
						$$->token="subprogram_head";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|FUNCTION IDENTIFIER formal_parameter ':' TYPE{
						$$=new Type;
						$$->token="subprogram_head";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
						$$->children.emplace_back($4);
						$$->children.emplace_back($5);
					}|FUNCTION error formal_parameter ':' TYPE{ //函数名缺失
						$$=new Type;
						$$->token="subprogram_head";
						yyerror("missing function name", @1.last_line, @1.last_column+1);
					}|FUNCTION IDENTIFIER formal_parameter error TYPE{ //缺少冒号
						$$=new Type;
						$$->token="subprogram_head";
						yyerror("missing a colon here", @3.last_line, @3.last_column);
					}|FUNCTION IDENTIFIER formal_parameter ':' error{ //缺少基本类型关键字
						$$=new Type;
						$$->token="subprogram_head";
						yyerror("missing a base type keyword here", @4.last_line, @4.last_column+1);
					};

formal_parameter: 	'(' parameter_list ')'{
						$$=new Type;
						$$->token="formal_parameter";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|{
						$$=new Type;
						$$->token="formal_parameter";
					}|'(' error{ //不完整的形参列表
						$$=new Type;
						$$->token="formal_parameter";
						yyerror("incomplete formal parameter list", @2.last_line, @2.last_column+1);
					};

parameter_list: parameter_list ';' parameter{
					$$=new Type;
					$$->token="parameter_list";
					$$->children.emplace_back($1);$$->children.emplace_back($2);$$->children.emplace_back($3);
				}|parameter{
                                 	$$=new Type;
                                 	$$->token="parameter_list";
                                 	$$->children.emplace_back($1);
                                }|parameter_list error parameter{ //缺少分号
					$$=new Type;
					$$->token="parameter_list";
					yyerror("missing a semicolon here", @1.last_line, @1.last_column+1);
				};

parameter: 	var_parameter {
				$$=new Type;
				$$->token="parameter";
				$$->children.emplace_back($1);
			}|value_parameter{
				$$=new Type;
				$$->token="parameter";
				$$->children.emplace_back($1);
			};

var_parameter: 	VAR value_parameter{
					$$=new Type;
					$$->token="var_parameter";
					$$->children.emplace_back($1);$$->children.emplace_back($2);
				}|VAR error{ //不完整的引用参数列表
					$$=new Type;
					$$->token="var_parameter";
					yyerror("incomplete refereced parameter list", @2.last_line, @2.last_column+1);
				};

value_parameter: 	idlist ':' TYPE{
						$$=new Type;
						$$->token="value_parameter";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|idlist error TYPE{ //缺少分号
						$$=new Type;
						$$->token="value_parameter";
						yyerror("missing a colon here", @1.first_line, @1.last_column+1);
					};

subprogram_body: 	const_declarations var_declarations compound_statement{
						$$=new Type;
						$$->token="subprogram_body";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					};

compound_statement: _BEGIN statement_list END{
						$$=new Type;
						$$->token="compound_statement";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|_BEGIN statement_list error{ //缺少END关键字
						$$=new Type;
						$$->token="compound_statement";
						yyerror("missing keyword \"end\"", @2.last_line, @2.last_column+1);
					};

statement_list: statement_list ';' statement{
					$$=new Type;
					$$->token="statement_list";
					$$->children.emplace_back($1);
					$$->children.emplace_back($2);
					$$->children.emplace_back($3);
				}|statement{
                                 	$$=new Type;
                                 	$$->token="statement_list";
                                 	$$->children.emplace_back($1);
                                }|statement_list error statement{ //缺失分号 这里引发了3个规约规约冲突
					$$=new Type;
					$$->token="statement_list";
					yyerror("missing a semicolon here", @1.last_line, @1.last_column+1);
				};

statement: variable ASSIGNOP expression{
				$$=new Type;
				$$->token="statement";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
			}|compound_statement{
                         	$$=new Type;
                         	$$->token="statement";
                         	$$->children.emplace_back($1);
                        }|IF expression THEN statement else_part{
                         	$$=new Type;
                         	$$->token="statement";
                         	$$->children.emplace_back($1);
                         	$$->children.emplace_back($2);
                         	$$->children.emplace_back($3);
                         	$$->children.emplace_back($4);
                         	$$->children.emplace_back($5);
                        }|{
                         	$$=new Type;
                         	$$->token="statement";
                        }|procedure_call{
				$$=new Type;
				$$->token="statement";
				$$->children.emplace_back($1);
			}|FOR IDENTIFIER ASSIGNOP expression TO expression DO statement{
				$$=new Type;
				$$->token="statement";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
				$$->children.emplace_back($4);
				$$->children.emplace_back($5);
				$$->children.emplace_back($6);
				$$->children.emplace_back($7);
				$$->children.emplace_back($8);
			}|WHILE expression DO statement{
				$$=new Type;
				$$->token="statement";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
				$$->children.emplace_back($4);
			}|REPEAT statement UNTIL expression{
				$$=new Type;
				$$->token="statement";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
				$$->children.emplace_back($4);
			}|FOR IDENTIFIER error expression TO expression DO statement{ //缺少赋值号
                         	$$=new Type;
                         	$$->token="statement";
                         	yyerror("missing assignop \":=\"", @2.last_line, @2.last_column+1);
                        }|IF expression error statement else_part{ //缺少then关键字
                         	$$=new Type;
                         	$$->token="statement";
                         	yyerror("missing keyword \"then\"", @2.last_line, @2.last_column+1);
                        }|REPEAT statement error expression{ //缺少关键字until
				$$=new Type;
				$$->token="statement";
				yyerror("missing keywrod \"until\"", @4.first_line, @4.first_column);
			};

else_part: 	ELSE statement{
				$$=new Type;
				$$->token="else_part";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
			}|%prec LOWER_THAN_ELSE{
				$$=new Type;
				$$->token="else_part";
			};

variable: 	IDENTIFIER id_varpart{
				$$=new Type;
				$$->token="variable";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
			};

id_varpart: '[' expression_list ']'{
				$$=new Type;
				$$->token="id_varpart";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
			}|{
				$$=new Type;
				$$->token="id_varpart";
			}|'[' error{ //不完整的数组下标列表
                         	$$=new Type;
                         	$$->token="id_varpart";
                         	yyerror("incomplete expression list of array subindex",  @2.last_line, @2.last_column+1);
                        };

procedure_call: IDENTIFIER{
				$$=new Type;
				$$->token="procedure_call";
				$$->children.emplace_back($1);
			}|IDENTIFIER '(' expression_list ')'{
				$$=new Type;
				$$->token="procedure_call";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
				$$->children.emplace_back($4);
			}|IDENTIFIER '(' expression_list error{ //缺少右括号
				$$=new Type;
				$$->token="procedure_call";
				yyerror("missing a right bracket here", @3.last_line, @3.last_column+1);
			};

expression_list: 	expression_list ',' expression{
						$$=new Type;
						$$->token="expression_list";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|expression{
						$$=new Type;
						$$->token="expression_list";
						$$->children.emplace_back($1);
					}|expression_list error expression{ //缺少逗号 这里引发了一个移进规约冲突
						$$=new Type;
						$$->token="expression_list";
						yyerror("missing a comma here", @1.last_line, @1.last_column+1);
					};

expression: simple_expression RELOP simple_expression{
				$$=new Type;
				$$->token="expression";
				$$->children.emplace_back($1);
				$$->children.emplace_back($2);
				$$->children.emplace_back($3);
			}|simple_expression '=' simple_expression{
				$$=new Type;
				$$->token="expression";
				$$->children.emplace_back($1);$$->children.emplace_back($2);$$->children.emplace_back($3);
			}|simple_expression{
				$$=new Type;
				$$->token="expression";
				$$->children.emplace_back($1);
			};

simple_expression: 	simple_expression ADDOP term{
						$$=new Type;
						$$->token="simple_expression";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);
						$$->children.emplace_back($3);
					}|simple_expression ADDOP error term %prec ADD{//error，缺少操作数
						$$=new Type;
						$$->token="simple_expression";
						yyerror("missing operand",@2.last_line, @2.last_column+1);
					}|simple_expression '-' term{
						$$=new Type;
						$$->token="simple_expression";
						$$->children.emplace_back($1);
						$$->children.emplace_back($2);$$->children.emplace_back($3);
					}|simple_expression '-' error term %prec ADD{//error，缺少操作数
						$$=new Type;
						$$->token="simple_expression";
						yyerror("missing operand",@2.last_line, @2.last_column+1);
					}|term{
						$$=new Type;
						$$->token="simple_expression";
						$$->children.emplace_back($1);
					};

term: 	term MULOP factor{
			$$=new Type;
			$$->token="term";
			$$->children.emplace_back($1);
			$$->children.emplace_back($2);
			$$->children.emplace_back($3);
		}|term error factor{ //操作符缺失
                        $$=new Type;
                        $$->token="term";
                        yyerror("missing operator here",@2.last_line, @2.last_column+1);
		}|term MULOP error factor %prec MUL{ //缺少操作数
			$$=new Type;
			$$->token="term";
			yyerror("missing operand",@2.last_line, @2.last_column+1);
		}|factor{
			$$=new Type;
			$$->token="term";
			$$->children.emplace_back($1);
		};

factor: UINUM{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
		}|UFNUM{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
		}|variable{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
		}|IDENTIFIER '(' expression_list ')'{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
			$$->children.emplace_back($2);
			$$->children.emplace_back($3);
			$$->children.emplace_back($4);
		}|'(' expression ')'{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
			$$->children.emplace_back($2);
			$$->children.emplace_back($3);
		}|'(' expression error{ //缺少右括号
			$$=new Type;
			$$->token="factor";
			yyerror("missing a r-bracket here", @2.last_line, @2.last_column+1);
		}|NOT factor{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
			$$->children.emplace_back($2);
		}|'-' factor{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
			$$->children.emplace_back($2);
		}|CHAR{
			$$=new Type;
			$$->token="factor";
			$$->children.emplace_back($1);
		}|IDENTIFIER '(' expression_list error{ //缺少右括号 这里引发了一个移进规约冲突
                 	$$=new Type;
                 	$$->token="factor";
                 	yyerror("missing a r-bracket here", @3.last_line, @3.last_column+1);
                }|IDENTIFIER '(' error{ //函数调用列表缺失
                 	$$=new Type;
                 	$$->token="factor";
                 	yyerror("incomplete formal parameter list", @2.last_line, @2.last_column+1);
                };

%%

string haveError(const char *s){
	haveSyntaxError = true;
	return string(s);
}

void yyerror(const char *s){
	string errorInfo = haveError(s);
	errorInfo = errorInfo + ", location: " + integer2string(yylineno) + ":" + integer2string(yycolumn-yyleng);
	syntaxErrorInfo.emplace_back(errorInfo);
}

void yyerror(const char *s, int line, int col){//处理一行以内的错误
	string errorInfo = haveError(s);
	errorInfo = "syntax error, " + errorInfo + ", location: " + integer2string(line) + ":" + integer2string(col);
	syntaxErrorInfo.emplace_back(errorInfo);
}

void yyerror(const char *s, int startLine, int startCol, int endLine, int endCol){//处理涉及多行的错误
	string errorInfo = haveError(s);
	errorInfo = "syntax error, " + errorInfo + ", location: " + integer2string(startLine) + ":" + integer2string(startCol) + "-" + integer2string(endLine) + ":" + integer2string(endCol);
	syntaxErrorInfo.emplace_back(errorInfo);
}
