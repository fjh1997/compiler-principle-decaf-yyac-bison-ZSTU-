
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define YYLSP_NEEDED

#define	T_Void	258
#define	T_Bool	259
#define	T_Int	260
#define	T_Double	261
#define	T_String	262
#define	T_Class	263
#define	T_LessEqual	264
#define	T_GreaterEqual	265
#define	T_Equal	266
#define	T_NotEqual	267
#define	T_And	268
#define	T_Or	269
#define	T_Null	270
#define	T_Extends	271
#define	T_This	272
#define	T_While	273
#define	T_For	274
#define	T_If	275
#define	T_Else	276
#define	T_Return	277
#define	T_Identifier	278
#define	T_StringConstant	279
#define	T_IntConstant	280
#define	T_DoubleConstant	281
#define	T_BoolConstant	282
#define	T_New	283
#define	T_NewArray	284
#define	T_Print	285
#define	T_ReadInteger	286
#define	T_ReadLine	287
#define	T_PostPlus	288
#define	T_PostMinus	289
#define	T_Switch	290
#define	T_Case	291
#define	T_Default	292
#define	T_Break	293
#define	Lower_Than_Else	294
#define	UMINUS	295

#line 10 "parser.y"


/*
 *同flex一样，第一个%{ %}内部的程序将被直接copy到parser_tab.h/c中
 *所以可以将要include的头文件和全局变量放到这儿。
*/
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <process.h>	
#include "scanner.h"


#line 68 "parser.y"
typedef union {			/*bison可以从这个定义中产生yylval的定义*/
  int integerConstant;
  int boolConstant;
  const char *stringConstant;
  double doubleConstant;
  char identifier[128];
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		187
#define	YYFLAG		-32768
#define	YYNTBASE	60

#define YYTRANSLATE(x) ((unsigned)(x) <= 295 ? yytranslate[x] : 97)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    48,     2,     2,     2,    47,     2,     2,    54,
    55,    45,    43,    56,    44,    51,    46,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    59,    52,    41,
    40,    42,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    50,     2,    53,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,    57,     2,    58,     2,     2,     2,     2,     2,
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
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    49
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     5,     6,     8,    10,    12,    14,    17,    20,
    22,    24,    26,    28,    30,    33,    37,    44,    46,    47,
    51,    53,    60,    67,    70,    71,    74,    75,    77,    79,
    81,    85,    88,    89,    91,    94,    96,    98,   100,   102,
   105,   108,   110,   113,   117,   119,   120,   123,   128,   131,
   132,   138,   140,   141,   145,   147,   157,   163,   170,   173,
   174,   184,   187,   188,   193,   197,   198,   200,   202,   205,
   210,   212,   214,   216,   219,   222,   224,   226,   230,   234,
   238,   242,   246,   250,   253,   257,   261,   265,   269,   273,
   277,   281,   285,   288,   292,   296,   301,   308,   310,   312,
   314,   316
};

