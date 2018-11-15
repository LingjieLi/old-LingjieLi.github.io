---
layout:	post
title:	"数据结构(陈越何钦铭) 1-数据结构是什么"
data:	2018-10-17 14:00:00
categories: LearnDataStructure
tags:	DataStructure 
author: Lydia
mathjax: true

---

* content
{:toc}

本文主要记录在MOOC上学习到的是数据结构第一节。



[TOC]
#### **秦九韶算法**
 $$ f(x)=a_0+a_1x+a_2*x^2+...+a_n*x^n=a_0+...+x(a_{n-2}+x*(a_{n-1}+a_n*x)) $$
#### **抽象数据类型Abstract Data Type**
 - 数据对象集
 - 数据对象集上的操作
 ![ADT](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/ADT.png)

#### **选择排序**
```cpp
void selectionSort(list[],n)
{
	for(i=1:n)
    {
    	minPosition=min(list[],i+1,n);
        swap(list[i],list[minPosition]);
    }
}
```
#### **衡量算法的指标**
空间复杂度 $S(n)$
时间复杂度$T(n)$:可以只去计算乘除法的的次数,因为计算加减比计算乘除快得多
![progress](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/progress.png)
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/On.png)
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Onimg.png)

#### **算法复杂度分析技巧**
  - $O(f_1(n)+f_2(n))=max(O(f_1(n)),O(f_2(n)))$,代码拼接
  - $O(f_1(n)*f_2(n))=O(f_1(n))*O(f_2(n))$,代码嵌套
  - 若T(n)是关于n的k阶多项式,则$T(n)= \Theta(n)$
  - 一个for循环的时间复杂度等于循环次数乘以循环体代码的复杂度
  - if-else 结构的复杂度取决于if的条件判断复杂度和两个分枝部分的复杂度，总体复杂度取三者中最大

#### **最大子列和问题**
给定N个整数的序列${A_1,A_2,...,A_N}$,求函数$f(i,j)=max{0,\sum_{k=i}^jA_k}$
##### **算法1:分治法**
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/Divide.png)
```cpp
float SubSequenceMax(const vector<int> &list,int low,int high)
{
}
```
##### **算法2:在线处理**
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/OnLine.png)

**这里给了两个课后练习题,第一题是基础版的最大子列和问题,第二题是提高版的最大子列和问题**
![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/MaxSubPAT1.png)
```cpp
#include <iostream>
#include <vector>

using namespace std;
int main()
{
  int N;
  vector<int> list;
  cin>>N;
  for(int i=0;i<N;i++)
  {
    int temp;
    cin>>temp;
    list.push_back(temp);
  }
  int thisSum,maxSum;
  thisSum=maxSum=0;
  for(int i=0;i<N;i++)
  {
    thisSum+=list[i];
    if(thisSum>maxSum)
    {
      maxSum=thisSum;
    }
    else if(thisSum<0)
    {
      thisSum=0;
    }
  }

  std::cout<<maxSum<<std::endl;
  return 0;
}
```

![](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/MaxSubPAT2.png)

**解决这个问题的时候,自己并没有写出完全正确的算法,这是参考别人代码改进的**
**这个方法的巧妙之处在于,使用tempIndex变量,记录可能的i值**

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int K;
  vector<int> list;
  cin>>K;
  int i=0,j=K-1;
  int tempIndex=0;
  int thisSum=0;
  int maxSum=-1;

  for(int p=0;p<K;p++)
  {
    int temp;
    cin>>temp;
    list.push_back(temp);

    thisSum+=temp;
    if(thisSum>maxSum)
    {
      maxSum=thisSum;
      i=tempIndex;
      j=p;
    }
    else if(thisSum<0)
    {
      thisSum=0;
      tempIndex=p+1;
    }
  }

  if(maxSum<0)
    maxSum=0;
  std::cout<<maxSum<<" "<<list[i]<<" "<<list[j]<<std::endl;
  return 0;
}

```
