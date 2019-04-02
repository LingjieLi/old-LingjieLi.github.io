---
layout:	post
title:	"C++ 误区"
data:	2018-08-11 14:00:00
categories: CPlusPLus
tags:	CPP 
author: Lydia
mathjax: true

---



这是一篇记录自己在使用C++过程中出现误区的地方，没有什么逻辑顺序，仅记录而已。



[TOC]
###1数组的声明和初始化
- 数组需要在声明时规定数组的长度
- 数组的初始化可以在声明时，也可以在声明之后
```cpp
    //1.声明时初始化
    int A[3]={1,2,3};
    int B[5]={1};
    int C[]={1,2,3};

    //2.声明之后初始化
    int D[10];//数组声明
    for(int i=0;i<10;i++)//数组初始化
    {
        D[i]=i;
    }

    int E[6];

    std::cout<<"\nA:\n";
    for(int i=0;i<3;i++)
    {
        std::cout<<A[i]<<" ";
    }

    std::cout<<"\nB:\n";
    for(int i=0;i<5;i++)
    {
        std::cout<<B[i]<<" ";
    }
    std::cout<<"\nC:\n";
    for(int i=0;i<3;i++)
    {
        std::cout<<C[i]<<" ";
    }
    std::cout<<"\nD:\n";
    for(int i=0;i<10;i++)
    {
        std::cout<<D[i]<<" ";
    }
    std::cout<<"\nE(未初始化):\n";
    for(int i=0;i<6;i++)
    {
        std::cout<<E[i]<<" ";
    }
```
**[输出结果]**
```cpp
A:
1 2 3
B:
1 0 0 0 0
C:
1 2 3
D:
0 1 2 3 4 5 6 7 8 9
E(未初始化):
1953915528 8 1953852355 1953852346 467552267 4199040
```

###2 数组VS指针
- 指针可以在使用时决定开辟区间的大小，数组在声明时就要决定开辟区间的大小,数组的长度必须是const的(数字或者const int)
  ```cpp
  //数组
  const int MAX_LENGTH=10;
  int A[MAX_LENGTH];
  //指针
  int *B;
  B=new int[10];
  ```
- 当类中有指针属性时，使用类时也要用指针(**?**)
  **[二叉堆类Heap]**
  ```cpp
  class Heap
  {
  	public:
    	Heap(){};
        Heap(int *A,length)
        {
        	this->A=new int[length];
            for(int i=0;i<length;i++)
            {
            	this->A[i]=A[i];
            }
        };
        void print()
        {
        	for(int i=0;i<length;i++)
            {
            	std::cout<<A[i]<<" ";
            }
        };
  	private:
    	int *A;
  }
  ```
  
  **[使用二叉堆Heap]**
  ```cpp
  int A[4]={1,2,3,4};
  //正确示范
  Heap *heap;
  heap=new Heap(A,4);
  heap->print();
  //错误
  Heap heap2;
  heap2=Heap(A,4);
  heap2.print();
  ```
  **[输出]**
  ```cpp
  1 2 3 4
  68937909 2 3 4
  ```
  
###3 类模板不能使用分离式编译
###4 静态函数只能调用静态