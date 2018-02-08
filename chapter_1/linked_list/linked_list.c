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
 * 算法2.9
 * 在带有头结点的单链线性表L的第i个位置之前插入元素e
 */
Status ListInsert(LinkedList * L,int i,ElemType e)
{
    int j = 1;
    LinkedList p = *L,s; // 头指针赋值给p，p此时指向头结点
    while( p && j < i ) // 移动指针p，使其指向第i-1个结点
    {
        p = p -> next;
        j++;
    }
    if( p == NULL || i < 1) // i大于链表最大长度，或者i<1时，都是无效取值
        return ERROR;
    s = (LinkedList)malloc( sizeof(struct LNode) );
    s -> data = e;
    s -> next = p -> next;
    p -> next = s;
    return OK;
}
Status ListInsert2(LinkedList L,int i,ElemType e)
{
    int j = 1;
    LinkedList p = L,s;
    while( p && j < i )
    {
        p = p -> next;
        j++;
    }
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










