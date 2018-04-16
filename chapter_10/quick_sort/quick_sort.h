#ifndef _QUICK_SORT_H_
#define _QUICK_SORT_H_

#define MAXSIZE 20
#include "common.h"

typedef int KeyType;
typedef int InfoType;

typedef struct {
    KeyType key;
    InfoType info;
} RedType;

typedef struct {
    RedType r[MAXSIZE + 1];
    int length;
} SqList;

void PrintListKeys(SqList);
void QuickSort(SqList *);
#endif
