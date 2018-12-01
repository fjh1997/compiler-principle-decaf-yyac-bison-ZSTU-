/*
main.c
   定义main()主函数
   
   不要修改此文件。
*/
#include "scanner.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*
	输入流，默认为stdin,本程序中为指定的文件
*/
extern FILE * yyin;

/*
	Function main()
	--------------
	首先根据参数确定输入的来源，然后调用Inityylex()和yyparse进行语法分析。
*/
int main(int argc, char *argv[])
{
	FILE * fIn; 
	switch(argc)
	{
	case 1: 					/*默认为test.decaf*/
    		fIn=fopen("test.decaf","r");
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
		printf("useage:pp2 [filename]\n");
		exit(1);
	}
	Inityylex();
	Inityyparse();
	yyparse();
	fclose(fIn);
	return (1);
}