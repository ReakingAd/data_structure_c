#ifndef _STRING_H_
#define _STRING_H_

#include "common.h"
#define MAXSTRLEN 40
// 串采用定长顺序存储结构
typedef char SString[MAXSTRLEN + 1]; // 0号单元存放串的长度
Status StrAssign(SString,char *);
Status StrCopy(SString,SString);
Status StrEmpty(SString);
Status StrCompare(SString,SString);
int StrLength(SString);
Status ClearString(SString);
Status Concat(SString,SString,SString);
Status SubString(SString,SString,int,int);
int Index(SString,SString,int);
#endif
