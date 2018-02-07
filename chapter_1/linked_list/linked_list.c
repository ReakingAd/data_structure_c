#include "common.h"
#include "linked_list.h"

/**
 * 构建一个空的（带有头结点的）线性链表
 */
Status InitList(LinkedList * L)
{
    (*L) = (LinkedList)malloc( sizeof(struct LNode) ); // 产生头结点，并使L指向头结点
    if( *L == NULL )
        exit(OVERFLOW);
    (*L) -> next = NULL;
    return OK;
}
/**
 * 不改变L？？
 */
Status ListInsert(LinkedList L,int i,ElemType e)
{
    int j = 0;
    LinkedList p = L,s;
    while( p && j < i - 1 ) // 寻找第i-1个结点
    {
        p = p -> next;
        j++;
    }
    if( !p || j > i - 1 )
        return ERROR;
    s = (LinkedList)malloc( sizeof(struct LNode) );
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}
Status ListTraverse(LinkedList L,void (*vi)(ElemType e))
{
    LinkedList p = L -> next;
    while( p )
    {
        vi(p -> data);
        p = p -> next;
    }
    printf("\n");
    return OK;
}
/**
 * 被ListTraverse()使用，以打印链表中的数据
 */
void visit(ElemType c)
{
    printf("%d",c);
}










