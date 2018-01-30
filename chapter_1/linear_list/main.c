#include <stdio.h>
#include <stdlib.h>
#include "sequence_list.h"

/**
 * ��ListTraverse()ʹ�ã���ӡ���Ա����洢������
 */
void print(ElemType * e)
{
    printf("%d",*e);
}
/**
 * �㷨2.1�Ĳ��Ժ���
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
 * �㷨 2.2 �Ĳ��Ժ���
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
 * �㷨2.3 ���Ժ���
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
 * �㷨2.4 ���Ժ���
 */
int algo_2_4_main()
{
    SqList L;
    Status s = InitList(&L);
    if( s != 1 )
        exit(ERROR);
    ListInsert(&L,1,2);
    printf("L����=%d\n",L.length);
    printf("LԪ�ذ�����\n");
    ListTraverse(L,print);
    ListInsert(&L,2,4);
    printf("L����=%d\n",L.length);
    printf("LԪ�ذ�����\n");
    ListTraverse(L,print);
    return OK;
}
/**
 * �㷨2.5 ���Ժ���
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
    printf("ɾ�������Ա�Ϊ��\n");
    ListTraverse(L,print);
    printf("��ɾ��Ԫ����%d",e);
    return OK;
}
int main()
{
//    algo_2_1_main();
//    algo_2_2_main();
//    algo_2_3_main();
//    algo_2_4_main();
    algo_2_5_main();
    return 0;
}
