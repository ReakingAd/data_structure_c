#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"

int comp(ElemType c1,ElemType c2)
{
    return c1 - c2;
}
void visit(ElemType c)
{
    printf("%d",c); // 整型
}
int main()
{
    LinkedList La,Lb,Lc;
    int j;
    Status k = InitList(&La);
    for(j=1;j<=5;j++)
        ListInsert(&La,j,j); // 顺序插入1,2,3,4,5
    printf("La=");
    ListTraverse(La,visit);
    InitList(&Lb);
    for(j=1;j<=5;j++)
        ListInsert(&Lb,j,2*j); // 顺序插入2.4.6.8.10
    printf("Lb=");
    ListTraverse(Lb,visit);
    InitList(&Lc);
    MergeList(La,Lb,&Lc,comp); // 归并La和Lb，产生Lc
    printf("Lc=");
    ListTraverse(Lc,visit);
    DestroyList(&Lc);
    return 0;
}
