#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "stack.h"
Status visit(SElemType e)
{
    printf("%d",e);
    return OK;
}
/**
 * 数据结构stack顺序栈的基本操作测试函数
 */
int stack_main()
{
    int j;
    SqStack s;
    SElemType e;
    if( InitStack(&s) == OK )
        for( j=1;j<=12;j++ )
            Push(&s,j);
    printf("The ElemType in this stack are:\n");
    StackTraverse(s,visit);
    Pop(&s,&e);
    printf("The pop ElemType is e =%d\n",e);
    printf("Empty or not:%d(1:empty 0:not empty)\n",StackEmpty(s));
    printf("The ElemType in this stack are:\n");
    StackTraverse(s,visit);
    GetTop(s,&e);
    printf("The top ElemType is e = %d ,the length of stack is %d\n",e,StackLength(s));
    ClearStack(&s);
    printf("After clear th stack,empty or not:%d(1:empty 0:not empty)\n",StackEmpty(s));printf("The ElemType in this status are:\n");
    StackTraverse(s,visit);
    DestroyStack(&s);
    printf("After destroy the stack ,s.top = %p s.base = %p,s.stacksize = %d\n",s.top,s.base,s.stacksize);
    return 0;
}
/**
 * 算法 3.1
 * 将键盘键入的非负十进制数字转换成八进制并打印
 */
void conversion()
{
    int n,e;
    SqStack S;
    printf("请输入一个非负十进制数字：\n");
    scanf("%d",&n);
    InitStack( &S );
    while( n )
    {
        Push( &S,n % 8);
        n = n / 8;
    }
    while( !StackEmpty(S) )
    {
        Pop(&S,&e);
        printf("%d",e);
    }
}
int main()
{
//    stack_main();
    conversion();
    printf("test git");
    return 0;
}
