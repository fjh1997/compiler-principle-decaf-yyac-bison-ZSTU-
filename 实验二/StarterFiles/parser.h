/*
 * parser.h
 * --------------
 * 不要修改此文件，这个文件定义了parser所需要的一些函数和变量。
 * 
 */

#ifndef _H_parser
#define _H_parser

 
#include "parser_tab.h"        // use include generated header to get define
extern struct yyltype yylloc;    // global defined in generated parser_tab.c file
 
int yyparse(void);       // Defined in the generated parser_tab.c file
void Inityyparse(void);  // Defined in parser.y

#endif