static const short yyrhs[] = {    61,
     0,    61,    62,     0,     0,    63,     0,    70,     0,    69,
     0,    66,     0,    64,    52,     0,    65,    23,     0,     5,
     0,     6,     0,     4,     0,     7,     0,     3,     0,     8,
    23,     0,    65,    50,    53,     0,    65,    23,    54,    67,
    55,    52,     0,    68,     0,     0,    68,    56,    64,     0,
    64,     0,    65,    23,    54,    67,    55,    74,     0,     8,
    23,    71,    57,    72,    58,     0,    16,    23,     0,     0,
    72,    73,     0,     0,    63,     0,    66,     0,    69,     0,
    57,    75,    58,     0,    75,    76,     0,     0,    63,     0,
    77,    52,     0,    85,     0,    84,     0,    83,     0,    87,
     0,    92,    52,     0,    93,    52,     0,    74,     0,    91,
    52,     0,    78,    40,    95,     0,    95,     0,     0,    79,
    23,     0,    95,    50,    95,    53,     0,    95,    51,     0,
     0,    79,    23,    54,    81,    55,     0,    82,     0,     0,
    82,    56,    95,     0,    95,     0,    19,    54,    77,    52,
    94,    52,    77,    55,    76,     0,    18,    54,    94,    55,
    76,     0,    20,    54,    94,    55,    76,    86,     0,    21,
    76,     0,     0,    35,    54,    95,    55,    57,    89,    88,
    90,    58,     0,    88,    89,     0,     0,    36,    25,    59,
    75,     0,    37,    59,    75,     0,     0,    38,     0,    22,
     0,    22,    95,     0,    30,    54,    82,    55,     0,    95,
     0,    96,     0,    78,     0,    78,    33,     0,    78,    34,
     0,    17,     0,    80,     0,    54,    95,    55,     0,    95,
    43,    95,     0,    95,    44,    95,     0,    95,    45,    95,
     0,    95,    46,    95,     0,    95,    47,    95,     0,    44,
    95,     0,    95,    41,    95,     0,    95,     9,    95,     0,
    95,    42,    95,     0,    95,    10,    95,     0,    95,    11,
    95,     0,    95,    12,    95,     0,    95,    13,    95,     0,
    95,    14,    95,     0,    48,    95,     0,    31,    54,    55,
     0,    32,    54,    55,     0,    28,    54,    23,    55,     0,
    29,    54,    95,    56,    65,    55,     0,    25,     0,    26,
     0,    27,     0,    24,     0,    15,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    88,    94,    95,    99,   100,   101,   102,   105,   109,   112,
   113,   114,   115,   116,   117,   118,   121,   124,   125,   128,
   129,   132,   135,   138,   139,   142,   143,   146,   147,   148,
   151,   154,   155,   158,   159,   160,   161,   162,   163,   164,
   165,   166,   167,   170,   171,   172,   175,   176,   179,   180,
   183,   186,   187,   190,   191,   194,   197,   200,   203,   204,
   207,   210,   211,   214,   217,   218,   221,   224,   225,   228,
   231,   234,   235,   236,   237,   238,   239,   240,   241,   242,
   243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
   253,   254,   255,   256,   257,   258,   259,   262,   263,   264,
   265,   266
};

static const char * const yytname[] = {   "$","error","$undefined.","T_Void",
"T_Bool","T_Int","T_Double","T_String","T_Class","T_LessEqual","T_GreaterEqual",
"T_Equal","T_NotEqual","T_And","T_Or","T_Null","T_Extends","T_This","T_While",
"T_For","T_If","T_Else","T_Return","T_Identifier","T_StringConstant","T_IntConstant",
"T_DoubleConstant","T_BoolConstant","T_New","T_NewArray","T_Print","T_ReadInteger",
"T_ReadLine","T_PostPlus","T_PostMinus","T_Switch","T_Case","T_Default","T_Break",
"Lower_Than_Else","'='","'<'","'>'","'+'","'-'","'*'","'/'","'%'","'!'","UMINUS",
"'['","'.'","';'","']'","'('","')'","','","'{'","'}'","':'","Program","DeclList",
"Decl","VariableDecl","Variable","Type","FunctionDecl","Formals","VariableList",
"FunctionDefn","ClassDefn","OptExtends","FieldList","Field","StmtBlock","StmtList",
"Stmt","SimpleStmt","LValue","OptReceiver","Call","Actuals","ExprList","ForStmt",
"WhileStmt","IfStmt","OptElse","SwitchStmt","CaseList","CaseStmt","DefaultStmt",
"BreakStmt","ReturnStmt","PrintStmt","BoolExpr","Expr","Constant",""
};
#endif

static const short yyr1[] = {     0,
    60,    61,    61,    62,    62,    62,    62,    63,    64,    65,
    65,    65,    65,    65,    65,    65,    66,    67,    67,    68,
    68,    69,    70,    71,    71,    72,    72,    73,    73,    73,
    74,    75,    75,    76,    76,    76,    76,    76,    76,    76,
    76,    76,    76,    77,    77,    77,    78,    78,    79,    79,
    80,    81,    81,    82,    82,    83,    84,    85,    86,    86,
    87,    88,    88,    89,    90,    90,    91,    92,    92,    93,
    94,    95,    95,    95,    95,    95,    95,    95,    95,    95,
    95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
    95,    95,    95,    95,    95,    95,    95,    96,    96,    96,
    96,    96
};

