#include <stdio.h>
#include <stdlib.h>
#include "string.h"
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
 * 算法 3.1 数制转换
 * 将键盘键入的非负十进制数字转换成八进制并打印
 */
//void conversion()
//{
//    int n,e;
//    SqStack S;
//    printf("请输入一个非负十进制数字：\n");
//    scanf("%d",&n);
//    InitStack( &S );
//    while( n )
//    {
//        Push( &S,n % 8);
//        n = n / 8;
//    }
//    while( !StackEmpty(S) )
//    {
//        Pop(&S,&e);
//        printf("%d",e);
//    }
//}
Status visit_char(SElemType c)
{
    printf("%c",c);
    return OK;
}
/**
 * 栈应用3.2.2 括号匹配
 * 判断键入的括号组合是否符合成对匹配。有效的括号只有()[]
 */
void CoupleCheck()
{
    SqStack S;
    char topC;
    int State = 0; // 是否正确匹配的标记
    InitStack(&S);
    char str[10];
    printf("请输入待鉴定的括号组合：\n");
    scanf("%s",str);
    int i = 0;
    while( str[i] != '\0' )
    {
        switch( str[i] )
        {
            case '(':
                Push(&S,str[i]);
                State = 0;
                break;
            case '[':
                Push(&S,str[i]);
                State = 0;
                break;
            case ')':
                GetTop(S,&topC);
                if( !StackEmpty(S) && topC == '(' )
                {
                    Pop(&S,&topC);
                    State = 1;
                }
                else
                {
                    Push(&S,str[i]);
                    State = 0;
                }
                break;
            case ']':
                GetTop(S,&topC);
                if( !StackEmpty(S) && topC == '[' )
                {
                    Pop(&S,&topC);
                    State = 1;
                }
                else
                {
                    Push(&S,str[i]);
                    State = 0;
                }
                break;
            default :
                printf("xxxx");
        }
        i++;
    }
    if( StackEmpty(S) && State == 1 )
        printf("匹配\n");
    else
        printf("不匹配\n");
}
/**
 * 算法3.2 行编辑程序
 */
//void LineEdit( )
//{
//    SqStack S;
//    InitStack(&S);
//    char c,pop_c;
//    c = getchar();
//    while( c != EOF )
//    {
//        while( c != EOF && c != '\n' )
//        {
//            printf("in inner while");
//            switch( c )
//            {
//                case '#' :
//                    Pop(&S,&pop_c);
//                case '@' :
//                    ClearStack(&S);
//                default :
//                    Push(&S,c);
//            }
//            c = getchar();
//        }
////        printf("char=%c",c);
//    }
//    printf("=========");
//    StackTraverse(S,visit_char);
//    ClearStack(&S);
//    if( c != EOF ) c = getchar();
//}
void LineEdit( char buffer[] )
{
    SqStack S;
    InitStack( &S );
    SElemType e;
    int i = 0;
    char ch = buffer[i];
    while( ch != '\0' )
    {
        while( ch != '\0' && ch != '\n' )
        {
            switch( ch )
            {
                case '#' :
                    Pop(&S,&e);
                    break;
                case '@' :
                    ClearStack(&S);
                    break;
                default :
                    Push(&S,ch);
            }
            ch = buffer[++  i];
        }
        if( ch == '\n' )
        {
            Push(&S,ch);
            StackTraverse(S,visit_char);
            ClearStack(&S);
            ch = buffer[++i]; // ???????
        }
    }
    if( ch == '\0' )
    {
//        printf("out while");
        StackTraverse(S,visit_char);
    }
}
int main()
{
    stack_main();
//    conversion();
//    CoupleCheck();
//    char buffer[] = "while(true)kk##\n    putchar(&a)";
//    printf("%s",buffer);
//    LineEdit( buffer );
    return 0;
}
