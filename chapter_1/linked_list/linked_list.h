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
Status ListInsert(LinkedList,int,ElemType);
Status ListTraverse(LinkedList L,void (*vi)(ElemType));
void visit(ElemType);
#endif
