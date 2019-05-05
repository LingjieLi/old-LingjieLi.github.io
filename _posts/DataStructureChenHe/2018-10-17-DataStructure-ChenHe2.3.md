---
layout:	post
title:	"数据结构(陈越何钦铭) 线性结构2.3-队列(Queue)"
data:	2018-10-17 14:00:00
categories: LearnDataStructure
tags:	线性结构 队列 Queue
excerpt: 这是一篇记录自己在学习MOOC线性结构-队列的文章
author: Lydia
mathjax: true
---

**堆栈是一种受限制的线性结构**,是一种特殊的线性表
入队只能在队尾进行,出队只能在队头进行

#### **1 队列的抽象数据结构**

#### **1.1队列的存储方式**
##### **1.1.1顺序存储方式**
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
##### **1.1.2链表存储结构**
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

#### **1.2循环队列**
**队列空和满的判别条件是什么?**
	- 使用额外标记:size或tag
    - 仅仅使用n-1个空间