#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.h"

/**
 * 算法2.1
 * 合并两个顺序线性表La，Lb。将Lb中存在、La中不存在的结点，插入到La的末尾
 */
void Union(SqList * La,SqList Lb)
{
    int i;
    int La_len = ListLength(*La);
    int Lb_len = ListLength(Lb);
    ElemType e;
    for( i = 1;i <= Lb_len;i++ )
    {
        GetElem(Lb,i,&e);
        if( !LocateElem(*La,e,equal) )
            ListInsert(La,++La_len,e);
    }
}
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
int main()
{
//    algo_2_1_main();
    algo_2_2_main();
    return 0;
}
