#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "common.h"

typedef int ElemType;
// 定义结点结构
struct LNode
{
    ElemType data;
    struct LNode * next;
};
typedef struct LNode * LinkedList; // 定义链表为指向结点的指针。

Status InitList(LinkedList *);
Status ListInsert(LinkedList * L,int i,ElemType);
Status ListInsert2(LinkedList L,int i,ElemType);
Status ListTraverse(LinkedList L,void (*vi)(ElemType));
void visit(ElemType);
Status GetElem(LinkedList,int,ElemType *);
Status ListDelete(LinkedList *,int,ElemType *);
Status CreateList(LinkedList *,int);
Status CreateList2(LinkedList *,int);
#endif
