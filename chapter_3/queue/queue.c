#include "queue.h"

/**
 * 构造一个空队列Q
 */
Status InitQueue(LinkQueue * Q)
{
    (*Q).front = (*Q).rear = (QueuePtr)malloc( sizeof( QNode) );
    if( (*Q).front )
        exit(OVERFLOW);
    (*Q).front -> next = NULL;
    return OK;
}
/**
 * 销毁队列Q（无论空与否）
 */
Status DestroyQueue(LinkQueue * Q)
{
    while( (*Q).front )
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
    QueueStr p,q;
    (*Q).rear = (*Q).front;
    p = (*Q).front -> next;
    (*Q).front -> next = NULL;
    while( p )
    {
        q = p;
        p = p -> next;
        free(q);
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
Status GetHead(LInkQueue Q,QElemType * e)
{
    QueuePtr p;
    if( Q.front == Q.rear )
        return ERROR;
    p = Q.front -> next;
    *e = p -> data;
    return OK;
}
