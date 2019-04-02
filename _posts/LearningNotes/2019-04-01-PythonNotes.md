---
layout:	post
title:	"python notes"
data:	2019-04-02 14:00:00
categories: python
tags:	python notes 
author: Lydia
mathjax: true

---


边学习,边记录,python notes

# python notes

###  1. `r''` 取消转义
```python
>>>print(r'\\\n\\')
\\\n\\\
>>>print('\\\n\\\')
\
\
```

### 2.`a='XYZ'`
`a='xyz'`
>Python解释器干了两件事情：
1.在内存中创建了一个'ABC'的字符串；
2.在内存中创建了一个名为a的变量，并把它指向'ABC'。

所以，
```python
a='XYZ'
b=a
a=’ABC‘
```
解释器干了三件事情:
1. 在内存中创建一个’XYZ‘字符串，在内存中创建一个名为a的变量，并把它指向'XYZ'
2. 在内存中创建一个名为b的变量，并把它指向'XYZ'
3. 在内存中创建一个’ABC‘字符串，并把变量a指向'ABC'
因此，最终变量a指向’ABC‘,变量b指向’XYZ‘

**python赋值：**
1）变量1=值1：在内存中新建一个值1，在内存中新建一个名为变量1的变量，并把它指向这个值1
2）变量1=变量2：在内存中创建一个名为变量1的变量，并把它指向变量2指向的值

### 3.python 格式化输出
```python
>>> 'Hello, %s' % 'world'
'Hello, world'
>>> 'Hi, %s, you have $%d.' % ('Michael', 1000000)
'Hi, Michael, you have $1000000.'
#使用字符串的format()方法，它会用传入的参数依次替换字符串内的占位符{0}、{1}……,{:}中冒号后面是格式控制
>>> 'Hello, {0}, 成绩提升了 {1:.1f}%'.format('小明', 17.125)
'Hello, 小明, 成绩提升了 17.1%'
```
另外用`%%`表示`%`

### 4.python 数据类型list(有序列表)
list（列表）一列东西，类型可以不同。支持的操作有，初始化、增、删、改、查、获取长度
```python
classmate = ['xiaoli', 'xiaowang', 'xiaohong']
print('初始化:',classmate)

classmate.append('xiaohong')
print('尾部追加:',classmate)
classmate.insert(2,'xiaozhao')
print('在序号为的位置插入:',classmate)

classmate.pop()
print('尾部删除:',classmate)
classmate.pop(1)
print('删除序号为2的元素:',classmate)

classmate[1]=123
print('修改序号为1的元素:',classmate)
print('查询序号为2的元素:',classmate[2])
print('查询序号为倒数第1的元素:',classmate[-1])
print('查询序号为倒数第2的元素:',classmate[-2])
print('列表长度:',len(classmate))

>>>python test.py
初始化: ['xiaoli', 'xiaowang', 'xiaohong']
尾部追加: ['xiaoli', 'xiaowang', 'xiaohong', 'xiaohong']
在序号为的位置插入: ['xiaoli', 'xiaowang', 'xiaozhao', 'xiaohong', 'xiaohong']
尾部删除: ['xiaoli', 'xiaowang', 'xiaozhao', 'xiaohong']
删除序号为2的元素: ['xiaoli', 'xiaozhao', 'xiaohong']
修改序号为1的元素: ['xiaoli', 123, 'xiaohong']
查询序号为2的元素: xiaohong
查询序号为倒数第1的元素: xiaohong
查询序号为倒数第2的元素: 123
列表长度: 3
```
### 5.python数据类型tuple(固定有序列表)
tuple数据类型没有pop、insert、append操作，一旦初始化之后，**指向的内容**不能再改变
```python
#只有一个元素
space=(1,)
#如果不写逗号,space变成一个整型，这是因为小括号`()`既表示括号运算也表示tuple，这里python 规定当成小括号运算
space=(1)
#初始化
space=(1,2)
```

