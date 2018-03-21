#ifndef _LINKEDLISTPLUS_H_
#define _LINKEDLISTPLUS_H_

#include "common.h"
// 结点类型
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
}LNode,*Link,*Position;
// 链表类型
typedef struct LinkedList
{
    Link head; // 指向线性链表的头结点
    Link tail; // 指向线性链表的最后一个结点
    int len; // 指示线性链表中数据元素的个数
}LinkedList;

Status InitList(LinkedList *);
Status ListInsert(LinkedList *,int,ElemType);
Status LocatePos(LinkedList,int,Link *);
Status MakeNode(Link *,ElemType);
Status InsFirst(LinkedList * ,Link,Link);
Status ListTraverse(LinkedList,void (*visit)(ElemType));
Status MergeList(LinkedList,LinkedList,LinkedList *,int (*compare)(ElemType,ElemType));
Position GetHead(LinkedList);
Position NextPos(Link);
Status ListEmpty(LinkedList);
ElemType GetCurElem(Link);
Status DelFisrt(LinkedList *,Link,Link *);
Status Append(LinkedList *,Link);
void FreeNode(Link *);
Status DestroyList(LinkedList *);
Status ClearList(LinkedList *);
Status DelFirst(LinkedList *,Link,Link *);
#endif
