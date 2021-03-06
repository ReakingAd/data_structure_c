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
7. 	
	### 运算符优先级

    | 优先级  | 运算符  | 含义  | 说明   |
    | ------ | ------ |------ |---- |
    | 1      | `[]`   | 数组下标      | 表明父子从属关系的，优先级最高。和`()`一样高
    |        | `()`   | (表达式)      | 
    |        |  `.`   | 成员选择(指针) | 
    |        | `->`   | 成员选择(对象) | 
    | 2      | `++`、`--`  | 自增/自减     | 修正自身取值的，优先级也较高。（注意自增/自减是前置还是后置，如果是后置，在计算当前表达式的意义时，相当于没有自增/自减）
    |        | `*`、`&`    | 取值/取地址   | 
    |        | `sizeof` | 长度运算符    | 
    | 3      | `/`、`*`、`%`| 乘、除、求余 | 四则运算
    | 4      | `+`、`-`   | 加减
    | ...    |
    | 11     | `&&` | 逻辑与  | 逻辑
    | 12     | `ll` | 逻辑或  | 

    有个大致的规律是***父为子纲，变化优先***。意思是，牵扯到父子关系的优先级高（例如`.``->`优先于`++`,`*`）,改变自身的运算符优先级高(`++`优先于`*`)
8. `printf()`和`scanf()`使用时的区别
    `printf()`使用变量名、常量和表达式。而`scanf()`使用只向变量的指针。简单总结为如下规则：
    - 使用`scanf()`读取某中基本变量类型的值，请在变量名之前加上一个`&`
    - 使用`scanf()`把一个字符串读进一个字符数组中，请不要使用`&`
9. `scanf()`函数读取两个或多个输入

        scanf("%d,%d",&a,&b);

    在键盘输入时，依次键入`1,2`,则可以将`1`赋值给`a`,将`1`赋值给`b`。分隔符不一定使用逗号，使用什么都可以，但是要求在键盘键入时键入同样的分隔符。例如：

        scanf("%dseparater%d",&a,&b);

    键盘输入时需要键入`1separater2`    
10. scanf()函数的说明符中`*`修饰符的应用
    `scanf()`的说明符中`*`作用是滞后赋值，相当跳过这个变量。举例：

        scanf("%*d,%d",&m);
    
    键盘键入两个数字，只有第二个数字会被存储在变量m中。键入的第一个数字会被忽略。

11. c中函数参数是基础类型时，使用按值传递。如果想在函数内修改传进来的参数，则可以将原参数的指针传给函数。
12. c中使用数组作为函数参数的注意事项：

    - 因为数组名其实就是数组首元素的指针。因此在函数定义时，形参可以写成数组，也可以写成指向元素类型的指针。***为了函数内部使用数组的方便，通常也将数组的长度作为第二个参数，但不是必须的***。
    
    拿`int`型元素组成的数组来举例：
    
    ***函数原型***可以有四种等价写法：

            // 因为c中int ar[]和 int * ar都表示指向int的指针。
            // 函数原型可以省略变量名，只保留类型
            int sum( int ar[],int len );
            int sum( int [],int );
            int sum( int * ar,int len );
            int sum( int *,int );
    
    ***函数定义***有下面两种等价写法

            int sum( int ar[],int len){};
            int sum( int * ar,int len){};
    - 上一条可见，数组作为参数来传递，归根到底是传递的指针。也就是说函数内部对于参数的修改会影响到函数的外部作用域。如果函数本身完成的功能并不需要修改参数本身，想要对参数做一些保护，以免被无意中修改，那么可以使用const关键字。例如：

            // 显然sum函数并不想修改数组本身，可以加上const作为保护。一旦ar被修改，会编译报错。
            int sum( const int ar[],int len);

### 问题