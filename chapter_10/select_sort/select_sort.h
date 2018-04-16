#ifndef _SELECT_SORT_H_
#define _SELECT_SORT_H_

#include "common.h"
#define MAXSIZE 20

typedef int KeyType;
typedef int InfoType;
typedef struct{
    KeyType key;
    InfoType info;
} RecType; // rec是record的缩写

typedef struct{
    RecType r[MAXSIZE + 1];
    int length;
} SqList;

typedef SqList HeapType;

void PrintKeys(SqList);
void SelectSort(SqList *);
int LT(RecType,RecType);
void HeapSort(SqList *);
#endif