static const short yyr2[] = {     0,
     1,     2,     0,     1,     1,     1,     1,     2,     2,     1,
     1,     1,     1,     1,     2,     3,     6,     1,     0,     3,
     1,     6,     6,     2,     0,     2,     0,     1,     1,     1,
     3,     2,     0,     1,     2,     1,     1,     1,     1,     2,
     2,     1,     2,     3,     1,     0,     2,     4,     2,     0,
     5,     1,     0,     3,     1,     9,     5,     6,     2,     0,
     9,     2,     0,     4,     3,     0,     1,     1,     2,     4,
     1,     1,     1,     2,     2,     1,     1,     3,     3,     3,
     3,     3,     3,     2,     3,     3,     3,     3,     3,     3,
     3,     3,     2,     3,     3,     4,     6,     1,     1,     1,
     1,     1
};

static const short yydefact[] = {     3,
     1,    14,    12,    10,    11,    13,     0,     2,     4,     0,
     0,     7,     6,     5,    15,     8,     9,     0,     0,     0,
    19,    16,    24,    27,     0,    21,     0,     0,    18,     0,
    15,     9,     0,     0,    23,    28,    29,    30,    26,    17,
    33,    22,    20,    46,   102,    76,     0,     0,     0,    50,
   101,    98,    99,   100,     0,     0,     0,     0,     0,     0,
    67,    50,    50,    50,    31,    34,    42,    32,     0,    73,
     0,    77,    38,    37,    36,    39,     0,     0,     0,    45,
    72,    50,    46,    50,    73,    69,     0,    50,    50,     0,
     0,    50,    84,    93,     0,    35,    74,    75,    50,    47,
    43,    40,    41,    50,    50,    50,    50,    50,    50,    50,
    50,    50,    50,    50,    50,    50,    50,    49,     0,    71,
     0,     0,     0,     0,     0,    55,    94,    95,     0,    78,
    44,    50,    86,    88,    89,    90,    91,    92,    85,    87,
    79,    80,    81,    82,    83,     0,    46,    50,    46,    96,
     0,    70,    50,     0,     0,    52,    48,    57,     0,    60,
     0,    54,     0,    51,    46,    46,    58,    97,     0,    63,
     0,    59,     0,    66,    46,    33,     0,    62,     0,    56,
    64,    33,    61,    46,     0,     0,     0
};

static const short yydefgoto[] = {   185,
     1,     8,    66,    10,    27,    12,    28,    29,    13,    14,
    20,    30,    39,    67,    44,    68,    69,    85,    71,    72,
   155,   125,    73,    74,    75,   167,    76,   174,   170,   179,
    77,    78,    79,   119,    80,    81
};

static const short yypact[] = {-32768,
   201,-32768,-32768,-32768,-32768,-32768,   -12,-32768,-32768,   -39,
   -17,-32768,-32768,-32768,   -13,-32768,   -29,   -25,     9,     0,
   257,-32768,-32768,-32768,    22,-32768,   -11,    18,    -2,    16,
-32768,-32768,   -42,   257,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,   139,-32768,-32768,    31,    45,    46,   534,
-32768,-32768,-32768,-32768,    47,    49,    51,    54,    62,    63,
-32768,   598,   598,   598,-32768,-32768,-32768,-32768,    35,    -3,
    97,-32768,-32768,-32768,-32768,-32768,    69,    81,    85,   415,
-32768,   598,   566,   598,    15,   415,   113,   598,   598,    93,
    94,   598,    25,    25,    84,-32768,-32768,-32768,   598,    86,
-32768,-32768,-32768,   598,   598,   598,   598,   598,   598,   598,
   598,   598,   598,   598,   598,   598,   598,-32768,    96,   415,
   100,    98,   105,    68,    34,   415,-32768,-32768,   355,-32768,
   415,   502,   454,   454,   465,   465,   437,   426,   454,   454,
     5,     5,    25,    25,    25,   370,   306,   598,   306,-32768,
   257,-32768,   598,   115,   118,    99,-32768,-32768,   123,   155,
    33,   415,   142,-32768,   566,   306,-32768,-32768,   154,-32768,
   125,-32768,   122,    55,   306,-32768,   126,-32768,   124,-32768,
   251,-32768,-32768,   195,   184,   186,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,     4,    -7,    -1,   158,-32768,-32768,   159,-32768,
-32768,-32768,-32768,   157,  -135,  -140,   -81,   -43,-32768,-32768,
-32768,    59,-32768,-32768,-32768,-32768,-32768,-32768,    20,-32768,
-32768,-32768,-32768,   -76,   -46,-32768
};


