
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 1



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "yacc.y"

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


/* Line 189 of yacc.c  */
#line 99 "yacc.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     PROGRAM = 258,
     CONST = 259,
     VAR = 260,
     ARRAY = 261,
     OF = 262,
     PROCEDURE = 263,
     FUNCTION = 264,
     _BEGIN = 265,
     END = 266,
     IF = 267,
     THEN = 268,
     FOR = 269,
     TO = 270,
     DO = 271,
     ELSE = 272,
     REPEAT = 273,
     UNTIL = 274,
     WHILE = 275,
     IDENTIFIER = 276,
     UINUM = 277,
     UFNUM = 278,
     CHAR = 279,
     TYPE = 280,
     ASSIGNOP = 281,
     RELOP = 282,
     ADDOP = 283,
     MULOP = 284,
     NOT = 285,
     RANGEDOT = 286,
     LOWER_THAN_ELSE = 287,
     ADD = 288,
     MUL = 289
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
} YYLTYPE;
# define yyltype YYLTYPE /* obsolescent; will be withdrawn */
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 188 "yacc.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
	     && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   380

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  118
/* YYNRULES -- Number of states.  */
#define YYNSTATES  245

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   289

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      35,    36,     2,    39,    37,    40,    34,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,    33,
       2,    38,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    42,     2,    43,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    44,    45
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     8,    13,    18,    23,    29,    35,    41,
      46,    48,    52,    56,    57,    61,    67,    73,    77,    80,
      83,    85,    88,    91,    93,    96,    99,   101,   103,   107,
     108,   112,   116,   122,   126,   132,   138,   144,   148,   150,
     157,   164,   171,   177,   181,   187,   193,   197,   201,   202,
     206,   210,   216,   222,   228,   234,   238,   239,   242,   246,
     248,   252,   254,   256,   259,   262,   266,   270,   274,   278,
     282,   286,   288,   292,   296,   298,   304,   305,   307,   316,
     321,   326,   335,   341,   346,   349,   350,   353,   357,   358,
     361,   363,   368,   373,   377,   379,   383,   387,   391,   393,
     397,   402,   406,   411,   413,   417,   421,   426,   428,   430,
     432,   434,   439,   443,   447,   450,   453,   455,   460
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      47,     0,    -1,    48,    33,    49,    34,    -1,    48,     1,
      49,    34,    -1,    48,    33,    49,     1,    -1,     1,    33,
      49,    34,    -1,     3,    21,    35,    50,    36,    -1,     3,
       1,    35,    50,    36,    -1,     3,    21,     1,    50,    36,
      -1,    51,    54,    58,    67,    -1,    21,    -1,    50,    37,
      21,    -1,     4,    52,    33,    -1,    -1,    21,    38,    53,
      -1,    52,    33,    21,    38,    53,    -1,    52,    33,    21,
      38,     1,    -1,    21,    38,     1,    -1,    39,    21,    -1,
      40,    21,    -1,    21,    -1,    39,    22,    -1,    40,    22,
      -1,    22,    -1,    39,    23,    -1,    40,    23,    -1,    23,
      -1,    24,    -1,     5,    55,    33,    -1,    -1,     5,    55,
       1,    -1,     1,    55,    33,    -1,    55,    33,    50,    41,
      56,    -1,    50,    41,    56,    -1,    55,    33,    50,     1,
      56,    -1,    55,     1,    50,    41,    56,    -1,    55,    33,
      50,    41,     1,    -1,    50,    41,     1,    -1,    25,    -1,
       6,    42,    57,    43,     7,    25,    -1,     6,    42,    57,
      43,     1,    25,    -1,     6,    42,    57,    43,     7,     1,
      -1,    57,    37,    22,    31,    22,    -1,    22,    31,    22,
      -1,    57,     1,    22,    31,    22,    -1,    57,    37,    22,
       1,    22,    -1,    58,    59,    33,    -1,    58,    59,     1,
      -1,    -1,    60,    33,    66,    -1,     8,    21,    61,    -1,
       9,    21,    61,    41,    25,    -1,     9,     1,    61,    41,
      25,    -1,     9,    21,    61,     1,    25,    -1,     9,    21,
      61,    41,     1,    -1,    35,    62,    36,    -1,    -1,    35,
       1,    -1,    62,    33,    63,    -1,    63,    -1,    62,     1,
      63,    -1,    64,    -1,    65,    -1,     5,    65,    -1,     5,
       1,    -1,    50,    41,    25,    -1,    50,     1,    25,    -1,
      51,    54,    67,    -1,    10,    68,    11,    -1,    10,    68,
       1,    -1,    68,    33,    69,    -1,    69,    -1,    68,     1,
      69,    -1,    71,    26,    75,    -1,    67,    -1,    12,    75,
      13,    69,    70,    -1,    -1,    73,    -1,    14,    21,    26,
      75,    15,    75,    16,    69,    -1,    20,    75,    16,    69,
      -1,    18,    69,    19,    75,    -1,    14,    21,     1,    75,
      15,    75,    16,    69,    -1,    12,    75,     1,    69,    70,
      -1,    18,    69,     1,    75,    -1,    17,    69,    -1,    -1,
      21,    72,    -1,    42,    74,    43,    -1,    -1,    42,     1,
      -1,    21,    -1,    21,    35,    74,    36,    -1,    21,    35,
      74,     1,    -1,    74,    37,    75,    -1,    75,    -1,    74,
       1,    75,    -1,    76,    27,    76,    -1,    76,    38,    76,
      -1,    76,    -1,    76,    28,    77,    -1,    76,    28,     1,
      77,    -1,    76,    40,    77,    -1,    76,    40,     1,    77,
      -1,    77,    -1,    77,    29,    78,    -1,    77,     1,    78,
      -1,    77,    29,     1,    78,    -1,    78,    -1,    22,    -1,
      23,    -1,    71,    -1,    21,    35,    74,    36,    -1,    35,
      75,    36,    -1,    35,    75,     1,    -1,    30,    78,    -1,
      40,    78,    -1,    24,    -1,    21,    35,    74,     1,    -1,
      21,    35,     1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    63,    63,    72,    77,    82,    89,    97,   101,   107,
     116,   120,   128,   134,   139,   143,   151,   155,   161,   166,
     171,   175,   180,   184,   188,   192,   196,   200,   206,   212,
     215,   219,   225,   233,   237,   241,   245,   249,   255,   259,
     268,   272,   278,   286,   292,   296,   302,   308,   312,   317,
     325,   331,   339,   343,   347,   353,   359,   362,   368,   372,
     376,   382,   386,   392,   396,   402,   408,   414,   422,   428,
     434,   440,   444,   450,   456,   460,   468,   471,   475,   486,
     493,   500,   504,   508,   514,   519,   524,   531,   537,   540,
     546,   550,   557,   563,   569,   573,   579,   585,   589,   595,
     601,   605,   610,   614,   620,   626,   630,   634,   640,   644,
     648,   652,   659,   665,   669,   674,   679,   683,   687
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "PROGRAM", "CONST", "VAR", "ARRAY", "OF",
  "PROCEDURE", "FUNCTION", "_BEGIN", "END", "IF", "THEN", "FOR", "TO",
  "DO", "ELSE", "REPEAT", "UNTIL", "WHILE", "IDENTIFIER", "UINUM", "UFNUM",
  "CHAR", "TYPE", "ASSIGNOP", "RELOP", "ADDOP", "MULOP", "NOT", "RANGEDOT",
  "LOWER_THAN_ELSE", "';'", "'.'", "'('", "')'", "','", "'='", "'+'",
  "'-'", "':'", "'['", "']'", "ADD", "MUL", "$accept", "programstruct",
  "program_head", "program_body", "idlist", "const_declarations",
  "const_declaration", "const_value", "var_declarations",
  "var_declaration", "type", "period", "subprogram_declarations",
  "subprogram", "subprogram_head", "formal_parameter", "parameter_list",
  "parameter", "var_parameter", "value_parameter", "subprogram_body",
  "compound_statement", "statement_list", "statement", "else_part",
  "variable", "id_varpart", "procedure_call", "expression_list",
  "expression", "simple_expression", "term", "factor", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,    59,    46,    40,    41,    44,    61,    43,
      45,    58,    91,    93,   288,   289
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    46,    47,    47,    47,    47,    48,    48,    48,    49,
      50,    50,    51,    51,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    54,    54,
      54,    54,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    56,    57,    57,    57,    57,    58,    58,    58,    59,
      60,    60,    60,    60,    60,    61,    61,    61,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    68,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    71,    72,    72,    72,
      73,    73,    73,    74,    74,    74,    75,    75,    75,    76,
      76,    76,    76,    76,    77,    77,    77,    77,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     4,     4,     4,     4,     5,     5,     5,     4,
       1,     3,     3,     0,     3,     5,     5,     3,     2,     2,
       1,     2,     2,     1,     2,     2,     1,     1,     3,     0,
       3,     3,     5,     3,     5,     5,     5,     3,     1,     6,
       6,     6,     5,     3,     5,     5,     3,     3,     0,     3,
       3,     5,     5,     5,     5,     3,     0,     2,     3,     1,
       3,     1,     1,     2,     2,     3,     3,     3,     3,     3,
       3,     1,     3,     3,     1,     5,     0,     1,     8,     4,
       4,     8,     5,     4,     2,     0,     2,     3,     0,     2,
       1,     4,     4,     3,     1,     3,     3,     3,     1,     3,
       4,     3,     4,     1,     3,     3,     4,     1,     1,     1,
       1,     4,     3,     3,     2,     2,     1,     4,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,    13,     0,     0,     1,    13,
      13,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     0,     0,    48,    10,     0,     0,     0,     3,
       4,     2,     0,    12,     0,     0,     0,     0,     7,     0,
       8,     6,    17,    20,    23,    26,    27,     0,     0,    14,
       0,     0,     0,    31,    30,    28,     0,     0,    76,     0,
       0,     9,    11,    18,    21,    24,    19,    22,    25,     0,
      37,     0,    38,    33,     0,     0,    56,    56,    56,     0,
       0,    76,     0,    90,    74,     0,    71,     0,    77,    47,
      46,    13,    16,    15,     0,     0,     0,     0,     0,    50,
       0,     0,    88,   108,   109,   116,     0,     0,     0,   110,
       0,    98,     0,   107,     0,     0,     0,     0,     0,    86,
      69,    68,    76,     0,     0,    49,     0,     0,    35,    34,
      36,    32,    57,     0,     0,     0,    59,    61,    62,     0,
       0,     0,     0,   114,     0,   115,    76,    76,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,     0,
      94,    89,     0,    72,    70,    73,     0,     0,     0,     0,
       0,    64,    63,     0,     0,     0,     0,    55,    52,    53,
      54,    51,   118,     0,   113,   112,    85,    85,    96,     0,
       0,    97,     0,     0,   105,     0,   104,     0,     0,    83,
      80,    79,    92,    91,     0,     0,    87,    67,    43,     0,
       0,     0,     0,    66,    65,    60,    58,   117,   111,    76,
      82,    75,     0,     0,   106,     0,     0,    95,    93,     0,
       0,     0,    40,    41,    39,    84,     0,     0,    44,    45,
      42,    76,    76,    81,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,    12,   134,    13,    20,    49,    24,    35,
      73,   127,    37,    59,    60,    99,   135,   136,   137,   138,
     125,    84,    85,    86,   220,   109,   119,    88,   159,   160,
     111,   112,   113
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -138
static const yytype_int16 yypact[] =
{
     175,    -8,   104,    22,    30,    24,    -1,    23,  -138,    24,
      24,    55,    50,   228,    99,    99,    99,   105,    31,   112,
     109,  -138,    99,    99,  -138,  -138,   168,   182,   209,  -138,
    -138,  -138,   134,   132,   138,    39,    45,   231,  -138,   173,
    -138,  -138,  -138,  -138,  -138,  -138,  -138,   273,   280,  -138,
     170,    98,    99,    99,    99,    99,   214,   116,   359,   101,
     221,  -138,  -138,  -138,  -138,  -138,  -138,  -138,  -138,   324,
    -138,   218,  -138,  -138,   151,    20,   229,   229,   229,   335,
     235,   359,   335,   172,  -138,   115,  -138,   243,  -138,  -138,
    -138,    24,  -138,  -138,   244,    13,    13,   135,   166,  -138,
     247,    15,   167,  -138,  -138,  -138,   335,   335,   335,  -138,
      14,   240,    58,  -138,     9,   158,   265,   335,    89,  -138,
     359,  -138,   359,   335,   205,  -138,   256,    10,  -138,  -138,
    -138,  -138,  -138,   117,    29,     6,  -138,  -138,  -138,   272,
     285,    96,   269,  -138,    12,  -138,   359,   359,   335,   284,
     335,   299,   335,   314,   335,   335,   335,   335,   359,     0,
    -138,  -138,    17,  -138,  -138,  -138,   288,   294,   295,   296,
      19,  -138,  -138,   301,   302,   144,   144,  -138,  -138,  -138,
    -138,  -138,  -138,     8,  -138,  -138,   311,   311,   -11,   335,
     153,   -11,   335,   184,  -138,   335,  -138,   315,   316,  -138,
    -138,  -138,   335,  -138,   335,   335,  -138,  -138,  -138,   309,
      91,   307,   102,  -138,  -138,  -138,  -138,   335,  -138,   359,
    -138,  -138,   215,   246,  -138,   335,   335,  -138,  -138,   319,
     320,   321,  -138,  -138,  -138,  -138,   317,   334,  -138,  -138,
    -138,   359,   359,  -138,  -138
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -138,  -138,  -138,   262,    92,   260,  -138,   283,   236,   330,
     216,  -138,  -138,  -138,  -138,   199,  -138,    74,  -138,   222,
    -138,   -34,  -138,   -79,   174,   -58,  -138,  -138,    -9,   -74,
      75,  -137,  -102
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -104
static const yytype_int16 yytable[] =
{
      87,   202,   115,    61,   143,   110,   145,   175,   116,   217,
     154,   168,   190,   184,   193,   146,   140,   149,   205,    71,
     211,    96,     8,    87,    15,     5,   212,   147,    11,   151,
     173,     9,    30,   144,    14,   155,   203,   204,    72,   176,
      52,   163,   177,   164,   218,   204,    54,   169,   185,   165,
     194,   196,   222,   170,   204,   223,   141,    39,    16,   152,
     206,    97,    87,    10,    87,    31,    39,   186,   187,  -103,
     174,  -103,    53,  -103,  -103,  -103,    19,  -103,    55,   201,
     197,   198,   199,   200,    21,  -103,  -103,   153,    87,    87,
     161,  -103,   230,   224,  -103,  -103,  -103,   180,  -103,    70,
      87,  -103,    89,   233,    71,     6,    26,    27,    28,   162,
     102,   103,   104,   105,    34,    34,   120,    77,   171,   106,
      25,   181,   231,    72,   107,     7,   121,   234,   227,   108,
     228,   227,   207,   183,    90,    42,   130,    78,    25,    29,
     235,    71,    33,   227,    74,    75,    74,    75,   122,   133,
      32,   236,   237,    50,   152,    43,    44,    45,    46,   156,
      72,    87,   243,   244,   -99,    25,   -99,   132,   -99,   -99,
     -99,   133,   -99,    47,    48,    39,     1,   157,     2,    51,
     -99,   -99,   153,    87,    87,   152,   -99,    25,    39,   -99,
     -99,   -99,    95,   -99,    62,  -101,   -99,  -101,   -88,  -101,
    -101,  -101,   142,  -101,    38,    39,    22,   117,    69,   118,
      23,  -101,  -101,   153,   118,   -29,   152,  -101,    40,    39,
    -101,  -101,  -101,   188,  -101,   191,  -100,  -101,  -100,    22,
    -100,  -100,  -100,    23,  -100,    76,   -29,   -29,   -29,    56,
      57,    58,  -100,  -100,   153,    41,    39,   152,  -100,   215,
     216,  -100,  -100,  -100,    91,  -100,   114,  -102,  -100,  -102,
      94,  -102,  -102,  -102,    98,  -102,   126,   148,   149,   123,
     182,    17,    18,  -102,  -102,   153,   100,   101,   150,  -102,
     151,   158,  -102,  -102,  -102,   189,  -102,   167,   139,  -102,
     102,   103,   104,   105,    63,    64,    65,   178,    58,   106,
     192,    66,    67,    68,   107,   102,   103,   104,   105,   108,
     179,   128,   129,   131,   106,   195,   208,   209,   210,   107,
     102,   103,   104,   105,   108,    92,   213,   214,   219,   106,
     225,   226,   232,   241,   107,   102,   103,   104,   105,   108,
     229,   238,   239,   240,   106,    43,    44,    45,    46,   107,
     242,   124,    93,    36,   108,   172,   102,   103,   104,   105,
     166,   221,     0,    47,    48,   106,     0,     0,     0,    58,
     107,    79,     0,    80,     0,   108,     0,    81,     0,    82,
      83
};

static const yytype_int16 yycheck[] =
{
      58,     1,    81,    37,   106,    79,   108,     1,    82,     1,
       1,     1,   149,     1,   151,     1,     1,    28,     1,     6,
       1,     1,     0,    81,     1,    33,     7,    13,     4,    40,
       1,     1,     1,   107,    35,    26,    36,    37,    25,    33,
       1,   120,    36,   122,    36,    37,     1,    37,    36,   123,
     152,   153,   189,    43,    37,   192,    41,    37,    35,     1,
      43,    41,   120,    33,   122,    34,    37,   146,   147,    11,
      41,    13,    33,    15,    16,    17,    21,    19,    33,   158,
     154,   155,   156,   157,    34,    27,    28,    29,   146,   147,
       1,    33,     1,   195,    36,    37,    38,     1,    40,     1,
     158,    43,     1,     1,     6,     1,    14,    15,    16,   118,
      21,    22,    23,    24,    22,    23,     1,     1,     1,    30,
      21,    25,    31,    25,    35,    21,    11,    25,   202,    40,
     204,   205,   166,   142,    33,     1,     1,    21,    21,    34,
     219,     6,    33,   217,    52,    53,    54,    55,    33,     5,
      38,   225,   226,    21,     1,    21,    22,    23,    24,     1,
      25,   219,   241,   242,    11,    21,    13,     1,    15,    16,
      17,     5,    19,    39,    40,    37,     1,    19,     3,    41,
      27,    28,    29,   241,   242,     1,    33,    21,    37,    36,
      37,    38,    41,    40,    21,    11,    43,    13,    26,    15,
      16,    17,    35,    19,    36,    37,     1,    35,    38,    42,
       5,    27,    28,    29,    42,    10,     1,    33,    36,    37,
      36,    37,    38,   148,    40,   150,    11,    43,    13,     1,
      15,    16,    17,     5,    19,    21,     8,     9,    10,     8,
       9,    10,    27,    28,    29,    36,    37,     1,    33,   175,
     176,    36,    37,    38,    33,    40,    21,    11,    43,    13,
      42,    15,    16,    17,    35,    19,    22,    27,    28,    26,
       1,     9,    10,    27,    28,    29,    77,    78,    38,    33,
      40,    16,    36,    37,    38,     1,    40,    31,    41,    43,
      21,    22,    23,    24,    21,    22,    23,    25,    10,    30,
       1,    21,    22,    23,    35,    21,    22,    23,    24,    40,
      25,    95,    96,    97,    30,     1,    22,    22,    22,    35,
      21,    22,    23,    24,    40,     1,    25,    25,    17,    30,
      15,    15,    25,    16,    35,    21,    22,    23,    24,    40,
      31,    22,    22,    22,    30,    21,    22,    23,    24,    35,
      16,    91,    69,    23,    40,   133,    21,    22,    23,    24,
     124,   187,    -1,    39,    40,    30,    -1,    -1,    -1,    10,
      35,    12,    -1,    14,    -1,    40,    -1,    18,    -1,    20,
      21
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,    47,    48,    33,     1,    21,     0,     1,
      33,     4,    49,    51,    35,     1,    35,    49,    49,    21,
      52,    34,     1,     5,    54,    21,    50,    50,    50,    34,
       1,    34,    38,    33,    50,    55,    55,    58,    36,    37,
      36,    36,     1,    21,    22,    23,    24,    39,    40,    53,
      21,    41,     1,    33,     1,    33,     8,     9,    10,    59,
      60,    67,    21,    21,    22,    23,    21,    22,    23,    38,
       1,     6,    25,    56,    50,    50,    21,     1,    21,    12,
      14,    18,    20,    21,    67,    68,    69,    71,    73,     1,
      33,    33,     1,    53,    42,    41,     1,    41,    35,    61,
      61,    61,    21,    22,    23,    24,    30,    35,    40,    71,
      75,    76,    77,    78,    21,    69,    75,    35,    42,    72,
       1,    11,    33,    26,    51,    66,    22,    57,    56,    56,
       1,    56,     1,     5,    50,    62,    63,    64,    65,    41,
       1,    41,    35,    78,    75,    78,     1,    13,    27,    28,
      38,    40,     1,    29,     1,    26,     1,    19,    16,    74,
      75,     1,    74,    69,    69,    75,    54,    31,     1,    37,
      43,     1,    65,     1,    41,     1,    33,    36,    25,    25,
       1,    25,     1,    74,     1,    36,    69,    69,    76,     1,
      77,    76,     1,    77,    78,     1,    78,    75,    75,    75,
      75,    69,     1,    36,    37,     1,    43,    67,    22,    22,
      22,     1,     7,    25,    25,    63,    63,     1,    36,    17,
      70,    70,    77,    77,    78,    15,    15,    75,    75,    31,
       1,    31,    25,     1,    25,    69,    75,    75,    22,    22,
      22,    16,    16,    69,    69
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (yylocationp);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, yylocationp)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    YYLTYPE const * const yylocationp;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yylsp, yyrule)
    YYSTYPE *yyvsp;
    YYLTYPE *yylsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       , &(yylsp[(yyi + 1) - (yynrhs)])		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, yylsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, yylocationp)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    YYLTYPE *yylocationp;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Location data for the lookahead symbol.  */
