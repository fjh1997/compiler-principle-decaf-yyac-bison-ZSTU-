/*
hashtable:
   hashtable��ʵ�ַ�������Ӱ�����Ľ�������Դ�ҿ������ɷ��ӡ�
   ������ʹ��ģ��\struct�ȷ���������Ҫ����Ӧ�ĸĶ���
   
   hashtable��Ҫ�洢���������������ھ�����ѯ������Ҫ���ٶȱȽϿ��hashtable��ʵ��
*/
       
/*
hashtable:
   hashtable��ʵ�ַ�������Ӱ�����Ľ�������Դ�ҿ������ɷ��ӡ�
   ������ʹ����\struct�ȷ���������Ҫ����Ӧ�ĸĶ���
   
   hashtable��Ҫ�洢���������������ھ�����ѯ������Ҫ���ٶȱȽϿ��hashtable��ʵ��
*/

#ifndef _H_hashtable
#define _H_hashtable
#include <string.h>
#include "declaration.h"
#define MaxDecla 256
class Declaration;
#define SIZE 211

typedef struct LineListRec
{
	Declaration declation;
	struct LineListRec * next;
}*LineList;
static LineList hashTable[SIZE];
static int location = 0;
class Hashtable {
private:
public:
	int hash(const char *key);
	void st_insert(Declaration declation);
	Declaration *st_lookup(const char *name );
};
#endif 
                                  