### 6.python数据类型dict(字典)
字典就相当于C++中的map，该数据结构查询速度快，但是浪费一些空间，相对于list查询速度随着数据增多而增大，但是不会浪费什么空间。这是一种根据key 去hash出value的方法。key必须是不可变类型。
```python
# 初始化
d = {'Amy': 31, 'Tom': 34, 'Mike': 12}

# 遍历
print('------item----------')
for kv in d.items():
    print(kv)
print('-------maps---------')
for key, value in d.items():
    print('%s -> %s' % (key, value))
print('-------keys---------')
for key in d.keys():
    print(key)
print('-------values---------')
for value in d.values():
    print(value)
print('----------------------')
# 添加数据
d['John'] = 34
print('John:%s' % d['John'])

# 删除数据
d.pop('Tom')

# 更新数据
d['Amy'] = 121
print('------item----------')
for kv in d.items():
    print(kv)
print('--------------------')

# 访问数据
# 直接根据key来访问，如果不存在会报错
mike = d['Mike']
print('Mike:%s' % mike)

# 判断字典中是否存在这个key
if 'Tom' in d:
    print(True)
else:
    print(False)

# 使用get函数来访问，不存在时返回None
lee = d.get('Lee')
print(lee)
# 定制不存在时的返回值
lee = d.get('Lee', -1)
print(lee)

```

**输出结果**
```shell
------item----------
('Amy', 31)
('Tom', 34)
('Mike', 12)
-------maps---------
Amy -> 31
Tom -> 34
Mike -> 12
-------keys---------
Amy
Tom
Mike
-------values---------
31
34
12
----------------------
John:34
------item----------
('Amy', 121)
('Mike', 12)
('John', 34)
--------------------
Mike:12
False
None
-1
```

### 7.python 数据结构 set
set和dict类似，也是一组key的集合，但不存储value。由于key不能重复，所以，在set中，没有重复的key。
要创建一个set，需要提供一个list作为输入集合,实际上，set屏蔽了list中的重复元素,并且set是无序的。
```python
# 初始化
s1 = set([3, 4, 5])
print(s1)
# 初始化
s2 = set({1, 2, 3, 2, 4, 1})
print(s2)
# 添加
s2.add(7)
# 删除
s2.remove(2)
print(s2)
# 交集
print(s1 & s2)
# 并集
print(s1 | s2)
```

**输出结果**
```shell 
{3, 4, 5}
{1, 2, 3, 4}
{1, 3, 4, 7}
{3, 4}
{1, 3, 4, 5, 7}
```

### 8.可变对象与不可变对象
所以，对于不变对象来说，调用对象自身的任意方法，也不会改变该对象自身的内容。相反，这些方法会创建新的对象并返回，这样，就保证了不可变对象本身永远是不可变的。list、set、map都是可变对象，tuple是不可变对象，像None、str也是不变对象。set的元素，map的key都应该是不可变对象，同样tuple里面套着可变对象也是不能作为key或set的元素的。
例如，`(1,[2,3])`不能作为set的元素
### 9.input()返回的数据类型是`str`
### 10.python中的循环
`for...in...`、`while`

### 11.python 中的数据结构
整数、浮点数、字符串、布尔值（支持or、and、not 操作）、空值（不是0，0是有意义的，None 是一个特殊空值）

### 12.python是一门动态语言
python是一门动态语言，其变量类型不固定，即，可以把不同类型的值赋值给同一变量
### 13.Python中没有机制保护一个常亮的值不被改变（用全大写字母变量表示一个常亮）
### 14.python 函数
- 定义函数时，需要确定函数名和参数个数；
- 如果有必要，可以先对参数的数据类型做检查；
- 函数体内部可以用return随时返回函数结果；
- 函数执行完毕也没有return语句时，自动return None。
- 函数可以同时返回多个值，但其实就是一个tuple。
- 函数什么也不做时，可以用`pass`做占位符


 