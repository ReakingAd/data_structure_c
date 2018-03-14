#ifndef _SLINKED_LIST_H
#define _SLINKED_LIST_H
#include "common.h"
#define MAXSIZE 100
struct component
{
    ElemType data;
    int cur;
};
typedef struct component SLinkedList[MAXSIZE];
void difference(SLinkedList space,int *S);
void InitSpace(SLinkedList);
Status ListInsert(SLinkedList,int,int,ElemType);
#endif
