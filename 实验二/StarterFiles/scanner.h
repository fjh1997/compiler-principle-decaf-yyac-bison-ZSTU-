/*
 *scanner.h
 *这个文件定义了scanner要返回的值和一些数据结构。
 *不要修改此文件
*/
#ifndef _H_scanner
#define _H_scanner




extern char *yytext;
void yyerror(char *msg);
int yylex(void);         // Defined in the generated lex.yy.c file
void Inityylex();        // Defined in scanner.l user subroutine section
#endif