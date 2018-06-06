#ifndef _BITREE_H_
#define _BITREE_H_

#include "common2.h"

typedef struct BiTNode{
    TElemType data;
    struct BiTNode * lchild,* rchild; // 左、右孩子指针
} BiTNode, * BiTree;

Status InitBiTree(BiTree * );
void CreateBiTree(BiTree *);
void PreOrder(BiTree);
void InOrder(BiTree);
void InOrder2(BiTree);
void PostOrder(BiTree);

#endif // _BITREE_H_
