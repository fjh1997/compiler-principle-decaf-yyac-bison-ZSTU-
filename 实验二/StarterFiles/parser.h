/*
 * parser.h
 * --------------
 * ��Ҫ�޸Ĵ��ļ�������ļ�������parser����Ҫ��һЩ�����ͱ�����
 * 
 */

#ifndef _H_parser
#define _H_parser

 
#include "parser_tab.h"        // use include generated header to get define
extern struct yyltype yylloc;    // global defined in generated parser_tab.c file
 
int yyparse(void);       // Defined in the generated parser_tab.c file
void Inityyparse(void);  // Defined in parser.y

#endif
