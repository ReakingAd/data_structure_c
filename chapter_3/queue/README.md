### 总结
1. 与链表不同，`LinkedList L`中`L`是头指针。而链式队列`ListQueue Q`中，`Q.front`是头指针。
2. `Q.front`指向头结点。`Q.front -> next`指向队头结点。`Q.rear`指向队尾结点。

### 问题
0. `Q.front`是头指针，那`Q`算什么啊？？？我曹
1. 比较队列的链式存储和顺序存储的存储上的差异
2. 链式队列，头指针，头结点，队头，队尾。
3. `DestroyQueue()`的实现原理是什么？？还有为什么要加上while循序呢？对比LinkedList的实现看看。
4. 感觉课本上的注释错了，`(*Q).front`不应该是队头指针，而应该是头指针。`(*Q).front -> next`才是队头指针
5. `ClearQueue()`为什么要逐个将原队列中的元素都free掉呢？放在那不行吗？linkedList不是就放在那不管了吗？对比一下`ClearList()`