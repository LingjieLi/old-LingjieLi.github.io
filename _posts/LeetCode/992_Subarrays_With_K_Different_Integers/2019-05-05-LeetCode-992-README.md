---
layout:	post
title:	"LeetCode_992 Subarrays with K Different Integers"
data:	2019-05-05 21:09:01
categories: LeetCode
tags: Sliding-Window Arrays LeetCode Hard
excerpt: LeetCode 第992题 关键是O(n)的滑动窗口
author: Lydia
mathjax: true
---

* content
{:toc}

### **992.Subarrays with K Different Integers**

解决这一题目的时候主要考虑到效率问题，我一开始也想到用滑动窗口解决，但是因为窗口前端和后端不是递增的，导致时间复杂度为$O(n^2)$，结果超时了，题目给的数据规模小于一万，因此需要更高效的算法。
### **Description**
- 地址  
[https://leetcode.com/problems/subarrays-with-k-different-integers/](https://leetcode.com/problems/subarrays-with-k-different-integers/)
- 题目
    > Given an array A of positive integers, call a (contiguous, not necessarily distinct) subarray of A good if the number of different integers in that subarray is exactly K.  
    >
    > (For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.)  
    >
    > Return the number of good subarrays of A.
    >
    >
    > Example 1:  
    > 
    > Input: A = [1,2,1,2,3], K = 2  
    > Output: 7  
    > Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2].
    >
    > Example 2:
    >
    > Input: A = [1,2,1,3,4], K = 3  
    > Output: 3  
    > Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
    >
    > Note:
    >
    > 1. 1 <= A.length <= 20000  
    > 2. 1 <= A[i] <= A.length  
    > 3. 1 <= K <= A.length  

- 解析  
  把一个子数组想象成一个窗口，窗口的长度以不同的整数个数计算，窗口长度要求为K。设定两个游标$i,j(j\geq i)$,$j-i+1$为窗口的长度。当窗口长度小于K时,j向右移动，当窗口长度大于K时，i向右移动。  
  `atMost(vector<int>& A,int K)` 函数用来计算长度在$[1,K]$的窗口个数，`atMost(A,K)-atMost(A,K-1)`得到长度为K的窗口个数

- 步骤  

### **Wrong Solution**

### **Good Solution**

#### **在这份代码中，值得被借鉴的写法**
`Map` 用来计数很方便，查找的平均时间复杂度为常数时间复杂度，最大为线性时间复杂度。
#### **Solution**

### **Commont**
#### **int,long,unsigned long,long long**

#### **How to input in C++?**
