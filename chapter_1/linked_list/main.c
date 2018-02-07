#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"

int main()
{
    Status s;
    int j;
    LinkedList L;
    s = InitList(&L);
    printf("%d\n",s);
    if( s == 1 )
        for(j=1;j<=5;j++)
            ListInsert(L,j,j);
//    ListInsert(L,1,1);
//    printf("data=%d\n",L -> next -> data);
    ListTraverse(L,visit);
    return 0;
}
