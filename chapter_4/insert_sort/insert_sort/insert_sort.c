#include "insert_sort.h"

void PrintListKeys(SqList L)
{
    int i;
    for(i=1;i<=L.length;i++)
    {
        printf("%d",L.r[i].key);
        if( i != L.length )
            printf(",");
    }
    printf("\n");
}

Status LT(KeyType a,KeyType b)
{
    if( a< b )
        return TRUE;
    else
        return FALSE;
}
/**
 * 算法10.1 直接插入排序
 */
void InsertSort(SqList * L)
{
    int i,j;
    for( i=2;i<=L -> length;++i)
    {
        if( LT(L -> r[i].key,L -> r[i-1].key) )
        {
            L -> r[0] = L -> r[i];
            L -> r[i] = L -> r[i-1];
            for( j=i-2;LT(L -> r[0].key,L -> r[j].key);--j )
                L -> r[j+1] = L -> r[j];
            L -> r[j+1] = L -> r[0];
        }
    }
}
