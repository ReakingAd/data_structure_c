#include "merge_sort.h"

void PrintKeys(SqList L)
{
    int i;
    for(i=0;i<L.length-1;i++)
        printf("%d,",L.r[i].key);
    printf("%d",L.r[i].key);
    printf("\n");
}
/**
 * 将有序的SR[i...m]和SR[m+1,n]归并为有序的TR[i...n]
 */
void Merge(RecType SR[],RecType TR[],int i,int m,int n)
{
    int j,k;
    j = m+1; // SR的后半段子序列的起始指针。前半段的起始指针为i
    k = i; // TR的起始指针也从第i个位置开始
    for(; i <= m && j <= n ;k++)
    {
        if( SR[i].key < TR[j].key )
            TR[k] = SR[i++];
        else
            TR[k] = TR[j++];
    }
    if(i <= m )
    {
        for(;i<=m;k++)
            TR[k] = SR[i++];
    }
    if( j <= n )
    {
        for(;j<=n;k++)
            TR[k] = SR[j++];
    }
}

/**
 * 将SR[s...t]归并排序为TR1[s...t]
 */
void MSort(RecType SR[],RecType TR1[],int s,int t)
{
    int m;
    RecType TR2[];
    if( s == t )
        TR1[s] = SR[s];
    else
    {
        m = (s + t) / 2;
        MSort(SR,TR2,s,m);
        MSort(SR,TR2,m+1,t);
        Merge(TR2,TR1,s,m,t);
    }
}
void MergeSort(SqList * L )
{
    MSort(L.r,L.r,1,L.length);
}
