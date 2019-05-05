---
layout:	post
title:	"散度和拉普拉斯算子(Divergence and Laplacian)"
data:	2018-06-15 14:00:00
categories: GeometricProcessing
tags:	计算机图形学 CG 微分网格处理
excerpt: 这是一篇记录自己在学习拉普拉斯算子的文章的文章
author: Lydia
mathjax: true
---

第一次接触拉普拉斯方程时，理解起来非常困难，主要在于两个方面：
1）对散度没有直观概念；
2）对拉普拉斯算子没有直观理解。
我第一次接触的是离散的拉普拉斯方程，感觉还要难一些。

最近看了可汗学院关于散度和拉普拉斯算子的讲解，感觉不仅对连续域的拉普拉斯算子理解更深，对离散域的拉普拉斯算子也有了更好的理解。现在讲这些理解记录下来。

### **1 梯度**

首先介绍一下梯度的概念，梯度首先是一个矢量 ，它的求解对象是标量，它指向标量场增长最快的方向，它的长度是改点值得变换率。

如图1所示，小箭头代表梯度，箭头的方向表示梯度的方向，箭头越长，梯度越大。在图像的最高点，梯度的方向朝里；在图像的最低点，梯度方向朝外；在图像变化最快的地方，梯度最大。

梯度通常用如下记号表示
$$grad(f)=\nabla f$$

### **2 散度**

#### **2.1散度概念**

下面，介绍一下散度的概念。散度我们可以记成“散开的程度”。它的运算对象为矢量，表示空间中矢量场在某一点的发散程度，运算的结果为标量，当散度为正（+）时，矢量在这一点是发散的，当散度为负（-）时，矢量在这一点是收敛的。

散度通常用符号$\nabla \cdot \mathbf {v}$表示

#### **2.2散度理解**

下面我们举几个例子说明，何时散度取正，何时散度取负。

矢量函数$\mathbf{v_1(x,y)} =  \begin{vmatrix} P(x,y) \\ 0 \end{vmatrix}$,该函数的$x$坐标为关于$x,y$的标量函数，$y$坐标为0

若某一点$p_0(x_0,y_0)$处，$Q(x_0,y_0)=0$，在$p_0$周围的向量都朝外，则改点处散度大于零。如图2所示。

#### **2.3散度公式**

二维散度公式表示为
$$\nabla \cdot \mathbf{v(x,y)}=\begin{vmatrix} \frac{\partial}{\partial x} \\ \frac{\partial}{\partial y}  \end{vmatrix} \cdot \begin{vmatrix} P(x,y) \\ Q(x,y) \end{vmatrix}= \frac{\partial P(x,y)}{\partial x} +\frac{\partial Q(x,y)}{\partial y}$$

即，对每一个分量求偏微分(二维梯度)再求和。

三维散度计算公式为$\nabla \cdot \mathbf{v(x,y,z)}=\begin{vmatrix} \frac{\partial}{\partial x} \\ \frac{\partial}{\partial y} \\ \frac{\partial}{\partial z}  \end{vmatrix} \cdot \begin{vmatrix} P(x,y,z) \\ Q(x,y,z)\\ R(x,y,z) \end{vmatrix}= \frac{\partial P(x,y,z)}{\partial x} +\frac{\partial Q(x,y,z)}{\partial y}+\frac{\partial R(x,y,z)}{\partial z}$

由此可推出$n$为散度公式
$$\nabla \cdot \mathbf{v(x_1,x_2,...,x_n)}=\frac{\partial P_1(x,y,z)}{\partial x} +\frac{\partial P_2(x,y,z)}{\partial y}+...+\frac{\partial P_n(x,y,z)}{\partial z}$$

### **3拉普拉斯方程**

![DivAndLaplacian](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/DivAndLaplacian.png)

图1,图像和梯度

![DivAndLaplacian1](https://raw.githubusercontent.com/LingjieLi/LingjieLi.github.io/master/images/DivAndLaplacian1.png)

图2,图像散度

### **附录**

- 图1代码

```matlab
clear;clc;close all
[X,Y] = meshgrid(-2:.2:2);        % 产生网格数据X和Y
Z = X.*exp(-X.^2 - Y.^2)+0.5;         % 计算网格点处曲面上的Z值
[DX,DY] = gradient(Z,0.2,0.2);    % 计算曲面上各点处的梯度

figure;
surfc(X,Y,Z);                       %绘制函数
hold on
q=quiver(X,Y,DX,DY,'k') ;               % 绘制梯度场
q.Color='black';
q.LineWidth=0.9;
q.MaxHeadSize=2.5
```



**散度:** 运算的对像是向量,运算出来的结果会是纯量
**梯度:** 运算的对像是纯量,运算出来的结果会是向量在一个标量场中,