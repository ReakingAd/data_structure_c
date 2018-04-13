#include "quick_sort.h"

/**
 * 顺序打印线性表中各元素的关键字属性的值。即key值
 */
void PrintListKeys(SqList L)
{
    int i;
    for(i=0;i<L.length - 1;i++)
        printf("%d,",L.r[i].key);
    printf("%d\n",L.r[i].key);
}
/**
 * 算法10.6a  分割线性表L的指定子表（起点low终点high），分界点pivot。使pivot左侧的
 * 元素都小于pivotKey,右侧的元素都大于pivotKey。返回pivot
 * ×××本算法可以改进×××
 */
int Partition(SqList * L,int low,int high)
{
    int pivotKey;
    pivotKey = L -> r[ low ].key; // 第一个元素作为枢纽
    while( low < high )
    {
        while( low < high && L -> r[high].key >= pivotKey  ) // 此时low是枢纽指针
            --high;
        // high 和 pivot(也就是low)位置上的元素交换位置
        L -> r[low].key = L -> r[high].key;
        L -> r[high].key = pivotKey;
        while( low < high && L -> r[low].key <= pivotKey ) // 此时high是枢纽指针
            ++low;
        L -> r[high].key = L -> r[low].key;
        L -> r[low].key = pivotKey;
    }

    return low;
}

/**
 * 算法10.7 对线性表的指定子表进行快速排序
 * 对线性表L的子表（起点low终点high）进行快速排序。
 */
void QSort(SqList * L,int low,int high)
{
    if( low < high )
    {
        int pivot = Partition(L,low,high);
        QSort(L,low,pivot - 1);
        QSort(L,pivot+1,high);
    }
}
/**
 * 算法10.8 快速排序
 * 封装一下算法算法10.7，以方便调用。只需要传递待排序的表，而表长度的计算在本算法内进行。
 */
void QuickSort(SqList * L)
{
    QSort(L,0,L -> length - 1);
}
