#include <stdio.h>
#include <stdlib.h>
#include "common.h"
#include "linked_list.h"

int algo_2_9_main()
{
Status s,s1;
    int j;
    LinkedList La,Lb,Lc;
    s = InitList(&La);
    if( s == 1 )
    {
        s1 = ListInsert2(La,1,4);
        printf("La,status=%d\n",s1);
        s1 = ListInsert(&La,2,9);
        printf("La,status=%d\n",s1);
    }
    ListTraverse(La,visit);
    s = InitList(&Lb);
    if( s == 1 )
    {
        s1 = ListInsert(&Lb,-1,4);
        printf("Lb,status=%d\n",s1);
    }
    s = InitList(&Lc);
    if( s == 1 )
    {
        s1 = ListInsert(&Lc,10,4);
        printf("Lc,status=%d\n",s1);
    }
    return 0;
}
int main()
{
    algo_2_9_main();
    return 0;
}
