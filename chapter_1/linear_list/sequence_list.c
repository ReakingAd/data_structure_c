#include "common.h"
#include "sequence_list.h"

/**
 * 算法2.3
 * 初始化一个空的顺序线性表
 */
Status InitList(SqList * L)
{
    L -> elem = (ElemType *) malloc( sizeof(ElemType) * LIST_INIT_SIZE );
    if( L -> elem == NULL )
        exit(OVERFLOW);
    L -> length = 0;
    L -> listsize = LIST_INIT_SIZE;
    return OK;
}
/**
 * 算法2.4
 * 在顺序线性表的指定个位置，插入一个新元素
 */
Status ListInsert(SqList * L,int i,ElemType e)
{
    ElemType * newbase = NULL ,* p = NULL ,*q = NULL;
    if( i < 1 || i > L -> length + 1 )
        exit(ERROR);
    if( L -> length >= L -> listsize ) // 如果当前线性表的长度已经达到了最大长度,则重新分配内存
    {
        newbase = (ElemType *)realloc( L -> elem,sizeof(ElemType) * ( (L -> length) + LISTINCREMENT) );
        if( newbase == NULL )
            exit(OVERFLOW);
        L -> listsize += LISTINCREMENT;
    }
    q = (L -> elem) + i - 1; // 要插入新元素的位置
    for( p = (L -> elem) + (L -> length) - 1 ;p >= q;p-- )
    {
        *(p + 1) = *p;
    }
    *q = e;
    (L -> length)++;
    return OK;
}
/**
 * 遍历顺序线性表，对每一个元素调用函数vi
 */
Status ListTraverse(SqList L,void (*vi)(ElemType *))
{
    ElemType * p = L.elem;
    int i;
    for(i = 1;i <= L.length;i++)
    {
        vi(p++);
    }
    printf("\n");
    return OK;
}
/**
 * 返回顺序线性表L的长度
 */
int ListLength(SqList L)
{
    return L.length;
}
/**
 * 获取顺序线性表指定位置上的数据
 */
Status GetElem(SqList L,int i,ElemType * e)
{
    if( i < 1 || i > L.length + 1 )
        exit(ERROR);
    *e = *(L.elem + i - 1);
    return OK;
}
/**
 * 算法2.6
 * 获取执行数据在线性表中的存储位置。如果不存在则返回0
 */
int LocateElem(SqList L,ElemType e,Status (*compare)(ElemType,ElemType))
{
    int i ;
    ElemType * p = NULL;
    p = L.elem;
    for( i = 1;i <= L.length;i++ )
    {
        if( compare(e,*p++) )
        {
            return i;
        }
    }
    return 0;
}
/**
 * 供LocateElem()使用。
 */
Status equal(ElemType e1,ElemType e2)
{
    if( e1 == e2 )
        return TRUE;
    else
        return FALSE;
}

/**
 * 算法2.1
 * 合并两个顺序线性表La，Lb。将Lb中存在、La中不存在的元素，插入到La的末尾
 */
void Union(SqList * La,SqList Lb)
{
    int i;
    int La_len = ListLength(*La);
    int Lb_len = ListLength(Lb);
    ElemType e;
    for( i = 1;i <= Lb_len;i++ )
    {
        GetElem(Lb,i,&e);
        if( !LocateElem(*La,e,equal) )
            ListInsert(La,++La_len,e);
    }
}
/**
 * 算法2.2
 * 已知：线性表LA，LB中的元素按值非递减有序排列。
 * 操作结果：将LA，LB中的元素归并到新的线性表LC中，且元素仍然按值非递减排列
 */
void MergeList(SqList La,SqList Lb,SqList * Lc)
{
    Status s = InitList(Lc);
    if( s != 1 )
        exit(ERROR);
    int i = 1,j = 1;
    int k = 1;
    ElemType ai,bj;
    while( i <= La.length && j <= Lb.length )
    {
        GetElem(La,i,&ai);
        GetElem(Lb,j,&bj);
        if( ai <= bj )
        {
            ListInsert(Lc,k++,ai);
            i++;
        }
        else
        {
            ListInsert(Lc,k++,bj);
            j++;
        }
    }
    while( i <= La.length )
    {
        GetElem(La,i,&ai);
        ListInsert(Lc,k++,ai);
        i++;
    }
    while( j <= Lb.length )
    {
        GetElem(Lb,j,&bj);
        ListInsert(Lc,k++,bj);
        j++;
    }
}
/**
 * 算法2.5
 * 删除先行表L中的第i个元素，并把被删除的元素存入参数e
 */
Status ListDelete(SqList * L,int i,ElemType * e)
{
    if( i < 1 || i > L -> length )
        exit(OVERFLOW);
    ElemType * p = NULL,* q = NULL;
    p = L -> elem;
    q = p + i - 1; // 指针，指向要被删除的元素的
    *e = *q;
    for(++q;q <= p + L -> length - 1;q++)
        *(q-1) = *q;
    L -> length--;
    return OK;
}
