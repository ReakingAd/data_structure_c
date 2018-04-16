#include "select_sort.h"

void PrintKeys(SqList L)
{
    int i;
    for(i=0;i<L.length-1;i++)
    {
        printf("%d,",L.r[i].key);
    }
    printf("%d",L.r[i].key);
    printf("\n");
}
int LT(RecType a,RecType b)
{
    if( a.key< b.key )
        return TRUE;
    else
        return FALSE;
}
/**
 * 算法10.9 简单选择排序
 */
void SelectSort(SqList * L)
{
    int i,j,temp;
    for(i=0;i<L->length;i++)
    {
        for(j=i+1;j<L->length;j++)
        {
            if( LT(L -> r[j],L -> r[i]) )
            {
                temp = L -> r[i].key;
                L -> r[i].key = L -> r[j].key;
                L -> r[j].key = temp;
            }
        }
    }
}

/**
 * 算法10.10  一次“筛选”操作
 * 已知H.r[s...m]中记录的关键字除H.r[s].key外，均满足堆的定义。本函数调整H.r[s]的关键字，使
 * H.r[s...m]成为一个大顶堆
 */
void HeapAdjust(HeapType * H,int s,int m)
{
    RecType rc = H -> r[s];
    int j;
    for(j=2*s;j<=m;j*=2) // 沿key较大的孩子结点向下筛选。（对于完全二叉树，结点n的左子树的序号是2n）
    {
        if(j<m && LT(H -> r[j],H -> r[j+1]) )
            ++j; // j为key较大的记录的下标
        if( !LT(rc,H -> r[j]) )
            break; // rc应插入在位置s上
        H -> r[s] = H -> r[j];
        s = j;
    }
    H -> r[s] = rc; // 插入
}
void HeapSort(SqList * H)
{
    int i;
    int temp;
    for(i=H -> length/2;i>0;--i) // 由堆的定义，从Math.floor(n/2)处的元素开始进行“筛选”
    {
        HeapAdjust(H,i,H -> length);
    }
    for(i=H -> length;i>1;--i)
    {
//        H.r[1]与H.r[i]对换。将堆顶记录和当前未经排序子序列H.r[1...i]中最后一个记录互相交换
        temp = H -> r[1].key;
        H -> r[i].key = temp;
        HeapAdjust(H,1,i-1);
    }
}
