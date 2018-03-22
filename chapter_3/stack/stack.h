#ifndef _STACK_H_
#define _STACK_H_

#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2

#include "common.h"
typedef struct
{
    SElemType * base; // 在构造之前和销毁之后，base的值为NULL
    SElemType * top; // 栈顶指针
    int stacksize; // 当前已分配的存储空间，以元素（个数）?为单位
} SqStack; // 顺序栈

Status InitStack(SqStack *);
Status DestroyStack(SqStack *);
Status ClearStack(SqStack *);
Status StackEmpty(SqStack S);
int StackLength(SqStack);
Status GetTop(SqStack,SElemType *);
Status Push(SqStack *,SElemType);
Status Pop(SqStack *,SElemType *) ;
Status StackTraverse(SqStack S,Status (*visit)(SElemType));
#endif // _STACK_H_
