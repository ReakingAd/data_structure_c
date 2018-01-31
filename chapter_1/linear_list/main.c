#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.h"

/**
 * 供ListTraverse()使用，打印线性表所存储的数据
 */
void print(ElemType * e)
{
    printf("%d",*e);
}
/**
 * 算法2.1的测试函数
 */
int algo_2_1_main()
{
    SqList La,Lb;
    Status i;
    int j;
    i = InitList(&La);
    if( i == 1 )
    {
        for(j = 1;j <= 5;j++)
            ListInsert(&La,j,j);
    }
    ListTraverse(La,print);
    i = InitList(&Lb);
    if( i == 1 )
    {
        for( j = 1;j <= 5;j++ )
        {
            ListInsert(&Lb,j,j * 2);
        }
    }
    ListTraverse(Lb,print);
    Union(&La,Lb);
    ListTraverse(La,print);
    return 0;
}
/**
 * 算法 2.2 的测试函数
 */
int algo_2_2_main()
{
    SqList La,Lb,Lc;
    Status s;
    int i;
    s = InitList(&La);
    if( s == 1 )
    {
        for(i = 1;i <= 5;i++)
            ListInsert(&La,i,i);
    }
    ListTraverse(La,print);
    s = InitList(&Lb);
    if( s == 1 )
    {
        for(i = 1;i <= 5;i++)
            ListInsert(&Lb,i,i * 2);
    }
    ListTraverse(Lb,print);
    s = InitList(&Lc);
    if( s != 1 )
        exit(ERROR);
    MergeList(La,Lb,&Lc);
    ListTraverse(Lc,print);
    return OK;
}
/**
 * 算法2.3 测试函数
 */
int algo_2_3_main()
{
    SqList L;
    Status s = InitList(&L);
    if( s == 1 )
        printf("Initialize success.\n");
    else
        printf("Initialize failed.\n");
    return OK;
}
/**
 * 算法2.4 测试函数
 */
int algo_2_4_main()
{
    SqList L;
    Status s = InitList(&L);
    if( s != 1 )
        exit(ERROR);
    ListInsert(&L,1,2);
    printf("L长度=%d\n",L.length);
    printf("L元素包括：\n");
    ListTraverse(L,print);
    ListInsert(&L,2,4);
    printf("L长度=%d\n",L.length);
    printf("L元素包括：\n");
    ListTraverse(L,print);
    return OK;
}
/**
 * 算法2.5 测试函数
 */
int algo_2_5_main()
{
    SqList L;
    Status s = InitList(&L);
    if( s != 1)
        exit(ERROR);
    int i;
    ElemType e;
    for( i = 1 ; i <= 5;i++ )
        ListInsert(&L,i,i);
    ListDelete(&L,2,&e);
    printf("删除后，线性表为：\n");
    ListTraverse(L,print);
    printf("被删除元素是%d",e);
    return OK;
}
/**
 * 算法2.6测试函数
 */
int algo_2_6_main()
{
    SqList L;
    Status s = InitList(&L);
    int j,pos;
    if( s == 1 )
    {
        for( j = 1;j <= 5;j++ )
            ListInsert(&L,j,j * 2);
    }
    printf("La=\n");
    ListTraverse(L,print);
    pos = LocateElem(L,4,equal);
    printf("position of %d = %d",4,pos);
    return OK;
}
int main()
{
//    algo_2_1_main();
//    algo_2_2_main();
//    algo_2_3_main();
//    algo_2_4_main();
//    algo_2_5_main();    algo_2_6_main();
    return 0;
}
