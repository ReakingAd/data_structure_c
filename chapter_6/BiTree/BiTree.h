#ifndef _BITREE_H_
#define _BITREE_H_

#include "common2.h"

typedef struct BiTNode{
    char data;
    struct BiTNode * lchild,* rchild; // 左、右孩子指针
} BiTNode, * BiTree;

Status InitBiTree(BiTree * );
void CreateBiTree(BiTree *);
void PreOrder(BiTree);
void PreOrder2(BiTree);
void InOrder(BiTree);
void InOrder2(BiTree);
void PostOrder(BiTree);
void PostOrder2(BiTree);
void LevelOrder(BiTree);

#endif // _BITREE_H_