#define	YYLAST		652


static const short yytable[] = {    11,
    70,   121,    19,    86,     9,    17,   158,   122,   160,    40,
    15,    32,    16,    26,    41,    93,    94,    95,     2,     3,
     4,     5,     6,    25,    21,   172,    43,    22,    11,    97,
    98,    23,    18,    36,   180,   120,    99,   120,    18,    70,
   181,   124,   126,   -25,    31,   129,   184,    97,    98,   114,
   115,   116,   131,    34,   117,   118,    24,   133,   134,   135,
   136,   137,   138,   139,   140,   141,   142,   143,   144,   145,
   146,   159,    33,    35,   117,   118,   104,   105,   106,   107,
   108,   109,    18,   171,    82,   126,    96,   168,   152,   153,
   169,   177,   104,   105,   106,   107,   108,   109,    83,    84,
    87,   120,    88,    70,    89,    70,   162,    90,   110,   111,
   112,   113,   114,   115,   116,    91,    92,   117,   118,   100,
   101,    70,    70,   151,   110,   111,   112,   113,   114,   115,
   116,    70,   102,   117,   118,   123,   103,    70,   130,   132,
    70,     2,     3,     4,     5,     6,    25,   127,   128,   161,
   147,   148,   149,    45,   153,    46,    47,    48,    49,   150,
    50,   -50,    51,    52,    53,    54,    55,    56,    57,    58,
    59,   163,   164,    60,   165,   166,    61,   169,   173,   175,
   176,   183,    62,   186,   182,   187,    63,    37,    38,    42,
   156,     0,    64,   178,     0,    41,    65,     2,     3,     4,
     5,     6,    25,     2,     3,     4,     5,     6,     7,    45,
     0,    46,    47,    48,    49,     0,    50,   -50,    51,    52,
    53,    54,    55,    56,    57,    58,    59,     0,     0,    60,
     0,     0,    61,     0,     0,     0,     0,     0,    62,     0,
     0,     0,    63,     0,     0,     0,     0,     0,    64,     0,
     0,    41,   -65,     2,     3,     4,     5,     6,    25,     2,
     3,     4,     5,     6,    25,    45,     0,    46,    47,    48,
    49,     0,    50,   -50,    51,    52,    53,    54,    55,    56,
    57,    58,    59,     0,     0,    60,     0,     0,    61,     0,
     0,     0,     0,     0,    62,     0,     0,     0,    63,     0,
     0,     0,   -46,     0,    64,     0,     0,    41,     2,     3,
     4,     5,     6,    25,     0,     0,     0,     0,     0,     0,
    45,     0,    46,    47,    48,    49,     0,    50,   -50,    51,
    52,    53,    54,    55,    56,    57,    58,    59,     0,     0,
    60,     0,     0,    61,     0,     0,     0,     0,     0,    62,
     0,     0,     0,    63,     0,     0,     0,     0,     0,    64,
     0,     0,    41,   104,   105,   106,   107,   108,   109,     0,
     0,     0,     0,     0,     0,     0,     0,     0,   104,   105,
   106,   107,   108,   109,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
   115,   116,     0,     0,   117,   118,     0,     0,     0,   154,
   110,   111,   112,   113,   114,   115,   116,     0,     0,   117,
   118,     0,   157,   104,   105,   106,   107,   108,   109,     0,
     0,     0,     0,     0,   104,   105,   106,   107,   108,     0,
     0,     0,     0,     0,     0,   104,   105,   106,   107,     0,
     0,     0,     0,     0,     0,   110,   111,   112,   113,   114,
   115,   116,-32768,-32768,   117,   118,   110,   111,   112,   113,
   114,   115,   116,   104,   105,   117,   118,   110,   111,   112,
   113,   114,   115,   116,     0,     0,   117,   118,     0,     0,
     0,     0,     0,     0,-32768,-32768,   112,   113,   114,   115,
   116,     0,     0,   117,   118,   110,   111,   112,   113,   114,
   115,   116,     0,     0,   117,   118,    45,     0,    46,     0,
     0,     0,     0,     0,     0,    51,    52,    53,    54,    55,
    56,     0,    58,    59,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,    62,     0,     0,    45,    63,
    46,     0,     0,     0,     0,    64,   -53,    51,    52,    53,
    54,    55,    56,     0,    58,    59,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    62,     0,     0,
    45,    63,    46,     0,     0,   -68,     0,    64,   -50,    51,
    52,    53,    54,    55,    56,     0,    58,    59,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
     0,     0,    45,    63,    46,     0,     0,     0,     0,    64,
     0,    51,    52,    53,    54,    55,    56,     0,    58,    59,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,    62,     0,     0,     0,    63,     0,     0,     0,     0,
     0,    64
};

