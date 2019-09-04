---
layout:	post
title:	"数据结构(陈越何钦铭) 线性结构2.1-线性表(List)"
data:	2018-10-17 14:00:00
categories: LearnDataStructure
tags:	线性结构 线性表 List
excerpt: 这是一篇记录自己在学习MOOC线性结构-线性表的文章
author: Lydia
mathjax: true
---

* content
{:toc}

### **引入:多项式的表示及运算**
#### 顺序存储结构直接表示
**使用数组元素 $a[i]$ 存储 $x^i$ 的系数 $a_i$**
- 多项式相加:相同下标的项相加
- 多项式相乘:遍历
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/LAll.png)

####顺序存储结构表示非零项
**用结构数组表示非零项,数组分量$a[i]$ 是由系数 $a_i$ 和指数 $i$ 组成的结构** 
- 多项式相加:从头开始,比较两个多项式对应的指数,指数相等:相加,都往后移一个;不等:指数大的放进和里,往后移一个
- 多项式相乘:遍历
- 好处:节省空间
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/LNoZero.png)

#### **链表结构表示非零项**
**一个链表节点有三个域:系数,指数,指向下一个节点的指针**
- 多项式相加:同顺序结构存储非零项
- 多项式相乘:遍历
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Llist.png)

#### **线性表(List)**
**同类型元素组成的有序序列的线性结构**
- **属性:** 长度,表头,表尾
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/LADT.png)
### **线性结构(线性表)的存储方式**
* 顺序存储
* 链式存储

### **广义表(Generlized List)**
- 广义表是线性表的推广
- 对于线性表来说, $n$ 个元素全部都是单元素,对于广义表来说,既可以是单元素也可以是广义表
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Glist.png)
### **多重链表**
- 广义表是一种多重链表
- 多重链表对于存储图\树 这种结构很友好,例如用十字链表存储稀疏矩阵
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Mlist1.png)
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Mlist2.png)
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Mlist3.png)
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Mlist4.png)