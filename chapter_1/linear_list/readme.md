## C语言基础 ##
1. 如果`L`是一个指针，则`L -> length `是`(*L).length` 的简写形式
2. `#include <math.h>` 提供`OVERFLOW = 3`的定义
3. 定义一个指针时，最好初始化它。要么设置为`NULL`,要么指向一段合法的内存。否则这个指针会乱指一气，造成bug，俗称野指针。
4. 关于`malloc()`函数
	
		`malloc`是`memeory allocation`的缩写。函数原型是`void * malloc(size_t size);`函数会申请一段size大小的内存，并把该内存地址作为结果返回。如果申请失败则返回NULL
    使用注意事项:

	    a. malloc()返回的指针类型是`void *`。因此需要对其返回结果做前置类型转换后，才能被使用。例如`p = (int *)malloc( sizeof(int) );`
        b. 为了确定malloc()是否成功申请了内存，需要对返回结果做判断，看结果是不是`NULL` 
5. 关于`realloc()`函数
	
		realloc是reallocate的缩写。函数原型是void * realloc(* mem_address,unsigned int newsize )；函数会对指针mem_address重新分配大小为newsize的内存，并将新内存地址返回。如果申请内存失败，则返回NULL，此时原内存mem_address仍然有效。
6. 关于`free()`函数

## 算法备注 ##

1. 顺序存储的线性表，是使用数组实现的。与数组从下表`0`开始计数不同，本源码实现的线性表是从`1`开始标记首个结点的。