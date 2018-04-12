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
        /**
        * mid的计算方式可知，mid总是在中间偏向low方向一个位置。若干次循环后，mid便和low相等了，即mid=low。
        * 显然此时必须得有mid=low=high
        * 当循环low=high进行时，如果哨兵<mid则low=mid=high+1如果哨兵>mid则low-1=mid=high
        * 此时low > higt便跳出了while循环。
        */
        while( low <= high )
        {
            mid = ( low + high ) / 2; // 由于mid是行下取证得来，mid最终总会遇到与low相等的时候。
                                                        // 所以当某次执行玩high=m-1时，high就比low大了，便跳出while循环了。
            if( LT(L -> r[0].key ,L -> r[mid].key ) )   // 在低半区
                high = mid - 1;
            else
                low = mid + 1;
        }
        /**
        * 当进行low=high=mid这次循环时，如果哨兵<mid关键字，则可知哨兵应该插入到high左侧。
        * 但是由于调整了high=mid-1(即high指针左移了一个位置)所以哨兵就应该插入到调整后的high的右侧
        * 如果哨兵>mid关键字，此时哨兵应该插入high的右侧，由于调整的是low的位置而high并没有变。
        * 可见，不管最后一次low=high=mid时哨兵与mid关键字大小关系如何，正确的插入位置都是high的右侧紧邻。
        * 即high+1
        */
        for(j=i-1;j>=high + 1;--j)
        {
            L -> r[j+1] = L -> r[j]; // 记录后移
        }
        L -> r[high + 1] = L -> r[0]; // 插入到high+1位置

    }
}
