#ifndef SEQUENCE_LIST_H_
#define SEQUENCE_LIST_H_
#include "common.h"
#define LIST_INIT_SIZE 10
#define LISTINCREMENT 2

typedef struct
{
    ElemType * elem;
    int length;
    int listsize;
} SqList;

Status InitList(SqList * L);
Status ListInsert(SqList * L,int i,ElemType e);
Status ListTraverse(SqList L,void (*vi)(ElemType *));
int ListLength(SqList L);
Status GetElem(SqList L,int i,ElemType * e);
int LocateElem(SqList L,ElemType e,Status (*compare)(ElemType,ElemType));
Status equal(ElemType,ElemType);
void MergeList(SqList La,SqList Lb,SqList * Lc);

#endif // SEQUENCE_LIST_H_
