#include "common.h"
#include "slinked_list.h"
/* 一个数组可生成若干个静态链表的基本操作（12个）*/
/**
 * 将一维数组L中各元素链成一个备用链表,L[0].cur为头指针。“0”表示空指针
 */
void InitSpace(SLinkedList L)
{
    int i;
    for(i = 0;i < MAXSIZE - 1;i++)
    {
        L[i].cur = i + 1;
    }
    L[MAXSIZE - 1].cur = 0;
};
/**
 * 一次输入集合A和B的元素，在一位数组space中建立表示集合(A-B)u(B-A)的静态链表，S为其头指针。假设备用空间足够大，space[0].cur为备用空间的头指针
 */
void difference(SLinkedList space,int *S)
{
    int m,n,i,j,r;
    ElemType b;
    InitSpace(space); // 初始化备用空间
    printf("请输入集合A和B的元素个数m,n");
    scanf("%d,%d",&m,&n); // ????? %*c 吃点回车符是怎么回事？？？？？
    printf("请输入集合A的元素（共%d个）",m);
    for(j=1;j<=m;j++) // 建立集合A的链表
    {
        scanf("%c",%b); // 输入A的元素值
        ListInsert(space,S,j,b); // 插入到表尾
    }
    scanf("%*c"); // 吃掉回车符
};
