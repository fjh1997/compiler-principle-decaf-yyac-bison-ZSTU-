/*
 *declaration.cpp
 *delcaration���ʵ�֡�
 *pp1��Ҫ����ʵ����
*/
#include "declaration.h"
#include <stdio.h>
#include <string.h>


Declaration::Declaration(const char *str,int lineNum,int num)
{
	name=strdup(str);
	lineFound=lineNum;
	numoccur=num;

}

const char * Declaration::GetName()
{
	return name;
}

int Declaration::GetLineFound()
{
	return lineFound;

}
int Declaration::GetOccurrences()
{

	return numoccur;
}

void Declaration::IncrementOccurrences()
{
	numoccur++;
}

/*
 *Print()
 *------
 *��main.c���ã�ע����������ʽ��ʹ���������������е��������һ�¡�
*/
void Declaration::Print()
{
	printf("(%s seen %d time(s), first on line %d)\n",name,numoccur,lineFound);
//	printf("(%s ",name);
}	