#include "common.h"

typedef struct BiTNode{
    TElemType data;
    struct BiTNode * lchild,* rchild; // 左、右孩子指针
} BiTNode, * BiTree;

Status InitBiTree(BiTree * );
Status CreateBiTree(BiTree *);
