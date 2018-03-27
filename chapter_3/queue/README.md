### 总结
1. 链表和链式队列在结构定义上的差异：
    > 链表`LinkedList L`,`L`是头指针，`L`指向头结点。
    > 链式队列`LinkedQueue Q`,`Q.front`是头指针，`Q.front`指向头结点。
    > 之所以`Q.front`是头指针，而`Q`不是头指针，是因为链式队列需要对头指针和对尾指针同时存在，才能唯一确定一个链式队列。而链表只需要一个头指针就可以唯一确定一个链表。所以链式队列的结构定义为：

        typedef struct {
            QueuePtr front;
            QueuePtr rear;
        } LinkedQueue;
    > 而链表则定义为：

        typedef struct LNode * LinkedList;

    这里要纠正一下之前对于头指针的理解偏差：`LinkedList L`定义的一个变量，变量名`L`就是一个头指针并不是天经地义的。而是由于链表的定义---本身`LinkedList`就是一个指向结点的指针。到了链式队列这里，`LinkedQueue Q`链式队列本身并不是一个指针，而是两个指针组成的一个结构体。这两个指针中，一个是头指针`front`一个是尾指针`rear`。千万不要理解成，类型定义后的变量名就是头指针。

2. 为了操作方便，像链表一样为链式队列加入一个不存放数据的头结点。`Q.front`是头指针，它指向头结点。`Q.front -> next`指向队头结点（第一个真正存放数据的结点）。`Q.rear`指向队尾结点。
3. 显然，队头指针`Q.front`和队尾指针`Q.rear`同时指向头结点时，队列为空。
4. 


### 问题

3. `DestroyQueue()`的实现原理是什么？？还有为什么要加上while循序呢？对比LinkedList的实现看看。

5. `ClearQueue()`为什么要逐个将原队列中的元素都free掉呢？放在那不行吗？linkedList不是就放在那不管了吗？对比一下`ClearList()`