YYLTYPE yylloc;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.
       `yyls': related to locations.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[2];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;
  yylsp = yyls;

#if YYLTYPE_IS_TRIVIAL
  /* Initialize the default location before parsing starts.  */
  yylloc.first_line   = yylloc.last_line   = 1;
  yylloc.first_column = yylloc.last_column = 1;
#endif

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;
	YYLTYPE *yyls1 = yyls;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yyls1, yysize * sizeof (*yylsp),
		    &yystacksize);

	yyls = yyls1;
	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
	YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;
  *++yylsp = yylloc;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1455 of yacc.c  */
#line 63 "yacc.y"
    {
			   		(yyval)=new Type;
			   		ParseTreeHead = (yyval);
			   		(yyval)->token = "programstruct";
			   		(yyval)->children.emplace_back((yyvsp[(1) - (4)]));
			   		(yyval)->children.emplace_back((yyvsp[(2) - (4)]));
					(yyval)->children.emplace_back((yyvsp[(3) - (4)]));
					(yyval)->children.emplace_back((yyvsp[(4) - (4)]));
					YYACCEPT;
			   	;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 72 "yacc.y"
    { //缺少分号
			   		(yyval)=new Type;
			   		ParseTreeHead = (yyval);
			   		(yyval)->token = "programstruct";
					yyerror("missing a semicolon here", (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).last_column+1);
			   	;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 77 "yacc.y"
    { //缺少点号
			   		(yyval)=new Type;
                                        ParseTreeHead = (yyval);
			   		(yyval)->token = "programstruct";
					yyerror("missing a dot here", (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column+1);
			   	;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 82 "yacc.y"
    { //program_head识别失败
			   		(yyval)=new Type;
                                        ParseTreeHead = (yyval);
			   		(yyval)->token = "programstruct";
					yyerror("failed to get program head",(yylsp[(1) - (4)]).first_line, (yylsp[(1) - (4)]).first_column, (yylsp[(1) - (4)]).last_line, (yylsp[(1) - (4)]).last_column);
			   	;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 89 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "program_head";
					(yyval)->children.emplace_back((yyvsp[(1) - (5)]));
					(yyval)->children.emplace_back((yyvsp[(2) - (5)]));
					(yyval)->children.emplace_back((yyvsp[(3) - (5)]));
					(yyval)->children.emplace_back((yyvsp[(4) - (5)]));
					(yyval)->children.emplace_back((yyvsp[(5) - (5)]));
				;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 97 "yacc.y"
    { //缺少主程序名
					(yyval)=new Type;
					(yyval)->token = "program_head";
					yyerror("missing program name here", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
				;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 101 "yacc.y"
    { //缺少左括号
					(yyval)=new Type;
					(yyval)->token = "program_head";
					yyerror("missing a left bracket here", (yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column-1);
				;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 107 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "program_body";
					(yyval)->children.emplace_back((yyvsp[(1) - (4)]));
					(yyval)->children.emplace_back((yyvsp[(2) - (4)]));
					(yyval)->children.emplace_back((yyvsp[(3) - (4)]));
					(yyval)->children.emplace_back((yyvsp[(4) - (4)]));
				;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 116 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token = "idlist";
			(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
		;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 120 "yacc.y"
    {
                  	(yyval)=new Type;
                  	(yyval)->token = "idlist";
                  	(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
                  	(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
                  	(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
                  ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 128 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token = "const_declarations";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 134 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token = "const_declarations";
					;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 139 "yacc.y"
    {
                   				(yyval)=new Type;
                   				(yyval)->token = "const_declaration";
                   				(yyval)->children.emplace_back((yyvsp[(1) - (3)])); (yyval)->children.emplace_back((yyvsp[(2) - (3)])); (yyval)->children.emplace_back((yyvsp[(3) - (3)]));
                   			;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 143 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token = "const_declaration";
						(yyval)->children.emplace_back((yyvsp[(1) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(4) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(5) - (5)]));
					;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 151 "yacc.y"
    { //右值缺失
						(yyval)=new Type;
						(yyval)->token = "const_declaration";
						yyerror("constant definition missing initial r-value", (yylsp[(4) - (5)]).first_line, (yylsp[(4) - (5)]).first_column, (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column);
					;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 155 "yacc.y"
    { //右值缺失
						(yyval)=new Type;
						(yyval)->token = "const_declaration";
						yyerror("constant definition missing initial r-value", (yylsp[(3) - (3)]).first_line, (yylsp[(3) - (3)]).first_column, (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column);
					;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 161 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (2)]));
					(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
				;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 166 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (2)]));
					(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
				;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 171 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
				;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 175 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (2)]));
					(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
				;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 180 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (2)])); (yyval)->children.emplace_back((yyvsp[(2) - (2)]));
				;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 184 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
				;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 188 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (2)])); (yyval)->children.emplace_back((yyvsp[(2) - (2)]));
				;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 192 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (2)])); (yyval)->children.emplace_back((yyvsp[(2) - (2)]));
				;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 196 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
				;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 200 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token = "const_value";
					(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
				;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 206 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token = "var_declarations";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 212 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token = "var_declarations";
					;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 215 "yacc.y"
    { //缺少分号
						(yyval)=new Type;
						(yyval)->token = "var_declarations";
						yyerror("missing a semicolon here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
					;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 219 "yacc.y"
    { //缺少关键字VAR
                                                (yyval)=new Type;
                                                (yyval)->token = "const_value";
                                                yyerror("missing keyword \"VAR\" here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
                                        ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 225 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token = "var_declaration";
						(yyval)->children.emplace_back((yyvsp[(1) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(4) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(5) - (5)]));
					;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 233 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token ="var_declaration";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));(yyval)->children.emplace_back((yyvsp[(2) - (3)])); (yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 237 "yacc.y"
    { //缺少冒号
                                         	(yyval)=new Type;
                                         	(yyval)->token = "var_declaration";
                                         	yyerror("missing a colon here", (yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column+1);
                                        ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 241 "yacc.y"
    { //缺少分号
						(yyval)=new Type;
						(yyval)->token = "var_declaration";
						yyerror("missing a semicolon here", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
					;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 245 "yacc.y"
    { //type识别失败
						(yyval)=new Type;
						(yyval)->token = "var_declaration";
						yyerror("missing a type here", (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column+1);
					;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 249 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token ="var_declaration";
						yyerror("missing a type here", (yylsp[(3) - (3)]).last_line, (yylsp[(3) - (3)]).last_column+1);
					;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 255 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token = "type";
			(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
		;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 259 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token = "type";
			(yyval)->children.emplace_back((yyvsp[(1) - (6)]));
			(yyval)->children.emplace_back((yyvsp[(2) - (6)]));
			(yyval)->children.emplace_back((yyvsp[(3) - (6)]));
			(yyval)->children.emplace_back((yyvsp[(4) - (6)]));
			(yyval)->children.emplace_back((yyvsp[(5) - (6)]));
			(yyval)->children.emplace_back((yyvsp[(6) - (6)]));
		;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 268 "yacc.y"
    { //缺少OF关键字
			(yyval)=new Type;
			(yyval)->token = "type";
			yyerror("missing keyword \"OF\" here", (yylsp[(4) - (6)]).last_line, (yylsp[(4) - (6)]).last_column+1, (yylsp[(6) - (6)]).first_line, (yylsp[(6) - (6)]).first_column-1);
		;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 272 "yacc.y"
    { //数组元素类型识别失败
			(yyval)=new Type;
			(yyval)->token = "type";
			yyerror("failed to get Array-type", (yylsp[(5) - (6)]).last_line, (yylsp[(5) - (6)]).last_column+1);
		;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 278 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="period";
			(yyval)->children.emplace_back((yyvsp[(1) - (5)]));
			(yyval)->children.emplace_back((yyvsp[(2) - (5)]));
			(yyval)->children.emplace_back((yyvsp[(3) - (5)]));
			(yyval)->children.emplace_back((yyvsp[(4) - (5)]));
			(yyval)->children.emplace_back((yyvsp[(5) - (5)]));
		;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 286 "yacc.y"
    {
                 	(yyval)=new Type;
                 	(yyval)->token="period";
                 	(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
                 	(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
                 	(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
                ;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 292 "yacc.y"
    { //缺少逗号
			(yyval)=new Type;
			(yyval)->token="period";
			yyerror("missing a comma here", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
		;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 296 "yacc.y"
    { //缺少双点号
			(yyval)=new Type;
			(yyval)->token="period";
			yyerror("missing range dot .. here", (yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column+1);
		;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 302 "yacc.y"
    {
								(yyval)=new Type;
								(yyval)->token="subprogram_declarations";
								(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
								(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
								(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
							;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 308 "yacc.y"
    { //缺少分号
								(yyval)=new Type;
								(yyval)->token="subprogram_declarations";
								yyerror("missing a semicolon here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
							;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 312 "yacc.y"
    {
								(yyval)=new Type;
								(yyval)->token ="subprogram_declarations";
							;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 317 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="subprogram";
				(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
			;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 325 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="subprogram_head";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 331 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="subprogram_head";
						(yyval)->children.emplace_back((yyvsp[(1) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(4) - (5)]));
						(yyval)->children.emplace_back((yyvsp[(5) - (5)]));
					;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 339 "yacc.y"
    { //函数名缺失
						(yyval)=new Type;
						(yyval)->token="subprogram_head";
						yyerror("missing function name", (yylsp[(1) - (5)]).last_line, (yylsp[(1) - (5)]).last_column+1);
					;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 343 "yacc.y"
    { //缺少冒号
						(yyval)=new Type;
						(yyval)->token="subprogram_head";
						yyerror("missing a colon here", (yylsp[(3) - (5)]).last_line, (yylsp[(3) - (5)]).last_column);
					;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 347 "yacc.y"
    { //缺少基本类型关键字
						(yyval)=new Type;
						(yyval)->token="subprogram_head";
						yyerror("missing a base type keyword here", (yylsp[(4) - (5)]).last_line, (yylsp[(4) - (5)]).last_column+1);
					;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 353 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="formal_parameter";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 359 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="formal_parameter";
					;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 362 "yacc.y"
    { //不完整的形参列表
						(yyval)=new Type;
						(yyval)->token="formal_parameter";
						yyerror("incomplete formal parameter list", (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column+1);
					;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 368 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token="parameter_list";
					(yyval)->children.emplace_back((yyvsp[(1) - (3)]));(yyval)->children.emplace_back((yyvsp[(2) - (3)]));(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
				;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 372 "yacc.y"
    {
                                 	(yyval)=new Type;
                                 	(yyval)->token="parameter_list";
                                 	(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
                                ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 376 "yacc.y"
    { //缺少分号
					(yyval)=new Type;
					(yyval)->token="parameter_list";
					yyerror("missing a semicolon here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
				;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 382 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="parameter";
				(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
			;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 386 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="parameter";
				(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
			;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 392 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token="var_parameter";
					(yyval)->children.emplace_back((yyvsp[(1) - (2)]));(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
				;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 396 "yacc.y"
    { //不完整的引用参数列表
					(yyval)=new Type;
					(yyval)->token="var_parameter";
					yyerror("incomplete refereced parameter list", (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column+1);
				;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 402 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="value_parameter";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 408 "yacc.y"
    { //缺少分号
						(yyval)=new Type;
						(yyval)->token="value_parameter";
						yyerror("missing a colon here", (yylsp[(1) - (3)]).first_line, (yylsp[(1) - (3)]).last_column+1);
					;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 414 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="subprogram_body";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 422 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="compound_statement";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 428 "yacc.y"
    { //缺少END关键字
						(yyval)=new Type;
						(yyval)->token="compound_statement";
						yyerror("missing keyword \"end\"", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
					;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 434 "yacc.y"
    {
					(yyval)=new Type;
					(yyval)->token="statement_list";
					(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
					(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
					(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
				;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 440 "yacc.y"
    {
                                 	(yyval)=new Type;
                                 	(yyval)->token="statement_list";
                                 	(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
                                ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 444 "yacc.y"
    { //缺失分号 这里引发了3个规约规约冲突
					(yyval)=new Type;
					(yyval)->token="statement_list";
					yyerror("missing a semicolon here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
				;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 450 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="statement";
				(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
			;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 456 "yacc.y"
    {
                         	(yyval)=new Type;
                         	(yyval)->token="statement";
                         	(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
                        ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 460 "yacc.y"
    {
                         	(yyval)=new Type;
                         	(yyval)->token="statement";
                         	(yyval)->children.emplace_back((yyvsp[(1) - (5)]));
                         	(yyval)->children.emplace_back((yyvsp[(2) - (5)]));
                         	(yyval)->children.emplace_back((yyvsp[(3) - (5)]));
                         	(yyval)->children.emplace_back((yyvsp[(4) - (5)]));
                         	(yyval)->children.emplace_back((yyvsp[(5) - (5)]));
                        ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 468 "yacc.y"
    {
                         	(yyval)=new Type;
                         	(yyval)->token="statement";
                        ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 471 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="statement";
				(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
			;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 475 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="statement";
				(yyval)->children.emplace_back((yyvsp[(1) - (8)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (8)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (8)]));
				(yyval)->children.emplace_back((yyvsp[(4) - (8)]));
				(yyval)->children.emplace_back((yyvsp[(5) - (8)]));
				(yyval)->children.emplace_back((yyvsp[(6) - (8)]));
				(yyval)->children.emplace_back((yyvsp[(7) - (8)]));
				(yyval)->children.emplace_back((yyvsp[(8) - (8)]));
			;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 486 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="statement";
				(yyval)->children.emplace_back((yyvsp[(1) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(4) - (4)]));
			;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 493 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="statement";
				(yyval)->children.emplace_back((yyvsp[(1) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(4) - (4)]));
			;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 500 "yacc.y"
    { //缺少赋值号
                         	(yyval)=new Type;
                         	(yyval)->token="statement";
                         	yyerror("missing assignop \":=\"", (yylsp[(2) - (8)]).last_line, (yylsp[(2) - (8)]).last_column+1);
                        ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 504 "yacc.y"
    { //缺少then关键字
                         	(yyval)=new Type;
                         	(yyval)->token="statement";
                         	yyerror("missing keyword \"then\"", (yylsp[(2) - (5)]).last_line, (yylsp[(2) - (5)]).last_column+1);
                        ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 508 "yacc.y"
    { //缺少关键字until
				(yyval)=new Type;
				(yyval)->token="statement";
				yyerror("missing keywrod \"until\"", (yylsp[(4) - (4)]).first_line, (yylsp[(4) - (4)]).first_column);
			;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 514 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="else_part";
				(yyval)->children.emplace_back((yyvsp[(1) - (2)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
			;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 519 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="else_part";
			;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 524 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="variable";
				(yyval)->children.emplace_back((yyvsp[(1) - (2)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
			;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 531 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="id_varpart";
				(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
			;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 537 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="id_varpart";
			;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 540 "yacc.y"
    { //不完整的数组下标列表
                         	(yyval)=new Type;
                         	(yyval)->token="id_varpart";
                         	yyerror("incomplete expression list of array subindex",  (yylsp[(2) - (2)]).last_line, (yylsp[(2) - (2)]).last_column+1);
                        ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 546 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="procedure_call";
				(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
			;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 550 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="procedure_call";
				(yyval)->children.emplace_back((yyvsp[(1) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (4)]));
				(yyval)->children.emplace_back((yyvsp[(4) - (4)]));
			;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 557 "yacc.y"
    { //缺少右括号
				(yyval)=new Type;
				(yyval)->token="procedure_call";
				yyerror("missing a right bracket here", (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column+1);
			;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 563 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="expression_list";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 569 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="expression_list";
						(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
					;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 573 "yacc.y"
    { //缺少逗号 这里引发了一个移进规约冲突
						(yyval)=new Type;
						(yyval)->token="expression_list";
						yyerror("missing a comma here", (yylsp[(1) - (3)]).last_line, (yylsp[(1) - (3)]).last_column+1);
					;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 579 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="expression";
				(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
				(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
			;}
    break;

  case 97:

/* Line 1455 of yacc.c  */
#line 585 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="expression";
				(yyval)->children.emplace_back((yyvsp[(1) - (3)]));(yyval)->children.emplace_back((yyvsp[(2) - (3)]));(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
			;}
    break;

  case 98:

/* Line 1455 of yacc.c  */
#line 589 "yacc.y"
    {
				(yyval)=new Type;
				(yyval)->token="expression";
				(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
			;}
    break;

  case 99:

/* Line 1455 of yacc.c  */
#line 595 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="simple_expression";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 100:

/* Line 1455 of yacc.c  */
#line 601 "yacc.y"
    {//error，缺少操作数
						(yyval)=new Type;
						(yyval)->token="simple_expression";
						yyerror("missing operand",(yylsp[(2) - (4)]).last_line, (yylsp[(2) - (4)]).last_column+1);
					;}
    break;

  case 101:

/* Line 1455 of yacc.c  */
#line 605 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="simple_expression";
						(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
						(yyval)->children.emplace_back((yyvsp[(2) - (3)]));(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
					;}
    break;

  case 102:

/* Line 1455 of yacc.c  */
#line 610 "yacc.y"
    {//error，缺少操作数
						(yyval)=new Type;
						(yyval)->token="simple_expression";
						yyerror("missing operand",(yylsp[(2) - (4)]).last_line, (yylsp[(2) - (4)]).last_column+1);
					;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 614 "yacc.y"
    {
						(yyval)=new Type;
						(yyval)->token="simple_expression";
						(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
					;}
    break;

  case 104:

/* Line 1455 of yacc.c  */
#line 620 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="term";
			(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
			(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
			(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
		;}
    break;

  case 105:

/* Line 1455 of yacc.c  */
#line 626 "yacc.y"
    { //操作符缺失
                        (yyval)=new Type;
                        (yyval)->token="term";
                        yyerror("missing operator here",(yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
		;}
    break;

  case 106:

/* Line 1455 of yacc.c  */
#line 630 "yacc.y"
    { //缺少操作数
			(yyval)=new Type;
			(yyval)->token="term";
			yyerror("missing operand",(yylsp[(2) - (4)]).last_line, (yylsp[(2) - (4)]).last_column+1);
		;}
    break;

  case 107:

/* Line 1455 of yacc.c  */
#line 634 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="term";
			(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
		;}
    break;

  case 108:

/* Line 1455 of yacc.c  */
#line 640 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
		;}
    break;

  case 109:

/* Line 1455 of yacc.c  */
#line 644 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
		;}
    break;

  case 110:

/* Line 1455 of yacc.c  */
#line 648 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
		;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 652 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (4)]));
			(yyval)->children.emplace_back((yyvsp[(2) - (4)]));
			(yyval)->children.emplace_back((yyvsp[(3) - (4)]));
			(yyval)->children.emplace_back((yyvsp[(4) - (4)]));
		;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 659 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (3)]));
			(yyval)->children.emplace_back((yyvsp[(2) - (3)]));
			(yyval)->children.emplace_back((yyvsp[(3) - (3)]));
		;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 665 "yacc.y"
    { //缺少右括号
			(yyval)=new Type;
			(yyval)->token="factor";
			yyerror("missing a r-bracket here", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
		;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 669 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (2)]));
			(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
		;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 674 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (2)]));
			(yyval)->children.emplace_back((yyvsp[(2) - (2)]));
		;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 679 "yacc.y"
    {
			(yyval)=new Type;
			(yyval)->token="factor";
			(yyval)->children.emplace_back((yyvsp[(1) - (1)]));
		;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 683 "yacc.y"
    { //缺少右括号 这里引发了一个移进规约冲突
                 	(yyval)=new Type;
                 	(yyval)->token="factor";
                 	yyerror("missing a r-bracket here", (yylsp[(3) - (4)]).last_line, (yylsp[(3) - (4)]).last_column+1);
                ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 687 "yacc.y"
    { //函数调用列表缺失
                 	(yyval)=new Type;
                 	(yyval)->token="factor";
                 	yyerror("incomplete formal parameter list", (yylsp[(2) - (3)]).last_line, (yylsp[(2) - (3)]).last_column+1);
                ;}
    break;



/* Line 1455 of yacc.c  */
#line 3050 "yacc.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }

  yyerror_range[0] = yylloc;

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, &yylloc);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[0] = yylsp[1-yylen];
  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;

      yyerror_range[0] = *yylsp;
      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;

  yyerror_range[1] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, (yyerror_range - 1), 2);
  *++yylsp = yyloc;

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, &yylloc);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 693 "yacc.y"


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

