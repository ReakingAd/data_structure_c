#include <stdio.h>
#include <stdlib.h>
#include "quick_sort.h"

int main()
{
    SqList L;
    L.r[0].key = 49;
    L.r[1].key = 38;
    L.r[2].key = 65;
    L.r[3].key = 97;
    L.r[4].key = 76;
    L.r[5].key = 13;
    L.r[6].key = 27;
    L.r[7].key = 50;
    L.length = 8;
    PrintListKeys(L);
//    int i = Partition(&L,0,7);
//    printf("i=%d\n",i);
    QuickSort(&L);
    PrintListKeys(L);
    return 0;
}
