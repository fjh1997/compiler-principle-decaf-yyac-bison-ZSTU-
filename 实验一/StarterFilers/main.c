/*
main.c
   定义main()主函数
   
   不要修改此文件。
*/
#include "declaration.h"
#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*
	输入流，默认为stdin,本程序中为指定的文件
*/
extern FILE * yyin;


/*
	Function:PrintOneToken()
	Useage: PrintOneToken(T_Double, "3.5", val, loc);
	-------------------------------------------------
	输出识别结果。
*/
static void PrintOneToken(TokenType token, char *text, YYSTYPE value,struct yyltype loc)
{
  char buffer[] = {'\'', token, '\'', '\0'};
  char name[256];
  if(token >= T_Void)
  	strcpy(name,gTokenNames[token - T_Void]);
  else strcpy(name,buffer);
  
  printf("%-12s line %d cols %d-%d is %s ", text,
	   loc.first_line, loc.first_column, loc.last_column, name);
  
  switch(token) {
    case T_IntConstant:     
      printf("(value = %d)\n", value.integerConstant); break;
    case T_DoubleConstant:   
      printf("(value = %g)\n", value.doubleConstant); break;
    case T_StringConstant:  
      printf("(value = %s)\n", value.stringConstant); break;
    case T_BoolConstant:    
      printf("(value = %s)\n", value.boolConstant ? "true" : "false"); break;
    case T_Identifier: 
      value.decl->Print(); break;
    default:
      printf("\n"); break;
  }
}


/*
	Function main()
	--------------
	首先根据参数确定输入的来源，然后循环调用yylex()获得识别结果。
*/
int main(int argc, char *argv[])
{
	TokenType token;

	FILE * fIn; 
	switch(argc)
	{
	case 1: 					/*默认为test.frag*/
    		fIn=fopen("test.frag","r");
			if(fIn==NULL)
			{
				printf("default file not found\n");
				exit(1);
			}
			yyin = fIn;
    		break;
    case 2: 
    	    if ((fIn = fopen(argv[1],"r")) == NULL)
    	    {
            	printf("File %s not found.\n",argv[1]);
             	exit(1);
            }
            else 
            	yyin=fIn;
            break;
	default:
		printf("useage:pp1 [filename]\n");
		exit(1);
	}
	while((token= (TokenType)yylex())!= 0)
		PrintOneToken(token, yytext, yylval, yylloc);
	
	fclose(fIn);
//	system("pause");
	return (1);
}