static const short yycheck[] = {     1,
    44,    83,    16,    50,     1,    23,   147,    84,   149,    52,
    23,    23,    52,    21,    57,    62,    63,    64,     3,     4,
     5,     6,     7,     8,    54,   166,    34,    53,    30,    33,
    34,    23,    50,    30,   175,    82,    40,    84,    50,    83,
   176,    88,    89,    57,    23,    92,   182,    33,    34,    45,
    46,    47,    99,    56,    50,    51,    57,   104,   105,   106,
   107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
   117,   148,    55,    58,    50,    51,     9,    10,    11,    12,
    13,    14,    50,   165,    54,   132,    52,    55,    55,    56,
    36,    37,     9,    10,    11,    12,    13,    14,    54,    54,
    54,   148,    54,   147,    54,   149,   153,    54,    41,    42,
    43,    44,    45,    46,    47,    54,    54,    50,    51,    23,
    52,   165,   166,    56,    41,    42,    43,    44,    45,    46,
    47,   175,    52,    50,    51,    23,    52,   181,    55,    54,
   184,     3,     4,     5,     6,     7,     8,    55,    55,   151,
    55,    52,    55,    15,    56,    17,    18,    19,    20,    55,
    22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
    32,    57,    55,    35,    52,    21,    38,    36,    25,    55,
    59,    58,    44,     0,    59,     0,    48,    30,    30,    33,
   132,    -1,    54,   174,    -1,    57,    58,     3,     4,     5,
     6,     7,     8,     3,     4,     5,     6,     7,     8,    15,
    -1,    17,    18,    19,    20,    -1,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    -1,    -1,    35,
    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,
    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,    -1,
    -1,    57,    58,     3,     4,     5,     6,     7,     8,     3,
     4,     5,     6,     7,     8,    15,    -1,    17,    18,    19,
    20,    -1,    22,    23,    24,    25,    26,    27,    28,    29,
    30,    31,    32,    -1,    -1,    35,    -1,    -1,    38,    -1,
    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
    -1,    -1,    52,    -1,    54,    -1,    -1,    57,     3,     4,
     5,     6,     7,     8,    -1,    -1,    -1,    -1,    -1,    -1,
    15,    -1,    17,    18,    19,    20,    -1,    22,    23,    24,
    25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
    35,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    54,
    -1,    -1,    57,     9,    10,    11,    12,    13,    14,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    10,
    11,    12,    13,    14,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
    46,    47,    -1,    -1,    50,    51,    -1,    -1,    -1,    55,
    41,    42,    43,    44,    45,    46,    47,    -1,    -1,    50,
    51,    -1,    53,     9,    10,    11,    12,    13,    14,    -1,
    -1,    -1,    -1,    -1,     9,    10,    11,    12,    13,    -1,
    -1,    -1,    -1,    -1,    -1,     9,    10,    11,    12,    -1,
    -1,    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,
    46,    47,     9,    10,    50,    51,    41,    42,    43,    44,
    45,    46,    47,     9,    10,    50,    51,    41,    42,    43,
    44,    45,    46,    47,    -1,    -1,    50,    51,    -1,    -1,
    -1,    -1,    -1,    -1,    41,    42,    43,    44,    45,    46,
    47,    -1,    -1,    50,    51,    41,    42,    43,    44,    45,
    46,    47,    -1,    -1,    50,    51,    15,    -1,    17,    -1,
    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    27,    28,
    29,    -1,    31,    32,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    15,    48,
    17,    -1,    -1,    -1,    -1,    54,    55,    24,    25,    26,
    27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
    15,    48,    17,    -1,    -1,    52,    -1,    54,    23,    24,
    25,    26,    27,    28,    29,    -1,    31,    32,    -1,    -1,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
    -1,    -1,    15,    48,    17,    -1,    -1,    -1,    -1,    54,
    -1,    24,    25,    26,    27,    28,    29,    -1,    31,    32,
    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
    -1,    54
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Bob Corbett and Richard Stallman

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 1, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */


#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc)
#include <alloca.h>
#else /* not sparc */
#if (defined (MSDOS) || defined(WIN32)) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#define YYLEX		yylex(&yylval, &yylloc)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_bcopy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_bcopy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif


#line 169 "bison.simple"
int
yyparse()
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
#ifdef YYLSP_NEEDED
		 &yyls1, size * sizeof (*yylsp),
#endif
		 &yystacksize);

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_bcopy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_bcopy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_bcopy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 88 "parser.y"
{ printf("Program -> DeclList\n"); yylsp[0];
    break;}
