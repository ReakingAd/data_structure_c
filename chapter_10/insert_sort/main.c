#include <stdio.h>
#include <stdlib.h>
#include "insert_sort.h"

void main_algo_10_1()
{
    printf("initializision...\n");
    SqList L;
    L.r[1].key = 49;
    L.r[2].key = 38;
    L.r[3].key = 65;
    L.r[4].key = 97;
    L.r[5].key = 76;
    L.r[6].key = 13;
    L.r[7].key = 27;
    L.r[8].key = 99;
    L.length = 8;
    // ===============
    PrintListKeys(L);
    InsertSort(&L);
    PrintListKeys(L);
}

void main_algo_10_2()
{
    printf("initializision...\n");
    SqList L;
    L.r[1].key = 49;
    L.r[2].key = 38;
    L.r[3].key = 65;
    L.r[4].key = 97;
    L.r[5].key = 76;
    L.r[6].key = 13;
    L.r[7].key = 27;
    L.r[8].key = 99;
    L.length = 8;
    // ===============
    PrintListKeys(L);
    BInsertSort(&L);
    PrintListKeys(L);
}
int main()
{
//    main_algo_10_1();
    main_algo_10_2();
    return 0;
}
