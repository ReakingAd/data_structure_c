#include "BiTree.h"
//#include "../../chapter_3/stack/stack.h"
#include "chapter_3/stack/stack.h"

Status InitBiTree(BiTree * T){
    *T = NULL;
    return 1;
}

/**
 * 算法6.4
 * 先序序列建立二叉树.使用字符#表示空子树。
 */
void CreateBiTree(BiTree * T){
    char ch;
    scanf("%c%*c",&ch); // %*c是用来读入多余的回车符
//    scanf(" %c",&ch); // 另一种好用的方法。即%c前面加一个空格
    if( ch == '#' ){
        *T = NULL;
    }
    else{
        *T = (BiTNode *) malloc( sizeof(BiTNode) );
        if( *T == NULL )
            exit(OVERFLOW);
        (*T) -> data = ch;
        CreateBiTree( &(*T) -> lchild );
        CreateBiTree( &(*T) -> rchild );
    }
}
void visit( BiTNode * p){
    printf("%c",p -> data);
}
/**
 * 算法 6.1
 * 先序遍历递归算法
 */
void PreOrder(BiTree T){
    if( T != NULL ){
        visit(T);
        PreOrder(T -> lchild);
        PreOrder(T -> rchild);
    }
}
/**
 * 中序遍历递归算法
 */
 void InOrder(BiTree T){
    if( T != NULL){
        InOrder( T -> lchild );
        visit(T);
        InOrder( T -> rchild );
    }
 }

 /**
  * 中序遍历非递归算法
  */
 void InOrder2(BiTree T){
    SqStack S;
    Status s = InitStack(&S);
    BiTree p;
    while( T != NULL || !StackEmpty(S) ){
        if( T != NULL ){
            Push(&S,T);
            T = T -> lchild;
        }
        else{
            Pop(&S,&T);
            visit(T);
            T = T -> rchild;
        }
    }
 }
 /**
  * 后序遍历递归算法
  */
void PostOrder(BiTree T){
    if( T != NULL){
        PostOrder( T -> lchild );
        PostOrder( T -> rchild );
        visit( T );
    }
}