case 2:
#line 94 "parser.y"
{ printf("DeclList -> DeclList Decl\n"); ;
    break;}
case 3:
#line 95 "parser.y"
{ printf("DeclList ->\n"); ;
    break;}
case 4:
#line 99 "parser.y"
{ printf("Decl -> VariableDecl\n"); ;
    break;}
case 5:
#line 100 "parser.y"
{ printf("Decl -> ClassDefn\n"); ;
    break;}
case 6:
#line 101 "parser.y"
{ printf("Decl -> FunctionDefn\n"); ;
    break;}
case 7:
#line 102 "parser.y"
{ printf("Decl -> FunctionDecl\n"); ;
    break;}
case 8:
#line 105 "parser.y"
{ printf("VariableDecl -> Variable ;\n"); ;
    break;}
case 9:
#line 109 "parser.y"
{ printf("Variable -> Type identifier\n"); ;
    break;}
case 10:
#line 112 "parser.y"
{ printf("Type -> int\n"); ;
    break;}
case 11:
#line 113 "parser.y"
{ printf("Type -> double\n"); ;
    break;}
case 12:
#line 114 "parser.y"
{ printf("Type -> bool\n"); ;
    break;}
case 13:
#line 115 "parser.y"
{ printf("Type -> string\n"); ;
    break;}
case 14:
#line 116 "parser.y"
{ printf("Type -> void\n"); ;
    break;}
case 15:
#line 117 "parser.y"
{ printf("Type -> class identifier\n"); ;
    break;}
case 16:
#line 118 "parser.y"
{ printf("Type -> Type [ ]\n"); ;
    break;}
case 17:
#line 121 "parser.y"
{ printf("FunctionDecl -> Type identifier ( Formals ) ;\n") ;
    break;}
case 18:
#line 124 "parser.y"
{ printf("Formals -> VariableList\n"); ;
    break;}
case 19:
#line 125 "parser.y"
{ printf("Formals ->\n"); ;
    break;}
case 20:
#line 128 "parser.y"
{ printf("VariableList -> VariableList , Variable\n"); ;
    break;}
case 21:
#line 129 "parser.y"
{ printf("VariableList -> Variable\n"); ;
    break;}
case 22:
#line 132 "parser.y"
{ printf("FunctionDefn -> Type identifier ( Formals ) StmtBlock\n"); ;
    break;}
case 23:
#line 135 "parser.y"
{ printf("ClassDefn -> class identifier OptExtends { FieldList }\n"); ;
    break;}
case 24:
#line 138 "parser.y"
{ printf("OptExtends -> extends identifier\n"); ;
    break;}
case 25:
#line 139 "parser.y"
{ printf("OptExtends ->\n"); ;
    break;}
case 26:
#line 142 "parser.y"
{ printf("FieldList -> FieldList Field\n"); ;
    break;}
case 27:
#line 143 "parser.y"
{ printf("FieldList ->\n"); ;
    break;}
case 28:
#line 146 "parser.y"
{ printf("Field -> VariableDecl\n"); ;
    break;}
case 29:
#line 147 "parser.y"
{ printf("Field -> FunctionDecl\n"); ;
    break;}
case 30:
#line 148 "parser.y"
{ printf("Field -> FunctionDefn\n"); ;
    break;}
case 31:
#line 151 "parser.y"
{ printf("StmtBlock -> { StmtList }\n"); ;
    break;}
