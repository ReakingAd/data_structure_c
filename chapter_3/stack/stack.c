#include "common.h"
#include "stack.h"
#include "math.h"

/**
 * 构建一个空栈S
 */
Status InitStack(SqStack * S)
{
    (*S).base = (SElemType *)malloc( sizeof(SElemType) * STACK_INIT_SIZE );
    if( !(*S).base )
        exit(OVERFLOW); // 存储分配失败
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    return OK;
}
/**
 * 销毁栈S，S不再存在
 */
Status DestroyStack(SqStack * S)
{
    free( (*S).base );
    (*S).base = NULL;
    (*S).top = NULL;
    (*S).stacksize = 0;
    return OK;
}
/**
 * 把S置为空栈
 */
Status ClearStack(SqStack * S)
{
    (*S).top = (*S).base;
    return OK;
}
/**
 * 若栈S为空栈，则返回TRUE，否则返回FALSE
 */
Status StackEmpty(SqStack S)
{
    if( S.top == S.base )
        return TRUE;
    else
        return FALSE;
}
/**
 * 返回S的元素个数，即栈的长度
 */
int StackLength(SqStack S)
{
    return S.top - S.base;
}
/**
 * 若栈不空，则用e返回S的栈顶元素，并返回OK。否则返回ERROR
 */
Status GetTop(SqStack S,SElemType * e)
{
    if( S.top > S.base )
    {
        *e = *(S.top - 1);
        return OK;
    }
    else
        return ERROR;
}
/**
 * 插入元素e为新的栈顶元素
 */
Status Push(SqStack * S,SElemType e)
{
    if( (*S).top - (*S).base >= (*S).stacksize ) // 栈满，追加存储空间
    {
        (*S).base = (SElemType *)realloc( (*S).base,sizeof(SElemType) * ( (*S).stacksize + STACKINCREMENT ) );

        if( !(*S).base )
            exit(OVERFLOW); // 存储分配失败
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    *(*S).top++ = e; // 运算符优先级***
    return OK;
}
/**
 * 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
 */
Status Pop(SqStack * S,SElemType * e)
{
    if( (*S).top == (*S).base )
        return ERROR;
    *e = *--(*S).top; // 运算符优先级***
    return OK;
}
/**
 * 从栈底到栈顶一次对栈中每个元素调用函数visit()
 * 一旦visit()失败，则操作失败
 */
Status StackTraverse( SqStack S,Status (*visit)(SElemType))
{
    while( S.top > S.base )
        visit( *S.base++ ); // 运算符优先级？？？？？
//    printf("\n");
    return OK;
}
