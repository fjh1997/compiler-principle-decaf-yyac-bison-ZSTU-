/*
 *scanner.h
 *这个文件定义了scanner要返回的值和一些数据结构。
 *不要修改此文件
*/
#ifndef _H_scanner
#define _H_scanner

#include "declaration.h"

typedef enum { 
    T_Void = 256,
    T_Int, T_Double, T_Bool, T_String, T_Class, T_Null, 
    T_LessEqual, T_GreaterEqual, T_Equal, T_NotEqual,
    T_And, T_Or,T_While, T_If, T_Else, T_Return,
    T_Identifier,
    T_StringConstant, T_IntConstant, T_DoubleConstant, T_BoolConstant,
    T_Public, T_Private, T_Extends, T_This,
    T_New, T_NewArray, T_Print, T_ReadInteger, T_ReadLine,
    T_NumTokenTypes
} TokenType;

static const char *gTokenNames[T_NumTokenTypes] = {
  "T_Void", "T_Int", "T_Double", "T_Bool", "T_String", "T_Class", "T_Null",
  "T_LessEqual", "T_GreaterEqual", "T_Equal", "T_NotEqual",
  "T_And", "T_Or", "T_While", "T_If", "T_Else", "T_Return",
  "T_Identifier", "T_StringConstant", "T_IntConstant", "T_DoubleConstant",
  "T_BoolConstant", "T_Public", "T_Private", "T_Extends", "T_This", "T_New",
  "T_NewArray", "T_Print", "T_ReadInteger", "T_ReadLine"
};

typedef union {
    int integerConstant;
    bool boolConstant;
    char stringConstant[1024];
    double doubleConstant;
    Declaration* decl;
} YYSTYPE;

extern YYSTYPE yylval;

struct yyltype {
  int first_line;
  int first_column, last_column;
};

extern struct yyltype yylloc;

extern char *yytext;
int yylex(void);         // Defined in the generated lex.yy.c file
void Inityylex();        // Defined in scanner.l user subroutine section
#endif