case 32:
#line 154 "parser.y"
{ printf("StmtList -> StmtList Stmt\n"); ;
    break;}
case 33:
#line 155 "parser.y"
{ printf("StmtList ->\n"); ;
    break;}
case 34:
#line 158 "parser.y"
{ printf("Stmt -> VariableDecl\n"); ;
    break;}
case 35:
#line 159 "parser.y"
{ printf("Stmt -> SimpleStmt ;\n"); ;
    break;}
case 36:
#line 160 "parser.y"
{ printf("Stmt -> IfStmt\n"); ;
    break;}
case 37:
#line 161 "parser.y"
{ printf("Stmt -> WhileStmt\n"); ;
    break;}
case 38:
#line 162 "parser.y"
{ printf("Stmt -> ForStmt\n"); ;
    break;}
case 39:
#line 163 "parser.y"
{ printf("Stmt -> SwitchStmt\n"); ;
    break;}
case 40:
#line 164 "parser.y"
{ printf("Stmt -> ReturnStmt ;\n"); ;
    break;}
case 41:
#line 165 "parser.y"
{ printf("Stmt -> PrintStmt ;\n"); ;
    break;}
case 42:
#line 166 "parser.y"
{ printf("Stmt -> StmtBlock\n"); ;
    break;}
case 43:
#line 167 "parser.y"
{ printf("Stmt -> BreakStmt ;\n"); ;
    break;}
case 44:
#line 170 "parser.y"
{ printf("SimpleStmt -> LValue = Expr\n"); ;
    break;}
case 45:
#line 171 "parser.y"
{ printf("SimpleStmt -> Expr\n"); ;
    break;}
case 46:
#line 172 "parser.y"
{ printf("SimpleStmt ->\n"); ;
    break;}
case 47:
#line 175 "parser.y"
{ printf("LValue -> OptReceiver identifier\n"); ;
    break;}
case 48:
#line 176 "parser.y"
{ printf("LValue -> Expr [ Expr ]\n"); ;
    break;}
case 49:
#line 179 "parser.y"
{ printf("OptReceiver -> Expr .\n"); ;
    break;}
case 50:
#line 180 "parser.y"
{ printf("OptReceiver ->\n"); ;
    break;}
case 51:
#line 183 "parser.y"
{ printf("Call -> OptReceiver identifier ( Actuals )\n"); ;
    break;}
case 52:
#line 186 "parser.y"
{ printf("Actuals -> ExprList\n"); ;
    break;}
case 53:
#line 187 "parser.y"
{ printf("Actuals ->\n"); ;
    break;}
case 54:
#line 190 "parser.y"
{ printf("ExprList -> ExprList , Expr\n"); ;
    break;}
case 55:
#line 191 "parser.y"
{ printf("ExprList -> Expr\n"); ;
    break;}
case 56:
#line 194 "parser.y"
{ printf("ForStmt -> for ( SimpleStmt; BoolExpr; SimpleStmt) Stmt\n"); ;
    break;}
case 57:
#line 197 "parser.y"
{ printf("WhileStmt -> while ( BoolExpr ) Stmt\n"); ;
    break;}
case 58:
#line 200 "parser.y"
{ printf("IfStmt -> if ( BoolExpr ) Stmt OptElse\n"); ;
    break;}
case 59:
#line 203 "parser.y"
{ printf("OptElse -> else Stmt\n"); ;
    break;}
case 60:
#line 204 "parser.y"
{ printf("OptElse ->\n"); ;
    break;}
case 61:
#line 207 "parser.y"
{ printf("SwitchStmt -> switch ( Expr ) { CaseStmt CaseList Default }\n"); ;
    break;}
case 62:
#line 210 "parser.y"
{ printf("CaseList -> CaseList CaseStmt\n"); ;
    break;}
case 63:
#line 211 "parser.y"
{ printf("CaseList ->\n");;
    break;}
case 64:
#line 214 "parser.y"
{ printf("CaseStmt -> case intConstant : StmtList\n"); ;
    break;}
case 65:
#line 217 "parser.y"
{ printf("DefaultStmt -> default : StmtList\n"); ;
    break;}
case 66:
#line 218 "parser.y"
{ printf("DefaultStmt ->\n"); ;
    break;}
case 67:
#line 221 "parser.y"
{ printf("BreakStmt -> break\n"); ;
    break;}
