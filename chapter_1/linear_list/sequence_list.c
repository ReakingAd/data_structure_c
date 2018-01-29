#include "common.h"
#include "sequence_list.h"

/**
 * ��ʼ��һ���յ�˳�����Ա�
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
 * ��˳�����Ա��ָ����λ�ã�����һ���½��
 */
Status ListInsert(SqList * L,int i,ElemType e)
{
    ElemType * newbase = NULL ,* p = NULL ,*q = NULL;
    if( i < 1 || i > L -> length + 1 )
        exit(ERROR);
    if( L -> length >= L -> listsize ) // �����ǰ���Ա�ĳ����Ѿ��ﵽ����󳤶�,�����·����ڴ�
    {
        newbase = (ElemType *)realloc( L -> elem,sizeof(ElemType) * ( (L -> length) + LISTINCREMENT) );
        if( newbase == NULL )
            exit(OVERFLOW);
        L -> listsize += LISTINCREMENT;
    }
    q = (L -> elem) + i - 1; // Ҫ�����½���λ��
    for( p = (L -> elem) + (L -> length) - 1 ;p >= q;p-- )
    {
        *(p + 1) = *p;
    }
    *q = e;
    (L -> length)++;
    return OK;
}
/**
 * ����˳�����Ա���ÿһ�������ú���vi
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
 * ����˳�����Ա�L�ĳ���
 */
int ListLength(SqList L)
{
    return L.length;
}
/**
 * ��ȡ˳�����Ա�ָ��λ���ϵ�����
 */
Status GetElem(SqList L,int i,ElemType * e)
{
    if( i < 1 || i > L.length + 1 )
        exit(ERROR);
    *e = *(L.elem + i - 1);
    return OK;
}
/**
 * ��ȡִ�����������Ա��еĴ洢λ�á�����������򷵻�0
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
 * ��LocateElem()ʹ�á�
 */
Status equal(ElemType e1,ElemType e2)
{
    if( e1 == e2 )
        return TRUE;
    else
        return FALSE;
}
