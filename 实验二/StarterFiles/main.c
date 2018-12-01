/*
main.c
   ����main()������
   
   ��Ҫ�޸Ĵ��ļ���
*/
#include "scanner.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/*
	��������Ĭ��Ϊstdin,��������Ϊָ�����ļ�
*/
extern FILE * yyin;

/*
	Function main()
	--------------
	���ȸ��ݲ���ȷ���������Դ��Ȼ�����Inityylex()��yyparse�����﷨������
*/
int main(int argc, char *argv[])
{
	FILE * fIn; 
	switch(argc)
	{
	case 1: 					/*Ĭ��Ϊtest.decaf*/
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