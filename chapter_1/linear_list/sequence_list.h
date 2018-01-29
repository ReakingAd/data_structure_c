#ifndef SEQUENCE_LIST_H_
#define SEQUENCE_LIST_H_
#include "common.h"

typedef struct
{
    ElemType * elem;
    int length;
    int listsize;
} SqList;

Status InitList(SqList * L,int i);

#endif // SEQUENCE_LIST_H_
