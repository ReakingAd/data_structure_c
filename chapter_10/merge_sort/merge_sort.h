#ifndef _MERGE_SORT_H_
#define _MERGE_SORT_H_

#define MAXSIZE 20
#include "common.h"

typedef int KeyType;
typedef int InfoType;
typedef struct {
    KeyType key;
    InfoType info;
}RecType;

typedef struct {
    RecType r[MAXSIZE + 1];
    int length;
} SqList;

void PrintKeys(SqList);
void Merge(RecType SR[],RecType TR[],int i,int m,int n);
void MSort(RecType SR[],RecType TR1[],int s,int t);
#endif

