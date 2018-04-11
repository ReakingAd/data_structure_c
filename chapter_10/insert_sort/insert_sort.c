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
    for( i=2;i<=L -> length;++i) // 从第二个元素开始循环。第0个元素哨兵位，负责比较大小，并不参加排序。
    {
        if( LT(L -> r[i].key,L -> r[i-1].key) ) // 比较已排好的序列的最后两个元素。如果r[i]>r[i-1]则不用动。如果r[i]<=r[i-1]则想办法将r[i]插入到对的位置
        {
            L -> r[0] = L -> r[i]; // 先保存r[i]的值到哨兵位，作为后边判断的标准
            L -> r[i] = L -> r[i-1]; // 将r[i-1]后移一位，至已排好序列的最末位。此时序列中就已空出一个位置了。但是r[i]要不要插入到这个位置，还要经下边的for循环决定
            for( j=i-2;LT(L -> r[0].key,L -> r[j].key);--j ) // 在已排好的序列中，从倒数第3个元素开始，依次与哨兵比较大小，如果大于哨兵，则后移一位。正好填补上r[i-1]及其他前辈后移所留下的空隙。
                L -> r[j+1] = L -> r[j];
            L -> r[j+1] = L -> r[0]; // 直到遇到第一个r[j]<=哨兵的元素。此时位置j+1就应该是哨兵所要找的位置，插入即可
        }
    }
}
/**
 * 算法10.2 折半插入排序
 */
void BInsertSort(SqList * L)
{
    int i;
    for(i=2;i<=L -> length;i++)
    {
        int low,high,mid,j;
        L -> r[0] = L -> r[i];
        low = 1;
        high = i -1;
        while( low <= high )
        {

            mid = ( low + high ) / 2; // ?? 为什么这里自动转换成了整数？？？？？效果是直接去掉小数部分
            if( LT(L -> r[0].key ,L -> r[mid].key ) )   // 在低半区
            {
                high = mid - 1;
            }
            else low = mid + 1;

        }

        for(j=i-1;j>=high + 1;--j)
        {
            L -> r[j+1] = L -> r[j]; // 记录后移
        }
        L -> r[high + 1] = L -> r[0];

    }
}
