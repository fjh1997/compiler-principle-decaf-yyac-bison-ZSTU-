/*
Hashtable.cpp:
add your code below:
*/

#include <stdio.h>
#include "stdlib.h"
#include "declaration.h"
#include "hashtable.h"
/* SHIFT is the power of two used as multiplier
in hash function  */
#define SHIFT 4
int Hashtable::hash ( const char * key )
{ int temp = 0;
int i = 0;
while (key[i] != '\0')
{ temp = ((temp << SHIFT) + key[i]) % SIZE;
++i;
}
return temp;
}
void Hashtable::st_insert( Declaration declation)
{ int h =hash(declation.GetName());
LineList l =  hashTable[h];
while ((l != NULL) && (strcmp(declation.GetName(),l->declation.GetName()) != 0))
l = l->next;
if (l == NULL)
{ l = (LineList) malloc(sizeof(struct LineListRec));
l->declation = declation;
l->next = hashTable[h];
hashTable[h]=l;
//printf("%d",h);
//printf("666 %s 666",hashTable[189]->declation.GetName());
}
}
Declaration * Hashtable::st_lookup (const char* name)
{ int h = hash(name);
//printf("%d",h);
LineList l =  hashTable[h];
//printf(l->declation.GetName());
while ((l != NULL) && (strcmp(name,l->declation.GetName()) != 0))
l = l->next;
if (l == NULL) return NULL;
else return &(l->declation);
}
