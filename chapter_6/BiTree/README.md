###

1. 在`createBiTree()`函数中,通过键盘输入的字符来创建二叉树,如果使用`scanf("%c",&ch)`读取输入到ch,则会将回车也放入ch中,造成函数执行问题.因此,
   采用`scanf("%c%*c",&ch)`忽略掉回车字符.其中`*`在`scanf()`中的作用是滞后赋值,相当于跳过这个变量.    
   另一种好用的方法。即%c前面加一个空格.即`scanf(" %c",&ch)`.

2. 在`BiTree`工程中，引用`Stack`工程中的栈实现：

    a. #include "absolute_dir/stack/stack.h"
    b. 将stack.h和stack.c都得add到BiTree的工程中。