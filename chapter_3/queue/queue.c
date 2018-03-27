#include "queue.h"

/**
 * 构造一个空队列Q
 */
Status InitQueue(LinkQueue * Q)
{
    (*Q).front = (*Q).rear = (QueuePtr)malloc( sizeof( QNode) );
    if( !(*Q).front )
        exit(OVERFLOW);
    (*Q).front -> next = NULL; // 设置头结点：指针域指向空，数据域不保存数据
    return OK;
}
/**
 * 销毁队列Q（无论空与否）
 */
Status DestroyQueue(LinkQueue * Q)
{
    while( (*Q).front ) // while循环是不是就是在不停的在队头删除结点？？
    {
        (*Q).rear = (*Q).front -> next;
        free( (*Q).front );
        (*Q).front = (*Q).rear; // ??????  直接保留这两行，都不用while循环不行吗？为什么
    }
    return OK;
}
/**
 * 将Q清为空队列
 */
Status ClearQueue(LinkQueue * Q)
{
    QueuePtr p,q;
    (*Q).rear = (*Q).front; // 头指针和尾指针同时指向头结点时，队列为空
    p = (*Q).front -> next; // 缓存一个头结点的地址，后面用来遍历。姑且称为“遍历指针”
    (*Q).front -> next = NULL; // 头结点的指针域指向空。断开头结点与存储数据的结点的链接。
    while( p ) // 回收遍历指针所指向的结点
    {
        q = p;
        p = p -> next;
        free(q); // 要把每一个曾经用到的结点都free()掉。否则系统不会再将这些内存再利用？？形成了内存浪费？？
    }
    return OK;
}
/**
 * 若Q为空队列，则返回TRUE，否则返回FALSE
 */
int QueueEmpty(LinkQueue Q)
{
    if( Q.front == Q.rear )
        return TRUE;
    else
        return FALSE;
}
/**
 * 求队列的长度
 */
int QueueLength(LinkQueue Q)
{
    int i = 0;
    QueuePtr p;
    p = Q.front;
    while( Q.rear != p )
    {
        i++;
        p = p -> next;
    }
    return i;
}
/**
 * 若队列不空，则用e返回Q的队头元素，并返回OK。否则返回ERROR
 */
Status GetHead(LinkQueue Q,QElemType * e)
{
    QueuePtr p;
    if( Q.front == Q.rear )
        return ERROR;
    p = Q.front -> next;
    *e = p -> data;
    return OK;
}
/**
 * 插入元素e为Q的新队尾元素
 */
Status EnQueue(LinkQueue * Q,QElemType e)
{
    QueuePtr p = (QueuePtr)malloc( sizeof(QNode) );
    if( !p )
        exit(OVERFLOW);
    p -> data = e;
    p -> next = NULL;
    (*Q).rear -> next = p; // 将新结点连接到队尾
    (*Q).rear = p; // 将新结点作为新的队尾结点。
    return OK;
}
/**
 * 若队列不空，则删除Q的队头元素，用e保存被删元素。成功返回OK，否则返回ERROR
 */
Status DeQueue(LinkQueue * Q,QElemType * e)
{
    if( (*Q).front == (*Q).rear ) // 如果队列为空，则返回ERROR
        return ERROR;
    QueuePtr p = (*Q).front -> next; // 缓存队头结点，也就是等待被删除的结点
    *e = p -> data; // 讲数据在e中保存
    (*Q).front -> next = p -> next; // 将队头结点在队列中跳过（也就是移除）
    if( (*Q).rear == p ) // 如果if成立，则说明原队列在操作前只有一个保存数据的结点
        (*Q).rear = (*Q).front; // 那么在删除了头结点后，队列将变成控队列。修正队尾指针的值。
    free(p); // 释放p。让其可以被系统用作他用
    return OK;
}
/**
 * 从队头到队尾依次对队列Q中每个元素调用函数vi()。一旦vi()失败，则操作失败
 */
Status QueueTraverse(LinkQueue Q,void (*vi)(QElemType))
{
    QueuePtr p = Q.front -> next;
    while( p )
    {
        vi( p -> data );
        p = p -> next;
    }
    printf("\n");
    return OK;
}
