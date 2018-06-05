#include "BiTree.h"

Status InitBiTree(BiTree * T){
    *T = NULL;
    return 1;
}

/**
 * 未完成....
 */
Status CreateBiTree(BiTree * T){
    char ch;
    scanf("%c",&ch);
    if( ch == '^' )
        T = NULL;
    else{
        *T = (BiTNode *) malloc( sizeof(BiTNode) );
        if( *T == NULL )
            exit(OVERFLOW);
        (*T) -> data = ch;
        (*T) -> lchild = NULL;
        (*T) -> rchild = NULL;
        CreateBiTree( &(*T) -> lchild );
        CreateBiTree( &(*T) -> rchild );
    }
    printf("=======\n");
    return 1;
}
