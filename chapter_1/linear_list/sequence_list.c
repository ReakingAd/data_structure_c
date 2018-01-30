#include "common.h"
#include "sequence_list.h"

/**
 * �㷨2.3
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
 * �㷨2.4
 * ��˳�����Ա��ָ����λ�ã�����һ����Ԫ��
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
    q = (L -> elem) + i - 1; // Ҫ������Ԫ�ص�λ��
    for( p = (L -> elem) + (L -> length) - 1 ;p >= q;p-- )
    {
        *(p + 1) = *p;
    }
    *q = e;
    (L -> length)++;
    return OK;
}
/**
 * ����˳�����Ա���ÿһ��Ԫ�ص��ú���vi
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

/**
 * �㷨2.1
 * �ϲ�����˳�����Ա�La��Lb����Lb�д��ڡ�La�в����ڵ�Ԫ�أ����뵽La��ĩβ
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
 * �㷨2.2
 * ��֪�����Ա�LA��LB�е�Ԫ�ذ�ֵ�ǵݼ��������С�
 * �����������LA��LB�е�Ԫ�ع鲢���µ����Ա�LC�У���Ԫ����Ȼ��ֵ�ǵݼ�����
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
 * �㷨2.5
 * ɾ�����б�L�еĵ�i��Ԫ�أ����ѱ�ɾ����Ԫ�ش������e
 */
Status ListDelete(SqList * L,int i,ElemType * e)
{
    if( i < 1 || i > L -> length )
        exit(OVERFLOW);
    ElemType * p = NULL,* q = NULL;
    p = L -> elem;
    q = p + i - 1; // ָ�룬ָ��Ҫ��ɾ����Ԫ�ص�
    *e = *q;
    for(++q;q <= p + L -> length - 1;q++)
        *(q-1) = *q;
    L -> length--;
    return OK;
}
