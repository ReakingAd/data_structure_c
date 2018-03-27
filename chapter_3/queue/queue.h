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
    QueuePtr front; // 队头指针。指向头结点。头结点的指针域指向队头结点（即第一个存储数据的结点）
    QueuePtr rear; // 队尾指针
} LinkQueue;
Status InitQueue(LinkQueue *);
Status DestroyQueue(LinkQueue *);
Status ClearQueue(LinkQueue * );
Status QueueEmpty(LinkQueue);
int QueueLength(LinkQueue);
Status GetHead(LinkQueue Q,QElemType *);
Status EnQueue(LinkQueue *,QElemType);
Status DeQueue(LinkQueue *,QElemType *);
Status QueueTraverse(LinkQueue,void (*vi)(QElemType));
#endif
