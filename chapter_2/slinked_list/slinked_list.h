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
int Malloc(SLinkedList);
void Free(SLinkedList,int);
Status ListTraverse(SLinkedList,int,void(*vi)(ElemType));
void visit(ElemType);
int difference2(SLinkedList); // 改进算法。尽量使用基本操作完成。
int InitList(SLinkedList);
Status ListInsert(SLinkedList,int,int,ElemType);
int ListLength(SLinkedList,int);
int LocateElem(SLinkedList,int,ElemType);
Status PriorElem(SLinkedList,int,ElemType,ElemType *);
#endif
