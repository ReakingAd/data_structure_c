#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "stack.h"
Status visit(SElemType e)
{
    printf("%d",e);
    return OK;
}
int main()
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
