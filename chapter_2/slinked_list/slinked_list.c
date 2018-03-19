#include "common.h"
#include "slinked_list.h"
#include "string.h"
/* 一个数组可生成若干个静态链表的基本操作（12个）*/
/**
 * 算法2.14
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
 * 算法2.15
 * 若备用链表非空，则返回分配的结点下标（备用链表的第一个结点），否则返回0
 */
int Malloc(SLinkedList space)
{
    int i = space[0].cur;
    if(i) // 备用链表非空
        space[0].cur = space[i].cur; // 备用链表的头结点指向原备用链表的第二个结点
    return i; // 返回新开辟结点的坐标
}
/**
 * 算法2.16
 * 将下标为k的空闲结点回收到备用链表（成为备用链表的第一个结点）
 */
void Free(SLinkedList space,int k)
{
    space[k].cur = space[0].cur; // 回收结点的“游标”指向备用链表的第一个结点
    space[0].cur = k;
}
/**
 * 算法2.17
 * 一次输入集合A和B的元素，在一位数组space中建立表示集合(A-B)u(B-A)的静态链表，S为其头指针。
 * 假设备用空间足够大，space[0].cur为备用空间的头指针
 */
void difference(SLinkedList space,int *S)
{
    int r,p,m,n,i,j,k;
    ElemType b;
    InitSpace(space); // 初始化备用空间
    *S = Malloc(space); // 生成s的头结点
    r = *S; // r指向S的当前最后结点
    printf("请输入集合A和B的元素个数m,n\n");
    scanf("%d,%d%*c",&m,&n); // %*c 吃掉回车符。方法中多次用到这个写法。不吃掉回车符的话会影响程序的执行。还不明白回车符是怎么影响程序执行的。
    printf("请输入集合A的元素（共%d个）\n",m);
    for(j=1;j<=m;j++) // 建立集合A的链表
    {
//        printf("in first loop==%d\n",j);
        i = Malloc(space); // 分配结点
        scanf("%c%*c",&space[i].data); // 输入A的元素值
        space[r].cur = i; // 插入到表尾
        r = i;
    }
    space[r].cur = 0; // 尾结点的指针为空
    printf("请输入集合B的元素（共%d个）:\n",n);
    for(j=1;j<=n;j++) // 依次输入B的元素，若不在当前表中，则插入，否则删除
    {
        scanf("%c%*c",&b);
        p = *S;
        k = space[*S].cur; // k指向集合A中的第一个结点
        while( k != space[r].cur && space[k].data != b)
        { // 在当前表中查找
            p = k;
            k = space[k].cur;
        }
        if( k == space[r].cur )
        { // 当前表中不存在该元素，插入在r所指结点之后，且r的位置不变
            i = Malloc(space);
            space[i].data = b;
            space[i].cur = space[r].cur;
            space[r].cur = i;
        }
        else // 该元素已在表中，删除之
        {
            space[p].cur = space[k].cur;
            Free(space,k);
            if( r == k )
                r = p; // 若删除的是尾元素，则需修改尾指针
        }
    }
};
 /**
  * 依次对L中表头位序为n的链表的每个数据元素，调用函数vi()。一旦vi()失败，则操作失败
  */
 Status ListTraverse(SLinkedList L,int n,void (*vi)(ElemType))
 {
    int i = L[n].cur; // 指向第一个元素
    while(i) // 没到静态链表尾
    {
        vi(L[i].data);
        i = L[i].cur; // 指向下一个元素
    }
    printf("\n");
    return OK;
 }
