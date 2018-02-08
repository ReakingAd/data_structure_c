#include "common.h"
#include "linked_list.h"

/**
 * 构建一个空的、带有头结点的线性链表
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
/**
 * 对链表每一个结点上的数据，调用指定函数。（本程序中用于打印链表数据）
 */
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
/**
 * 算法2.8
 * 获取指定位置上的结点所保存的数据
 */
Status GetElem(LinkedList L,int i,ElemType * e)
{
    int j = 1;
    LinkedList p = L;
    while( p && j <= i )
    {
        p = p -> next;
        j++;
    }
    if( i < 1 || p == NULL )
        return ERROR;
    *e = p -> data;
    return OK;
}
/**
 * 算法2.10
 * 删除指定位置上的结点，并把该结点的数据存放在指定变量上
 */
Status ListDelete(LinkedList * L,int i,ElemType * e)
{
    int j = 1;
    LinkedList p = *L,q;
    while( p && j <= i - 1 )
    {
        p = p -> next;
        j++;
    }
    if( p == NULL || i < 1 )
        return ERROR;
    q = p -> next; // 要被删除的结点指针
    *e = q -> data;
    p -> next = q -> next;
    return OK;
}
/**
 * 算法2.11
 * 头插法（或称逆序），创建含有指定数量结点的链表。结点中的数据从键盘输入获取
 * 这个函数执行一次后，生成满足要求的链表。不像InitList()和ListInsert()的
 * 组合那样，先生成空的链表，再一个一个插入结点。
 */
Status CreateList(LinkedList * L,int n)
{
    int i;
    LinkedList p;
    *L = (LinkedList)malloc( sizeof(struct LNode) );
    if( *L == NULL )
        exit(OVERFLOW);
    (*L) -> next = NULL; // 先创建头结点
    printf("请一次输入要插入链表的数据：\n");
    for( i = 1 ; i <= n ; i++ )
    {
        p = (LinkedList)malloc( sizeof(struct LNode) );
        if( p == NULL )
            exit(ERROR);
        scanf("%d",&p -> data);
        p -> next = (*L) -> next;
        (*L)-> next = p;
    }
    return OK;
}
/**
 * 对应算法2.11。尾插法（或称正序法）
 */
Status CreateList2(LinkedList * L,int n)
{
    int i;
    LinkedList p,end;
    *L = (LinkedList)malloc( sizeof(struct LNode) );
    if( *L == NULL )
        exit(OVERFLOW);
    (*L) -> next = NULL;
    end = (*L);
    for( i = 1 ; i <= n ; i++)
    {
        p = (LinkedList)malloc( sizeof(struct LNode) );
        if( p == NULL )
            exit(OVERFLOW);
        scanf("%d",&p -> data);
        end -> next = p;
        end = end -> next;
    }
    p -> next = NULL;
    return OK;
}









