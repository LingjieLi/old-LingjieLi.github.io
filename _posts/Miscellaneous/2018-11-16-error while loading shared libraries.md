---
layout: post
title:  "error while loading shared libraries"
date:   2018-11-16 22:14:54
categories: Miscellaneous
tags: Ubuntu library
excerpt: 第一次在Ubuntu上使用CGAL库遇到此问题
mathjax:	true

---

* content
{:toc}

### **1 问题**
>/home/lydia/Code/LearnCGAL/SegmentationWithSDF/build-SegmentationWithSDF-Desktop_Qt_5_11_2_GCC_64bit-Debug/SegmentationWithSDF: error while loading shared libraries: libCGAL.so.13: cannot open shared object file: No such file or directory


### **2 参考连接**
[https://www.cnblogs.com/abc-begin/p/8243235.html](https://www.cnblogs.com/abc-begin/p/8243235.html)

### **3 治疗**

**依赖的库找不到路径导致的**

#### **3.1查看依赖库**

使用命令`ldd xxx(生成的文件xxx.o)`
```
lydia@lydia-desktop:~/Code/LearnCGAL/SegmentationWithSDF/build-SegmentationWithSDF-Desktop_Qt_5_11_2_GCC_64bit-Debug$ ldd SegmentationWithSDF 
	linux-vdso.so.1 (0x00007fffaad7f000)
	libCGAL.so.13 => /usr/local/lib/libCGAL.so.13 (0x00007f093b010000)
	libstdc++.so.6 => /usr/lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007f093ac87000)
	libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x00007f093a8e9000)
	libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x00007f093a6d1000)
	libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f093a2e0000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f093b44c000)

```

**我本来是`libCGAL.so.13`**找不到的,但是我再`.pro`文件内包含了的,应该是这样的我这个动态库安装在`/俗人/local/lib`文件夹下,属于系统位置?应该是能够自己搜索到的?

#### **3.2分类解决**

**1)如果共享库文件安装到了/lib或/usr/lib目录下, 那么需执行一下ldconfig命令**

>ldconfig命令的用途，主要是在默认搜寻目录(/lib和/usr/lib)以及动态库配置文件/etc/ld.so.conf内所列的目录下，搜索出可共享的动态链接库(格式如lib*.so*)，进而创建出动态装入程序(ld.so)所需的连接和缓存文件，缓存文件默认为/etc/ld.so.cache，此文件保存已排好序的动态链接库名字列表。

**2)如果共享库文件安装到了/usr/local/lib(很多开源的共享库都会安装到该目录下)或其它"非/lib或/usr/lib"目录下，那么在执行ldconfig命令前，还要把新共享库目录加入到共享库配置文件/etc/ld.so.conf中**

```
lydia@lydia-desktop://etc$ sudo cat ld.so.conf
[sudo] password for lydia: 
include /etc/ld.so.conf.d/*.conf
#lydia@lydia-desktop://etc$ sudo echo "/usr/local/lib">>ld.so.conf
#bash: ld.so.conf: Permission denied
#当执行以上命令出现以上错误时:

lydia@lydia-desktop://etc$ sudo sh -c " echo '/usr/local/lib'>>ld.so.conf"
lydia@lydia-desktop://etc$ sudo ldconfig

```

**3)如果共享库文件安装到了其它"非/lib或/usr/lib" 目录下，但是又不想在/etc/ld.so.conf中加路径(或者是没有权限加路径)。那可以export一个全局变量LD_LIBRARY_PATH，然后运行程序的时候就会去这个目录中找共享库**

LD_LIBRARY_PATH的意思是告诉loader在哪些目录中可以找到共享库。可以设置多个搜索目录，这些目录之间用冒号分隔开。比如安装了一个mysql到/usr/local/mysql目录下，其中有一大堆库文件在/usr/local/mysql/lib下面，则可以在.bashrc或.bash_profile或shell里加入以下语句即可：
export LD_LIBRARY_PATH=/usr/local/mysql/lib:$LD_LIBRARY_PATH   