---
layout:	post
title:	"shell notes"
data:	2019-04-01 14:00:00
categories: shell
tags:	shell notes 
author: Lydia
mathjax: true

---


边学习,边记录,shell notes




# 一、shell 常用命令

## 1.**ssh登陆不能在命令行中指定密码。** 
sshpass的出现，解决了这一问题。sshpass用于非交互SSH的密码验证，一般用在sh脚本中，无须再次输入密码。

它允许你用 -p 参数指定明文密码，然后直接登录远程服务器，它支持密码从命令行、文件、环境变量中读取。

## 2.登录远程服务器
登录远程服务器`spider@cp01-cspub.epc.baidu.com`，并且输出`/home/spider/testplatform/apache/htdocs/testplatform/crawler_service `下的文件列表
```shell
sshpass -p ps-testing\!\!\! ssh spider@cp01-cspub.epc.baidu.com "cd /home/spider/testplatform/apache/htdocs/testplatform/crawler_service;ls"
```

## 3.打开传输服务
`sudo service smb restart`
`sudo service smb start`

## 4.`grep` 命令
```shell
grep -r testTool ./*
```
在`./*`下查找含有 字符串`testTool`的文件

## 5.`find` 命令
`find ./ -name test`
在当前文件夹下查找文件名中含有test的文件

## 6. shell中定义/初始化变量 或 给变量赋值时不能用空格
```shell
#正确写法
path="/home/spider/cs/dispatcher/data"
#错误写法
path = "/home/spider/cs/dispather/data
```
## 7.`=~`包含的意思
## 8.`source`命令 ##
source命令，点命令，不产生子进程
## 9. 单引号（强引用，全引用）vs 双引号（部分引用，弱引用）
1）单引号被称为“强引用”、“全引用”，变量替换被阻止
2)  双引号被称为“部分引用”、“弱引用”，变量替换不被阻止
## 10. `env`函数  vs  `set`函数
`env `函数显示环境变量
`set`函数显示所有本地变量，也包括环境变量
## 11. `$#` `$@`
`$#`参数数量，`$@`所有参数 
## 12. 重定向符号`>` `<` `>>`
```shell
command>file # 将command的标准输出重定向到file(覆盖方式)
command<file # 将command的标准输入重定向到file
command>>file #将command的标准输出重定向到file(追加方式)
```
## 13. 管道符号`|`
`command1 | command2` 将`command1`的标准输出与`command2`的标准输入相连 
## 14. `/dev`设备文件存放地址 
## 15. 标准输出、标准输入和标准错误
```shell
# 重定向标准输入
0<
# 重定向标准输出
1>
# 重定向标准错误
2>
# 重定向标准输出和标准错误
&>
```

## 16. `/dev/null`黑洞
写入的文件会永久丢失，如果想从这个文件读取则什么也读取不到
## 17. `ls -lh` = `ls-lA` vs `ls -la`
`-l`列出属性
`=h`列出所有条目
`-A`列出所有条目
`-a`列出所有项，包含 `.` `..`

## 17 字典

``` 
declare -A dict
dict=([db]="db_crawl_info" [hz]="hz_crawl_info" [hksm]="hksm_crawl_info" [hknm]="hknm_crawl_info")
```

# 二、Shell基础知识

## 1.Shell是什么
**Shell命令行解释器**
**一种编程语言**
## 2.记录
- export 继承变量，让子Shell继承该变量，只能向下单向继承
- 若需要使用脚本来影响当前环境，用source 来执行该脚本
- subshell :调用脚本 使用外部命令 管道符、() 压入后台执行的命令
```shell
:(){ :|:& };:
```
### 2.1.环境变量
`$IFS` :分隔符，如果改变，那么在当前shell环境下使用当前分隔符（`for ... in ...`）
`$PWD`:当前目录

### 2.2.引号迷雾
单引号：引号里面是什么就是什么
双引号：变量替换
反引号：里面内容是命令

### 2.3 括号
尽量使用双中括号`[[]]` 注意内容和括号之间要有空格

## 3.命令
tee:将标准输出拆分成两部分，文件+接下来的标准输出
`&` 压后台命令
重定向符号 `>` `<` 是倒序解析的
重定向符号 `>>` `<<` 是追加到文件后，也是倒序解析的

# 三、Shell编程技巧
## 1.内置字符串处理
```shell
str=abcdefg
#1.字符串长度
${#str} 
7
#2.字符查找
expr index $str "b"
2
#3.字符串截取/偏移
echo ${str:1} #${字符串:起始位置}
bcdefg
echo ${str:2} #${字符串:起始位置}
cdefg
echo ${str:0:2} #${字符串:起始位置:结束位置}
ab
#4.截去头部最短匹配
str=aabbbnsalweelwfjkdwlfw
echo ${str#a*a}
bbbnsalweelwfjkdwlfw
#5.截去头部最长匹配
echo ${str##a*a}
lweelwfjkdwlfw
#6.截去尾部最短匹配
echo ${str%w*w}
aabbbnsalweelwfjkd
#7.截去尾部最长匹配
echo ${str%%w*w}
aabbbnsal
#8.字符替换，只替换一个
echo ${str/a/b}
babbbnsalweelwfjkdwlfw
#9.字符替换，替换所有
echo ${str//a/b}
bbbbbnsblweelwfjkdwlfw

#10 :+ :- 判断字符串有没有值
# :+ 有值则整体变为冒号后面的值，自身不变
a=123
echo ${a:+456}
456
echo $a
123
# :- 有值则整体变为冒号后面的值，自身不变
a=
echo ${a:-456}
456
echo $a
空

# := 空则赋值为等号后面的值，非空不变
a=
echo ${a:=456}
456
echo $a
456

a=123
echo ${a:=456}
456
echo $a
123
```
## 2.进程替换
diff两台服务器的同一配置文件
```shell
vimdiff<(ssh server1 cat conf)<(ssh server cat conf)
```

## 四、Shell陷阱
### 1.陷阱一
管道内异常捕获
### 1.陷阱二 ssh 远程hang住
ssh 需要确定命令不再有任何输入和输出，并且有确切的返回值
### 1.陷阱三
### 1.陷阱四 hug 信号
-  nohup 命令
向系统注册一个SIGHUP信号，终端退出，命令不会退出
- setsid命令
在新会话中运行进程，父进程为init
- ( cmd& )
在新会话中运行进程，父进程为init
- screen
会话状态保持在服务器端


