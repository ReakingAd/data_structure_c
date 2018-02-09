#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"

/**
 * 算法2.9测试函数
 */
int algo_2_9_main()
{
    Status s,s1;
    LinkedList La,Lb,Lc;
    s = InitList(&La);
    if( s == 1 )
    {
        s1 = ListInsert(&La,1,4);
        printf("La,status=%d\n",s1);
        s1 = ListInsert(&La,2,9);
        printf("La,status=%d\n",s1);
    }
    ListTraverse(La,visit);
    s = InitList(&Lb);
    if( s == 1 )
    {
        s1 = ListInsert(&Lb,-1,4);
        printf("Lb,status=%d\n",s1);
    }
    s = InitList(&Lc);
    if( s == 1 )
    {
        s1 = ListInsert(&Lc,10,4);
        printf("Lc,status=%d\n",s1);
    }
    return 0;
}
/**
 * 算法2.8测试函数
 */
int algo_2_8_main()
{
    LinkedList L;
    Status s,s1;
    int j,e;
    s = InitList(&L);
    if( s == 1 )
        for(j = 1;j <= 5;j++)
            ListInsert(&L,j,j*2);
    ListTraverse(L,visit);
    // 合法的位置参数i=2
    s1 = GetElem(L,2,&e);
    if( s1 == 1 )
        printf("Elem at place 2 is %d\n",e);
    else
        printf("wrong param..\n");
    // 非法的位置参数i=10
    s1 = GetElem(L,10,&e);
    if( s1 == 1 )
        printf("Elem at place 10 is %d\n",e);
    else
        printf("wrong param..\n");
        s1 = GetElem(L,10,&e);
    // 非法的位置参数i=-2
    s1 = GetElem(L,-2,&e);
    if( s1 == 1 )
        printf("Elem at place 10 is %d\n",e);
    else
        printf("wrong param..\n");
    return 0;
}
/**
 * 算法2.10测试函数
 */
int algo_2_10_main()
{
    LinkedList L;
    Status s,s1;
    int j,e;
    s = InitList(&L);
    if( s == 1 )
        for(j = 1;j <= 5;j++)
            ListInsert(&L,j,j * 2);
    ListTraverse(L,visit);
    // 非法的位置参数i=-1
    s1 = ListDelete(&L,-1,&e);
    if( s1 == 1 )
    {
        printf("elem deleted is %d\n",e);
        ListTraverse(L,visit);
    }
    else
        printf("wrong..\n");
    // 非法的位置参数i=10
    s1 = ListDelete(&L,10,&e);
    if( s1 == 1 )
    {
        printf("elem deleted is %d\n",e);
        ListTraverse(L,visit);
    }
    else
        printf("wrong..\n");
    // 合法的位置参数i=3
    s1 = ListDelete(&L,3,&e);
    if( s1 == 1 )
    {
        printf("elem deleted is %d\n",e);
        ListTraverse(L,visit);
    }
    else
        printf("wrong..\n");
    return 0;
}
/**
 * 算法2.11测试函数
 */
int algo_2_11_main()
{
    LinkedList L;
    Status s;
    s = CreateList(&L,5);
    if( s == 1 )
        ListTraverse(L,visit);
    return 0;
}
int algo_2_11_main2()
{
    LinkedList L;
    Status s;
    s = CreateList2(&L,5);
    if( s == 1 )
        ListTraverse(L,visit);
    return 0;
}
/**
 * 算法2.12 测试函数
 */
int algo_2_12_main()
{
    LinkedList La,Lb,Lc;
    Status s;
    int j;
    s = InitList(&La);
    if( s == 1 )
        for(j = 1;j <= 5;j++)
            ListInsert(&La,j,j);
    ListTraverse(La,visit);
    s = InitList(&Lb);
    if( s == 1 )
        for(j = 1;j <= 5;j++)
            ListInsert(&Lb,j,j * 2);
    ListTraverse(Lb,visit);
//    s = InitList(&Lc);
    MergeList(&La,&Lb,&Lc);
    printf("La addr=%p\n",&La);
    printf("La=");
    ListTraverse(La,visit);
    printf("Lc addr=%p\n",&Lc);
    printf("Lc=");
    ListTraverse(Lc,visit);
    return 0;
}
int test()
{
   LinkedList * La,* Lb;
   LinkedList Lc;
   MergeList(La,Lb,&Lc);
   return 0;
}
int main()
{
//    algo_2_9_main();
//    algo_2_8_main();
//    algo_2_10_main();
//    algo_2_11_main();
    algo_2_12_main();
    return 0;
}









































