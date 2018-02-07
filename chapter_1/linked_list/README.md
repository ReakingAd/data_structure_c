##111111##
1. 关于链表的定义。
	
	   typedef struct LNode * LinkList;

    链表被定义为指向结点的指针。因为链表可以由头指针唯一确定，而头指针指向链表的第一个结点（如果有头结点，头指针则指向头结点，头结点的指针域指向第一个结点）。所以将链表定义为一个指向结点的指针。例如：
    `LinkedList L;` 则`LinkedList`类型的变量`L`就是一个指向头结点的指针。
    
    
2. [参考](https://segmentfault.com/q/1010000007504600)

--------------------------------
    单循环链表的操作为什么要用二级指针作为参数呢？ 我试过了若用一级指针的话 初始化链表之后 链表并不是空的
    而用二级指针的话 调用函数LinkEmpty()之后 证明链表是空的 二级指针不是很少用吗？这里必须用二级指针吗？
    typedef struct LinkListNode
    {
    LElemType data;
    struct LinkListNode *next;
    }LinkList,……


初始化必须要用二级指针
LinkListPtr La;//没有初始化，La的值是随机的，如果 La=0xFFFFFFFF；
则 InitList(La)执行如下：
创建局部变量L，
传参L = La;       //L=2000H;
L = (LinkListPtr)malloc(sizeof(LinkList));//假如新申请的空间首地址是0x111111111；
/*下面是对以0x11111111为首地址的结构体变量的操作*/
if(!L)
return OVERFLOW;
L->next = NULL;
return OK;

/*函数结束后，以0x11111111为首地址的结构体变量空间依然可用（因为是你申请的）*/
/*但是L是局部变量，函数结束后，L被撤销，而La的值不会随L改变（是两个不同的变量，只是一开始传值有关系），既，你申请的空间的地址丢了*/
/*返回主函数后，La还是0xFFFFFFFF(一开始的随机值)*/
这么说，懂不？ 