#include <string.h>
#include "sstring.h"

/**
 * 生成一个其值等于 chars 的串T
 */
Status StrAssign(SString T,char * chars)
{
    int i;
    if( strlen(chars) > MAXSTRLEN )
        return ERROR;
    else
    {
        T[0] = strlen( chars );
        for( i = 0;i<T[0];i++ )
            T[i] = *(chars + i -1);
        return OK;
    }
}
/**
 * 由串S复制到串T
 */
Status StrCopy(SString T,SString S)
{
    int i;
    for(i=0;i<S[0];i++)
        T[i] = S[i];
    return OK;
}
/**
 * 若S为空串，则返回TRUE，否则返回FALSE
 */
Status StrEmpty(SString S)
{
    if( S[0] == 0 )
        return TRUE;
    else
        return FALSE;
}
/**
 * 若 S>T .则返回值>0,若S=T，则返回值=0.若S<T，则返回值<0
 */
Status StrCompare(SString S,SString T)
{
    int i;
    for(i=1;i<=S[0] && i <= T[0];i++)
        if( S[i] != T[i] )
            return S[i] - T[i];
    return S[0] - T[0];
}
/**
 * 返回串的元素个数
 */
int StrLength(SString S)
{
    return S[0];
}
/**
 * 将串S清空
 **/
Status ClearString(SString S)
{
    S[0] = 0;
    return OK;
}
/**
 * 算法4.2
 * 用T返回S1和S2连接而成的新船。若未截断，则返回TRUE，否则返回FALSE
 **/
Status Concat(SString T,SString S1,SString S2)
{
     int i;
     if( S1[0] + S2[0] <= MAXSTRLEN ) // 未截断
     {
        for(i=1;i<=S1[0];i++)
            T[i] = S1[i];
        for(i=1;i<=S2[0];i++)
            T[ S1[0] + i ] = S2[i];
        T[0] = S1[0] + S2[0];
        return TRUE;
     }
     else // 截断
     {
        for( i=1;i<=S1[0];i++)
            T[i] = S1[i];
        for( i =1;i<=MAXSTRLEN-S1[0];i++)
            T[ S1[0] + i] = S2[i];
        T[0] = MAXSTRLEN;
        return FALSE;
     }
}
/**
 * 算法4.3
 * 用Sub返回串S的第pos个字符起长度为len的子串
 */
Status SubString(SString Sub,SString S,int pos,int len)
{
    int i;
    if( pos < 1 || pos > S[0] || pos + len -1 > S[0] )
        return ERROR;
    for(i=pos;i<=pos + len -1;i++)
        Sub[i] = S[i];
    Sub[0] = len;
    return OK;
}
/**
 * 算法4.5
 * 不依赖串的其他基础操作
 * 返回子串T在主串S中第pos个字符之后的位置。若不存在，则函数值为0
 * 其中，T非空，1<=pos <=StrLength(S)
 */
int Index(SString S,SString T,int pos)
{
    int i,j;
    if( 1 <= pos && pos <= S[0] )
    {
        i = pos;
        j = 1;
        while( i<= S[0] && j<=T[0] )
            if( S[i] == T[j] ) // 继续比较后继字符
            {
                ++i;
                ++j;
            }
            else //指针后退重新开始匹配
            {
                i = i - j + 2; // i - (j - 1) + 1
                j = 1;
            }
        if( j > T[0] )
            return i = T[0];
        else
            return 0;
    }
    else
        return 0;
}
