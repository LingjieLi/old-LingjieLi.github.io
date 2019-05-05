---
layout:	post
title:	"数据结构(陈越何钦铭) 树(上)3.2-二叉树及存储结构"
data:	2018-11-13 14:00:00
categories: LearnDataStructure
tags:	树
excerpt: 这是一篇记录自己在学习MOOC树的文章
author: Lydia
mathjax: true
---

#### **1.1二叉树的定义**
**二叉树$T$:一个有穷的结点集合**
这个集合可以为空，如果不为空，则它由根节点和称为其左子树$T_L$和右子树$T_R$的两个不相交的二叉树组成

##### **1.1.1二叉树具有五种基本形态**
空树、仅根节点、只有左子树、只有右子树、有左子树和右子树
##### **1.1.2二叉树的子树有左子树和右子树之分**
##### **1.1.3特殊二叉树**
 * 斜二叉树
 ![斜二叉树](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/SkewedBinaryTree.png)
 * 完美二叉树(满二叉树)
 ![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Full_PerfectBinaryTree.png)
 * 完全二叉树
 缺少的结点只在最底层的右边
 ![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/CompleteBinaryTree.png)
 
##### **1.1.4 二叉树性质**
$n_0$:度为0的结点，叶子结点
$n_1$:度为1的结点
$n_2$:度为2的结点
$n_0=n_2+1$