#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "slinked_list.h"

//int main_test()
//{
//    SLinkedList s = {
//        {"",1},{"ZHAO",2},{"QIAN",3},{"SUN",4},{"LI",5},{"ZHOU",6},{"WU",7},{"ZHENG",8},{"WANG",0}
//    };
//    int i;
//    i = s[0].cur;
//
//    while(i)
//    {
//        printf("%s--",s[i].data);
//        i = s[i].cur;
//    }
//    printf("\n");
//    s[9].cur = 5;
//    s[4].cur = 9;
//    strcpy(s[9].data,"SHI");
//    s[6].cur = 8;
//    i = s[0].cur;
//    while(i)
//    {
//        printf("%s--",s[i].data);
//        i = s[i].cur;
//    }
//    printf("\n");
//    return 0;
//}

void visit(ElemType c)
{
    printf("%c",c);
}
int algo_2_17_main()
{
    int k;
    SLinkedList s;
    difference(s,&k);
    printf("合并后为：\n");
    ListTraverse(s,k,visit);
    return 0;
}
int main()
{
//    main_test();
    algo_2_17_main();
    return 0;
}
