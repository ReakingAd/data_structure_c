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
#endif

