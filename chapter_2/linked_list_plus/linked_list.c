#include "common.h"
#include "linked_list.h"

/**
 * 构造一个空的线性链表
 */
Status InitList(LinkedList * L)
{
    Link p;
    p = (Link)malloc( sizeof(LNode) ); // 生成头结点
    if(p)
    {
        p -> next = NULL;
        (*L).head = (*L).tail = p;
        (*L).len = 0;
        return OK;
    }
    else
        return ERROR;
}
/**
 * 算法2.20
 * 在带头结点的单链线性表L的第i个元素之前插入元素e
 */
Status ListInsert(LinkedList * L,int i,ElemType e)
{
    Link h,s;
    if( !LocatePos(*L,i-1,&h) )
        return ERROR; // i值不合法
    if( !MakeNode(&s,e))
        return ERROR; // 结点分配失败
    InsFirst(L,h,s); // ????对于从第i个结点开始的链表，第i-1个结点是它的头结点
    return OK;
}
/**
 * ？？？？？ 这个函数的功能描述要自己再改改，现在看不明白
 * 返回p指示线性链表L中第i个结点的位置，并返回OK，i值不合法时返回ERROR
 * i=0为头结点
 */
Status LocatePos(LinkedList L,int i,Link *p)
{
    int j;
    if( i < 0 || i > L.len )
        return ERROR;
    else
    {
        *p = L.head; // ?????L.head就是一个指向头结点的指针了，那么p就是指向指针的指针？不应该时p = L.head吗？？
        for(j=1;j<=i;j++)
            *p = (*p) -> next;
        return OK;
    }
}
/**
 * 分配由p指向的值为e的结点，并返回OK；若分配直白，则返回ERROR
 */
Status MakeNode(Link * p,ElemType e)
{
    *p = (Link)malloc( sizeof(LNode) );
    if( !*p )
        return ERROR;
    (*p) -> data = e;
    return OK;
}
/**
 * ？？？？？这个函数时在干嘛？？？？？为什么不在ListInsert()内部做好这些事？
 * 形参增加L，因为需修改L
 * h指向L的一个结点，把h当做头结点，将s所指结点插入在第一个结点之前
 */
Status InsFirst(LinkedList * L,Link h,Link s)
{
    s -> next = h -> next;
    h -> next = s;
    if( h == (*L).tail ) // h指向尾结点
        (*L).tail = h -> next; // 修改尾指针
    (*L).len++;
    return OK;
}
/**
 * 依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败
 */
Status ListTraverse(LinkedList L,void (*visit)(ElemType))
{
    Link p = L.head -> next;
    int j;
    for(j=1;j<=L.len;j++)
    {
        visit(p -> data);
        p = p -> next;
    }
    printf("\n");
    return OK;
}
/**
 * 比较两个整型的大小，将结果返回。此函数供其他函数调用，例如MergeList()。
 */
int compare(ElemType c1,ElemType c2)
{
    return c1 - c2;
}
/**
 * 算法2.21
 * 已知单链线性表La和Lb的元素按值非递减排列。归并La和Lb得到新的单链
 * 线性表Lc，Lc的元素也按值非递减排列。（不改变La，Lb）
 */
Status MergeList(LinkedList La,LinkedList Lb,LinkedList * Lc,int (*compoare)(ElemType,ElemType))
{
    Link ha,hb,pa,pb,q;
    ElemType a,b;
    if( !InitList(Lc) )
        return ERROR; // 存储空间分配失败
    ha = GetHead(La); // ha和hb分别指向La和Lb的头结点
    hb = GetHead(Lb);
    pa = NextPos(ha); // pa和pb分别指向La和Lb的第一个结点
    pb = NextPos(hb);
    while( !ListEmpty(La) && !ListEmpty(Lb) )
    {
        a = GetCurElem(pa); // a和b为链表中当前比较元素
        b = GetCurElem(pb);
        if( compare(a,b) < 0 )  // ？？？？？这里时和MergeList()使用的同一个compare()吗？？？？？
        {
            DelFirst(&Lb,ha,&q);
            InsFirst(Lc,(*Lc).tail,q);
            pa = NextPos(ha);
        }
        else // a > b
        {
            DelFirst(&Lb,hb,&q);
            InsFirst(Lc,(*Lc).tail,q);
            pb = NextPos(hb);
        }
    }
    if( !ListEmpty(La) )
        Append(Lc,pa);
    else
        Append(Lc,pb);
    FreeNode(&ha);
    FreeNode(&hb);
    return OK;
}
/**
 * 返回线性链表L中头结点的位置
 */
Position GetHead(LinkedList L)
{
    return L.head;
}
/**
 * 已知p指向线性链表L中的一个结点，返回p所指结点的直接后继的位置
 * 若无后继，则返回NULL
 */
Position NextPos(Link p)
{
    return p -> next;
}
/**
 * 若线性链表L为空表，则返回TRUE，否则返回FALSE
 */
Status ListEmpty(LinkedList L)
{
    if( L.len )
        return FALSE;
    else
        return TRUE;
}
/**
 * 已知p指向线性链表中的一个结点，返回p所指结点中数据元素的值
 */
ElemType GetCurElem(Link p)
{
    return p -> data;
}
/**
 * 形参增加L，因为需修改L
 * h指向L的一个结点，把h当做头结点，删除链表中的第一个结点并以q返回。
 * 若链表为空（h指向尾结点），q=NULL，返回FALSE
 */
Status DelFirst(LinkedList * L,Link h,Link * q)
{
    *q = h -> next;
    if(*q) // 链表非空
    {
        h -> next = (*q) -> next;
        if( !h -> next ) // 删除尾结点
            (*L).tail = h; // 修改尾指针
        (*L).len--;
        return OK;
    }
    else
        return FALSE; // 链表空
}
/**
 * 将指针s(s -> data为第一个数据元素)所指（彼此以指针相链，以NULL结尾）的
 * 一串结点链接在线性链表L的最后一个结点之后，并改变链表L的尾指针指向新的尾结点
 */
Status Append(LinkedList * L,Link s)
{
     int i = 1;
     (*L).tail -> next = s;
     while( s -> next )
     {
        s = s -> next;
        i++;
     }
     (*L).tail = s;
     (*L).len += i;
     return OK;
}
/**
 * 释放p所指结点
 */
void FreeNode(Link * p)
{
    free(*p);
    *p = NULL;
}
/**
 * 销毁线性链表L，L不在存在
 */
Status DestroyList(LinkedList * L)
{
    ClearList(L); //  清空链表
    FreeNode( &(*L).head );
    (*L).tail = NULL;
    (*L).len = 0;
    return OK;
}
/**
 * 将线性链表L重置为空表，并释放原链表的结点空间
 */
Status ClearList(LinkedList * L)
{
    Link p,q;
    if( (*L).head != (*L).tail ) // 不是空表
    {
        p = q = (*L).head -> next;
        (*L).head -> next = NULL;
        while( p != (*L).tail )
        {
            p = q -> next;
            free(q);
            q = p;
        }
        free(q);
        (*L).tail = (*L).head;
        (*L).len = 0;
    }
    return OK;
}
