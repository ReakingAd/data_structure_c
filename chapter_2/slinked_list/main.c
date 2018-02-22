#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"
#include "slinked_list.h"

int main()
{
    SLinkedList s = {{"",1},{"ZHAO",2},{"QIAN",3},{"SUN",4},{"LI",5},{"ZHOU",6},{"WU",7},{"ZHENG",8},{"WANG",0}}; // 解构赋值？？？？？
    int i;
    i = s[0].cur;
    while(i) // 输出图2.10a的状态
    {
        printf("%s--",s[i].data); // 输出链表的当前值
        i = s[i].cur; // 找到下一个
    }
    printf("\n");
    s[4].cur = 9; // 修改
    s[6].cur = 8;
    s[9].cur = 5;
    strcpy( s[9].data,"SHI" );
    i = s[0].cur;
    while(i)
    {
        printf("%s--",s[i].data);
        i = s[i].cur;
    }
    printf("\n");
    return 0;
}
