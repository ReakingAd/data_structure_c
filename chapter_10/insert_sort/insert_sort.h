#include "common.h"

#define MAXSIZE 20 // 一个用作示例的小顺序表的最大长度

typedef int KeyType; // 定义关键字类型为整数类型
typedef int InfoType;

typedef struct {
    KeyType key; // 关键字项
    InfoType otherinfo; // 其他数据项
}RedType; // 记录类型

typedef struct {
    RedType r[MAXSIZE + 1]; // r[0]用作哨兵单元
    int length;
}SqList;

void PrintListKeys(SqList);
void InsertSort(SqList *);
void BInsertSort(SqList *);
