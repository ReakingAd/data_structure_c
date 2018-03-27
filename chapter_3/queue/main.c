#include "queue.h"

void visit(QElemType e)
{
    printf("%d",e);
}
int main()
{
    int i;
    QElemType d;
    LinkQueue q;
    i = InitQueue( &q );
    if( i )
        printf("InitQueue success \n");
    printf("Queue empty or not ? %d(1:empty 0:not empty)\n",QueueEmpty(q));
    printf("The length of Queue is %d\n",QueueLength(q));
    EnQueue(&q,-5);
    EnQueue(&q,5);
    EnQueue(&q,10);
    printf("After insert(-5,5,10),the length of Queue is %d\n",QueueLength(q));
    printf("Queue empty or not ? %d(1:empty 0:not empty)\n",QueueEmpty(q));
    printf("Output the queue in term is :");
    QueueTraverse(q,visit);
    i = GetHead(q,&d);
    if( i == OK )
        printf("THe front of Queue is :%d\n",d);
    DeQueue(&q,&d);
    printf("After delete the front ElemeType %d\n",d);
    i = GetHead(q,&d);
    if( i == OK )
        printf("The new front of Queue is:%d\n",d);
    ClearQueue(&q);
    printf("After clear the QUeue,q.front=%p q.rear=%p q.front->next=%p\n",q.front,q.rear,q.front->next);
    DestroyQueue(&q);
    printf("After destroy the Queue,q.front=%p q.rear=%p\n",q.front,q.rear);
    return 0;
}
