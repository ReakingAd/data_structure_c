#include "common.h"
#include "slinked_list.h"
#include "string.h"
/* 一个数组可生成若干个静态链表的基本操作（12个）*/
/**
 * 算法2.14
 * 将一维数组L中各元素链成一个备用链表,L[0].cur为头指针。“0”表示空指针
 * 相当于将数组的各个元素使用cur串起来形成链表。此时这个链表为备用链表。
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
 * 在备用链表中，剔除掉头结点所指向的结点。返回这个被剔除的结点在原数组中的
 * 下标，可当做“内存地址”使用。
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
 * 相当于，将原数组中k位置上的元素，插入到备用链表的第一个结点之后，供下一次Malloc()函数申请使用。
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
    *S = Malloc(space); // 生成S的头结点
    r = *S; // r指向S的当前最后结点 /* r指向最后一个被分配出来的“内存” */
    printf("请输入集合A和B的元素个数m,n\n");
    scanf("%d,%d%*c",&m,&n); // %*c 吃掉回车符。方法中多次用到这个写法。不吃掉回车符的话会影响程序的执行。还不明白回车符是怎么影响程序执行的。
    printf("请输入集合A的元素（共%d个）\n",m);
    for(j=1;j<=m;j++) // 建立集合A的链表
    {
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
        k = space[*S].cur; // k初始时指向集合A中的第一个结点。通过while循环移动k来遍历集合A，以判断新键入的字母是否在集合A中已经存在
        while( k != space[r].cur && space[k].data != b) // 修正k值
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
* 改进算法2.17
* 过程尽量使用基本操作来进行。
*/
int difference2(SLinkedList space)
{
    int m,n,i,j,k,S;
    ElemType b,c;
    InitSpace( space ); // 初始化备用空间
    S = InitList(space); // 生成链表S的头结点
    printf("请输入集合A和B的元素个数m,n:\n");
    scanf("%d,%d%*c",&m,&n);
    printf("请输入集合A的元素（共%d）个：\n",m);
    for(j=1;j<=m;j++)
    {
        scanf("%c%*c",&b);
        ListInsert(space,S,j,b); // 插入到表尾
    }
//    scanf("%*c"); // 吃掉回车符？？？？是否删掉就可以？？
    printf("请输入集合B的元素（共%d）个：\n",n);
    for(j=1;j<=n;j++) // 依次输入B的元素，若不在当前表中，则插入，否则删除
    {
            scanf("%c%*c",&b);
            k = LocateElem(space,S,b); // k为b的位序
            if(k) // b在当前表中
            {
                PriorElem(space,S,b,&c); // b的前驱为c
                i = LocateElem(space,S,c); // i为c的位序
                space[i].cur = space[k].cur; // 将k的指针域付给i的指针域
                Free(space,k); // 将下表为k的空闲结点回收到备用链表
            }
            else
            {
                ListInsert(space,S,ListLength(space,S) + 1,b); // 在表尾插入b
            }
    }
    return S;
}
void visit(ElemType c)
{
    printf("%c",c);
}
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
 /**
  * 构造一个空链表，返回值为空表在数组中的位序
  * (在原数组中申请一个单位的“内存”，作为新链表的头结点。这个头结点的位序作为返回值返回)
  */
int InitList(SLinkedList L)
{
    int i;
    i = Malloc(L); // 调用Malloc(),简化程序
    L[i].cur = 0;
    return i;
}
/**
 * 在L中表头位序为n的链表的第i个元素之前插入新的数据元素e
 */
Status ListInsert(SLinkedList L,int n,int i,ElemType e)
{
    int l,j,k=n; // k 指向表头
    if( i < 1 || i > ListLength(L,n) + 1)
        return ERROR;
    j = Malloc(L); // 申请新单元
    if(j) // 申请成功
    {
        L[j].data = e; // 赋值给新单元
        for(l=1;l<i;l++) // 移动i-1个元素
            k = L[k].cur;
        L[j].cur = L[k].cur;
        L[k].cur = j;
        return OK;
    }
    return ERROR;
}
/**
 * 返回L中表头位序为n的链表的数据元素个数
 */
int ListLength(SLinkedList L,int n)
{
    int j = 0,i=L[n].cur; // i 指向第一个元素
    while(i) // 遍历至静态链表尾
    {
        i = L[i].cur; // 指向下一个元素
        j++;
    }
    return j;
}
/**
 * 在L中表头位序为n的静态单链表中查找第1个值为e的元素。若
 * 找到，则返回它在L中的位序，否则返回0
 */
int LocateElem(SLinkedList L,int n,ElemType e)
{
    int i = L[n].cur; // i指向静态链表中的第一个结点
    while(i && L[i].data != e) // 在表中顺链查找（e不能时字符串）
        i = L[i].cur;
    return i;
}
/**
 * 若cur_e是此单链表的数据元素，且不是第一个，则用pre_e返回它的前驱，
 * 否则操作失败，pre_e无定义
 */
Status PriorElem(SLinkedList L,int n,ElemType cur_e,ElemType * pre_e)
{
    int j,i = L[n].cur; // i 为链表第一个结点的位置
    do // 向后移动结点
    {
            j = i;
            i = L[i].cur;
    }while( i && cur_e != L[i].data );
    if(i) // 找到该元素
    {
        *pre_e = L[j].data;
        return OK;
    }
    return ERROR;
}
