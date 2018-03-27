#ifndef _QUEUE_H_
#define _QUEUE_H_
#include "common.h"

struct QNode
{
    QElemType data;
    struct QNode * next;
};
typedef struct QNode QNode;
typedef struct QNode  * QueuePtr;

typedef struct
{
    QueuePtr front; // 队头指针 ?????? 不对吧，front应该是头指针。front->next才是队头指针。因为这个实现中有头结点的存在。
                                // Q.front应该是指向头结点 Q.front -> next 指向队头结点
    QueuePtr rear; // 队尾指针
} LinkQueue;
Status InitQueue(LinkQueue *);
Status DestroyQueue(LinkQueue *);
Status ClearQueue(LinkQueue * );
Status QueueEmpty(LinkQueue);
int QueueLength(LinkQueue);
Status GetHead(LinkQueue Q,QElemType *);
#endif
