#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"

int main()
{
//    printf("Hello world!\n");
    BiTree T = NULL;
    Status s = InitBiTree(&T);
    if( s )
        printf("SUCCESS\n");
    CreateBiTree(&T);
    return 0;
}
