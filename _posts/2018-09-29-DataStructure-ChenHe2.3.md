## 数据结构(陈越何钦铭)2-线性结构
### 数据结构(陈越何钦铭)2.3-队列(Queue)

**堆栈是一种受限制的线性结构**,是一种特殊的线性表
入队只能在队尾进行,出队只能在队头进行

#### 队列的抽象数据结构

#### 队列的存储方式
##### 顺序存储方式
```cpp
#define MaxSize <存储数据元素的最大个数>
struct QNode
{
	ElementType Data[MaxSize]
    int rear;//队尾
    int front;//队头
}
typedef struct QNode* Queue;
```
##### 链表存储结构
**使用链表存储队列**,队头指向链表的头,队尾指向链表的尾
```cpp
struct Node
{
	ElementTyep Data;
    struct Node *Next;
}
struct QNode
{
	struct Node *rear;
    struct Node *front;
}
typedef struct QNode *Queue;
Queue PtrQ;
```

#### 循环队列
**队列空和满的判别条件是什么?**
	- 使用额外标记:size或tag
    - 仅仅使用n-1个空间