case 68:
#line 224 "parser.y"
{ printf("ReturnStmt -> return\n"); ;
    break;}
case 69:
#line 225 "parser.y"
{ printf("ReturnStmt -> return Expr\n"); ;
    break;}
case 70:
#line 228 "parser.y"
{ printf("PrintStmt -> Print ( ExprList )\n"); ;
    break;}
case 71:
#line 231 "parser.y"
{ printf("BoolExpr -> Expr\n"); ;
    break;}
case 72:
#line 234 "parser.y"
{ printf("Expr -> Constant\n"); ;
    break;}
case 73:
#line 235 "parser.y"
{ printf("Expr -> LValue\n"); ;
    break;}
case 74:
#line 236 "parser.y"
{ printf("Expr -> LValue ++\n"); ;
    break;}
case 75:
#line 237 "parser.y"
{ printf("Expr -> LValue --\n"); ;
    break;}
case 76:
#line 238 "parser.y"
{ printf("Expr -> this\n"); ;
    break;}
case 77:
#line 239 "parser.y"
{ printf("Expr -> Call\n"); ;
    break;}
case 78:
#line 240 "parser.y"
{ printf("Expr -> ( Expr )\n");;
    break;}
case 79:
#line 241 "parser.y"
{ printf("Expr -> Expr + Expr\n"); ;
    break;}
case 80:
#line 242 "parser.y"
{ printf("Expr -> Expr - Expr\n"); ;
    break;}
case 81:
#line 243 "parser.y"
{ printf("Expr -> Expr * Expr\n"); ;
    break;}
case 82:
#line 244 "parser.y"
{ printf("Expr -> Expr / Expr\n"); ;
    break;}
case 83:
#line 245 "parser.y"
{ printf("Expr -> Expr %% Expr\n"); ;
    break;}
case 84:
#line 246 "parser.y"
{ printf("Expr -> - Expr\n"); ;
    break;}
case 85:
#line 247 "parser.y"
{ printf("Expr -> Expr < Expr\n"); ;
    break;}
case 86:
#line 248 "parser.y"
{ printf("Expr -> Expr <= Expr\n"); ;
    break;}
case 87:
#line 249 "parser.y"
{ printf("Expr -> Expr > Expr\n"); ;
    break;}
case 88:
#line 250 "parser.y"
{ printf("Expr -> Expr >= Expr\n"); ;
    break;}
case 89:
#line 251 "parser.y"
{ printf("Expr -> Expr == Expr\n"); ;
    break;}
case 90:
#line 252 "parser.y"
{ printf("Expr -> Expr != Expr\n"); ;
    break;}
case 91:
#line 253 "parser.y"
{ printf("Expr -> Expr && Expr\n"); ;
    break;}
case 92:
#line 254 "parser.y"
{ printf("Expr -> Expr || Expr\n"); ;
    break;}
case 93:
#line 255 "parser.y"
{ printf("Expr -> ! Expr\n"); ;
    break;}
case 94:
#line 256 "parser.y"
{ printf("Expr -> ReadInteger ( )\n"); ;
    break;}
case 95:
#line 257 "parser.y"
{ printf("Expr -> ReadLine ( )\n"); ;
    break;}
case 96:
#line 258 "parser.y"
{ printf("Expr -> New ( identifier )\n"); ;
    break;}
case 97:
#line 259 "parser.y"
{ printf("Expr -> NewArray ( Expr , Type )\n"); ;
    break;}
case 98:
#line 262 "parser.y"
{ printf("Constant -> intConstant\n"); ;
    break;}
case 99:
#line 263 "parser.y"
{ printf("Constant -> doubleConstant\n"); ;
    break;}
case 100:
#line 264 "parser.y"
{ printf("Constant -> boolConstant\n"); ;
    break;}
case 101:
#line 265 "parser.y"
{ printf("Constant -> stringConstant\n"); ;
    break;}
case 102:
#line 266 "parser.y"
{ printf("Constant -> null\n"); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 442 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = 0; x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 272 "parser.y"
 
/*
 *语法规则到此为止。
 *以下是你自己定义的函数，这些函数将会直接被copy到parser_tab.c文件中，
 *如果你需要一些辅助的函数，可以写到这儿。
*/
void Inityyparse(void)
{
}
