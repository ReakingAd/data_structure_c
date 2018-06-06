#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

// 中序遍历算法测试
void InOrder_main(){
    BiTree T = NULL;
    // 按照教材中图6.8(b)的二叉树，需要依次键入ABC##DE#G##F###
    CreateBiTree(&T);
    printf("中序遍历为\n");
//    InOrder(T);
    InOrder2(T);
}

// 先序遍历算法测试
void PreOrder_main(){
    BiTree T = NULL;
    // 按照教材中图6.8(b)的二叉树，需要依次键入ABC##DE#G##F###
    CreateBiTree(&T);
    printf("先序遍历为:\n");
    PreOrder(T);
}

// 后序遍历算法测试
void PostOrder_main(){
    BiTree T = NULL;
    // 按照教材中图6.8(b)的二叉树，需要依次键入ABC##DE#G##F###
    CreateBiTree(&T);
    printf("后序遍历为:\n");
    PostOrder(T);
}
int main()
{
    InOrder_main();
//    PreOrder_main();
//    PostOrder_main();
    return 0;
}
