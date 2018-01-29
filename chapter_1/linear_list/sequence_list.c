#include "common.h"
#include "sequence_list.h"

/**
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
 * 在顺序线性表的指定个位置，插入一个新结点
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
    q = (L -> elem) + i - 1; // 要插入新结点的位置
    for( p = (L -> elem) + (L -> length) - 1 ;p >= q;p-- )
    {
        *(p + 1) = *p;
    }
    *q = e;
    (L -> length)++;
    return OK;
}
/**
 * 遍历顺序线性表，对每一个结点调用函数vi
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
