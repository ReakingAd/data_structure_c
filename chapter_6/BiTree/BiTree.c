#include "BiTree.h"
//#include "../../chapter_3/stack/stack.h"
#include "chapter_3/stack/stack.h"
#include "chapter_3/queue/queue.h"

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
 * 先序遍历非递归算法
 */
void PreOrder2(BiTree T){
    SqStack S;
    Status s = InitStack(&S);
    if( !s )
        exit(OVERFLOW);
    while( T != NULL || !StackEmpty(S) ){
        if( T != NULL ){
            visit(T);
            Push(&S,T);
            T = T -> lchild;
        }
        else{
            Pop(&S,&T);
            T = T -> rchild;
        }
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
    if( !s )
        exit(OVERFLOW);
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

/**
 * 后序遍历非递归算法
 * 后序非递归相对于先序非递归、中序非递归都要复杂。需要分辨出，在访问栈顶元素时，是刚刚遍历玩左子树，还是左右子树都已经遍历完毕。
 * 借助一个记忆指针，记录最后一个visit()过的结点，如果栈顶元素的右子树根节点和这个记忆指针指向同一结点，则说明栈顶元素的左右子树
 * 都已经访问完毕。
 */
void PostOrder2(BiTree T){
    SqStack S;
    Status s = InitStack(&S);
    BiTree p = T; // 工作指针
    BiTree r; // 存放上一个visit()的结点
    if( !s )
        exit(OVERFLOW);
    while( p != NULL || !StackEmpty(S) ){
        if( p ){
            Push(&S,p);
            p = p -> lchild;
        }
        else{
            GetTop(S,&p);
            if( p -> rchild && p -> rchild != r ){
                p = p -> rchild;
                Push(&S,p);
                p = p -> lchild;
            }
            else{
                Pop(&S,&p);
                visit(p);
                r = p;
                p = NULL;
            }
        }
    }
}
/**
 * 层次遍历二叉树。自上而下，自左而右
 */
void LevelOrder( BiTree T ){
    LinkQueue Q;
    Status s = InitQueue(&Q);
    if( !s )
        exit(OVERFLOW);
    BiTree p;
    EnQueue(&Q,T);
    while( !QueueEmpty(Q) ){
        DeQueue(&Q,&p);
        visit(p);
        if( p -> lchild )
            EnQueue(&Q,p -> lchild);
        if( p -> rchild )
            EnQueue(&Q,p -> rchild);
    }
}
