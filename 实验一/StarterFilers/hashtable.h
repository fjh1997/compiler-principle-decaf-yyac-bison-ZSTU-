/*
hashtable:
   hashtable的实现方法不会影响最后的结果，所以大家可以自由发挥。
   允许大家使用模版\struct等方法，不过要做相应的改动。
   
   hashtable主要存储变量的声明，由于经常查询，所以要用速度比较快的hashtable来实现
*/
       
/*
hashtable:
   hashtable的实现方法不会影响最后的结果，所以大家可以自由发挥。
   允许大家使用类\struct等方法，不过要做相应的改动。
   
   hashtable主要存储变量的声明，由于经常查询，所以要用速度比较快的hashtable来实现
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
                                  
