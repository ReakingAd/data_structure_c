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
void Merge(RecType SR[],RecType * TR[],int i,int m,int n)
{

}
