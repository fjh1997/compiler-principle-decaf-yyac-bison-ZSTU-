/*
 *scanner.h
 *����ļ�������scannerҪ���ص�ֵ��һЩ���ݽṹ��
 *��Ҫ�޸Ĵ��ļ�
*/
#ifndef _H_scanner
#define _H_scanner




extern char *yytext;
void yyerror(char *msg);
int yylex(void);         // Defined in the generated lex.yy.c file
void Inityylex();        // Defined in scanner.l user subroutine section
#endif