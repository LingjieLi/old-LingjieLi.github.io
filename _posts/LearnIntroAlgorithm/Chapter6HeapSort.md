## Chapter6 堆排序(HeapSort)
学习这一章后，我才明白堆，指的是二叉堆，例如C++中的map就是使用最大堆来保存数据，所以当我们无论使用[]操作符或者使用迭代获取数据时，和插入时的顺序并不相同

[TOC]
```
Chapter6 堆排序(HeapSort)
 - 6.1堆
 - 6.2维护堆的性质
 - 6.3建立最大堆
 - 6.4堆排序算法
	- 6.4.1堆排序算法的基本思想 
	- 6.4.2堆排序算法的伪代码
	- 6.4.3最大堆类
 - 6.5优先队列
 	- 6.5.1优先队列
 	- 6.5.2最大优先队列的操作
 	- 6.5.3支持最大优先队列的最大堆
 	- 6.5.4最大优先队列 
 - 课后练习
 - SaySomting
```
```
代码索引
6.2维护堆的性质
 - 递归版本维护堆的性质
 - 非递归版本维护堆的性质
6.3建立最大堆
 - 建立最大堆
6.4最大堆类
 - 最大堆类
6.5优先队列
 - 支持最大优先队列的最大堆
 - 最大优先队列
```

### 6.1堆
什么是堆？简言之，堆是一个数组，可以把它看成一个近似的完全二叉树，除最底层外，该树是完全充满的，而且叶子节点从左到右填充。
树的根节点为A[1],根据节点下标可以很容易计算出，其左右孩子节点和父节点
```
PARENT(i)
	return \floor i \rfloor

LEFT(i)
	return 2*i
	
RIGHT(i)
	return 2*i+1
```
堆有两种：最大堆和最小堆。堆有两种属性：数组的长度(length)和堆的长度(heap_size)$0\leq heap\_size \leq length$,也就是说数组中的某些元素可能不是堆中的元素
我们为什么可以把堆看成一个近似完全二叉树呢？关键就在于存在如下性质：
除$i=1$外
最大堆：$A[PARENT(i)]\geq A[i]$
最大堆：$A[PARENT(i)]\leq A[i]$
### 6.2维护堆的性质
下列的维护最大堆代码使用了递归，1.递归存在入栈入栈，耗费时间；2.函数调用存在栈中，如果树太深可能会导致stack overflow栈溢出。

**[递归版本维护堆的性质]**
```cpp
static void max_heapify(Heap &heap,int i)
{
	int l=LEFT(i);
	int r=RIGHT(i);
	int largest;

	if(l<=heap.heap_size&&heap[l]>heap[i])
	{
		largest=l;
	}
	else
	{
		largest=i;
	}

	if(r<=heap.heap_size&&heap[r]>heap[largest])
	{
		largest=r;
	}

	if(largest!=i)
	{
		T temp=heap[i];
		heap[i]=heap[largest];
		heap[largest]=temp;
		max_heapify(heap,largest);
	}
};
```

**[非递归版本维护堆的性质]**
```cpp

```
### 6.3建立最大堆

```cpp
static void build_max_heap(Heap &heap)
{
	heap.heap_size=heap.length;
	for(int i=heap.length/2;i>0;i--)
	{
		max_heapify(heap,i);
	}
};
```
### 6.4堆排序算法
编写了最大堆模板，这个模板是基于基本类型(char int float double)的，因为里面的比较运算都是基于这些基本类型的

##### 6.4.1堆排序算法的基本思想：
1. 构建最大堆。根据最大堆的性质，此时最大值位于堆的根部；
2. 将堆根A[1]和A[i](i=length)互换。此时，A[1]的所有子树都是最大堆，堆元素-1；
3. 在A[1]维护最大堆的性质。之后，又变成最大堆;
4. 将A[1]与A[i](i=length-1)互换，如此重复2,3步骤，至i=2。

##### 6.4.2堆排序算法的伪代码
```
HEAPSORT(A)
    build_max_heap(A);
    for i=length downto 2
    {
    	A[1] exchange A[i];
        A.heap_size--;//堆中数据减一
        max_heapify(A,1);//维护最大堆
    }
```
##### 6.4.2最大堆类

**[测试代码]**
```cpp
#include <cstdlib>
#include <iostream>
#include <utility>

#include "Heap.h"
using namespace std;

int main()
{
    //最大堆测试代码
    int length;
    int *A;
    cin>>length;
    A=new int[length];

    for(int i=0;i<length;i++)
    {
        cin>>A[i];
    }

    Heap<int> heap=Heap<int>(A,length);
    heap.print_heap_length();
    Heap<int>::build_max_heap(heap);
    heap.print_heap_length();
    Heap<int>::heap_sort(heap);
    heap.print_heap_length();[](http://)
    
    system("pause");
    return 0;
}
```

**[测试用例]**
```cpp
input:
10
1 0 6 3 8 6 2 4 18 3
output:
1 0 6 3 8 6 2 4 18 3
18 8 6 4 3 6 2 0 3 1
0 1 2 3 3 4 6 6 8 18

```


**[最大堆类]**
```cpp
/**
*Author:lydia  lydia71@163.com
*Function:二叉堆,基本类型最大堆
*
*Input:length,A*
*Output:
*
*Case:
*Input:
*Output:
*/
#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <cstddef>

template <typename T>
class Heap
{
    public:
        Heap()
        {
            std::cout<<"empty construct"<<std::endl;
        };
        Heap(T *A,int length)
        {
            delete []this->A;
            this->length=length;
            this->heap_size=length;
            this->A=new T[length];

            for(int i=0;i<length;i++)
            {
                this->A[i]=A[i];
            }
        };
        virtual ~Heap()
        {
            delete []A;
        };

        T &operator[](int index)
        {
            return this->A[index-1];
        };

        void print_heap_size()
        {
            for(int i=0;i<heap_size;i++)
            {
                std::cout<<A[i]<<" ";
            }
            std::cout<<std::endl;
        };
        void print_heap_length()
        {
            for(int i=0;i<length;i++)
            {
                std::cout<<A[i]<<" ";
            }
            std::cout<<std::endl;
        };

    public:
        //建立最大堆
        static void build_max_heap(Heap &heap)
        {
            heap.heap_size=heap.length;
            for(int i=heap.length/2;i>0;i--)
            {
                max_heapify(heap,i);
            }
        };
        //维护最大堆
        static void max_heapify(Heap &heap,int i)
        {
            int l=LEFT(i);
            int r=RIGHT(i);
            int largest;

            if(l<=heap.heap_size&&heap[l]>heap[i])
            {
                largest=l;
            }
            else
            {
                largest=i;
            }

            if(r<=heap.heap_size&&heap[r]>heap[largest])
            {
                largest=r;
            }

            if(largest!=i)
            {
                T temp=heap[i];
                heap[i]=heap[largest];
                heap[largest]=temp;
                max_heapify(heap,largest);
            }
        };
        //堆排序算法
        static void heap_sort(Heap &heap)
        {
            build_max_heap(heap);
            for(int i=heap.length;i>1;i--)
            {
                int temp=heap[1];
                heap[1]=heap[i];
                heap[i]=temp;

                heap.heap_size--;
                max_heapify(heap,1);
            }
        };
        static int LEFT(int i)
        {
            return 2*i;
        };
        static int RIGHT(int i)
        {
            return 2*i+1;
        };
        static int PARENT(int i)
        {
            return i/2;
        };

    public:
        int heap_size=0;  //堆长度
        int length=0;     //堆中数据数目

    private:
        T *A=NULL;

};

#endif // HEAP_H

```
### 6.5优先队列
##### 6.5.1优先队列
优先队列是来维护一组元素构成的集合S的数据结构，其中每一个元素都有一个相关的值，称为**关键字key**。
这里的key可以是优先级，例如key越大，优先级越低。在计算机系统中的作业调度，可将一系列作业存储在优先队列中。将x视为一个作业，x.key视为其优先级，x.key值越大，优先级越低。那么，我们可以据key的大小将作业排序，按照优先级由高到底执行，当作业执行完毕或中断时，从队列中删除该作业；也可以选择出优先级最大的作业执行，或者将一作业插入至队列中，或将一作业的优先级提高。

至于，优先队列为什么叫优先·队列，就不知道啦，或许是指此队列中有元素被优待(最大优先队列中key值大的，最小优先队列中key值小的)

#####6.5.2最大优先队列的操作
```
INSERT(S,x);//将作业插入至优先队列S中
MAXINUM(S);//返回优先队列S中具有最大键字的元素
EXARACT_MAX(S);//删除并返回S中具有最大键字的元素
INCREASE_KEY(S,x,k);//将S中x元素x的键字升为k,假设x的键字不大于key
```
##### 6.5.3支持最大优先队列的最大堆
~~[由于最大优先队列中存在**关键字key**这一概念，我考虑到使用c++中的```std::pair<int,Class T>```类型来表示队列中元素比较合适，其**first**属性作为**关键字key**值,其second属性作为内容。]~~
我使用结构体保存元素
```cpp
template <typename T>
struct Node
{
    int key;
    T contain;
};
```

**[测试代码]**
```cpp
int length;
cin>>length;
PairMaxHeap<string> *heap;
Node<string> *A=new Node<string>[length];
for(int i=0;i<length;i++)
{
	cin>>A[i].key>>A[i].contain;
}
std::cout<<"最大堆赋值:\n";
heap=new PairMaxHeap<string>(A,length);
heap->print_heap_length();
//建立最大堆
std::cout<<"建立最大堆:\n";
PairMaxHeap<string>::build_max_heap(*heap);
heap->print_heap_length();
//最大堆排序
std::cout<<"最大堆排序:\n";
PairMaxHeap<string>::heap_sort(*heap);
heap->print_heap_length();
```
**[测试用例]**
```cpp
10
6 ,
1 ,
2 i
5 world
7 do
4 the
9 ?
3 love
8 you
0 lydia
output:
最大堆赋值:
6 1 2 5 7 4 9 3 8 0
, , i world do the ? love you lydia
建立最大堆:
9 8 6 5 7 4 2 3 1 0
? you , world do the i love , lydia
最大堆排序:
0 1 2 3 4 5 6 7 8 9
lydia , i love the world , do you ?
```
**[支持最大优先队列的最大堆]**
```cpp
/**
*Author:lydia  lydia71@163.com
*Function:支持最大优先队列的最大堆
*
*Input:pair*A,length
*Output:
*
*Case:
*Input:
*Output:
*/
#ifndef PAIRMAXHEAP_H
#define PAIRMAXHEAP_H

#include <utility>
#include <iostream>


template <typename T>
struct Node
{
    int key;
    T contain;
};
template <typename T>
class PairMaxHeap
{
public:
    PairMaxHeap(){};
    PairMaxHeap( Node<T> *A, int length )
    {
        this->length=length;
        this->heap_size=length;
        this->array_length=2*length;

        this->A=new Node<T>[array_length];

        for(int i=0;i<length;i++)
        {
            this->A[i]=A[i];
        }
    };
    //获取最大堆的index个元素
    Node<T> &operator[](int index)
    {
        if(index<=length)
        {
            return A[index-1];
        }
        else if(index==length+1&&index<=array_length)//赋值
        {
            length++;
            return A[index-1];
        }
        else if(index==length+1&&index>array_length)
        {
            array_length=2*index;
            Node<T> *temp=new Node<T>[array_length];
            for(int i=0;i<length;i++)
            {
                temp[i]=A[i];
            }
            delete []A;
            A=NULL;
            A=temp;
            length++;
            return A[index-1];
        }
        else{
            A[0];
        }
    };
    void print_heap_size()
    {
        for( int i = 0; i < heap_size; i++ )
        {
            std::cout << A[i].key << "\t";
        }
        std::cout<<std::endl;
        for( int i = 0; i < heap_size; i++ )
        {
            std::cout << A[i].contain << "\t";
        }
        std::cout<<std::endl;
    };
    void print_heap_length()
    {
        for( int i = 0; i < length; i++ )
        {
            std::cout << A[i].key << "\t";
        }
        std::cout<<std::endl;
        for( int i = 0; i < length; i++ )
        {
            std::cout << A[i].contain << "\t";
        }
        std::cout<<std::endl;
    };
    virtual ~PairMaxHeap() {delete []A;}

public:
    //建立最大堆
    static void build_max_heap(PairMaxHeap &heap)
    {
        heap.heap_size=heap.length;
        for(int i=heap.length/2;i>0;i--)//最大堆的叶子节点位于length/2之后
        {
            max_heapify(heap,i);
        }
    };
    //维护最大堆的性质heap[i]的所有子树都为最大堆
    static void max_heapify(PairMaxHeap &heap,int i)
    {
        int l=LEFT(i);
        int r=RIGHT(i);
        int largest;
        if(l<=heap.heap_size&&heap[l].key>heap[i].key)
        {
            largest=l;
        }
        else
        {
            largest=i;
        }

        if(r<heap.heap_size&&heap[r].key>heap[largest].key)
        {
            largest=r;
        }

        if(largest!=i)
        {
            Node<T> temp=heap[i];
            heap[i]=heap[largest];
            heap[largest]=temp;

            max_heapify(heap,largest);
        }
    };
    //堆排序算法
    static void heap_sort(PairMaxHeap &heap)
    {
        build_max_heap(heap);
        for(int i=heap.length;i>1;i--)
        {
            Node<T> temp=heap[1];
            heap[1]=heap[i];
            heap[i]=temp;

            heap.heap_size--;
            max_heapify(heap,1);
        }
    };

public:
    static int LEFT(int i){return 2*i;};
    static int RIGHT(int i){return 2*i+1;};
    static int PARENT(int i){return i/2;};//向下取整
public:
    int length;//数组长度
    int heap_size;//堆中元素个数
private:
    Node<T> *A;
    int array_length;

};

#endif // PAIRMAXHEAP_H

```

##### 6.5.4 最大优先队列
**[伪代码]**
```
MAXINUM(S)
	S[1]//最大堆的第一个元素为最大元素
	

EXARACT_MAX(S)
	exchange S[1] and S[length]
	S.length--
	S.heap_size--
	max_heapify(S,1)//第一个元素的子树都是最大堆
	
INCREASE_KEY(S,i,k);//将第i个元素的键值增大为k
	if k<S[i].key
		error"k is smaller than current key"
	A[i].key=k
	while i>1&&A[PARENT(i)].key<A[i].key
		exchange A[PARENT[i]] and A[i]
		i=PARENT[i]
		
INSERT(S,x)
	S.heap_size++;
	S[S.heap_size]=x
	S[S.heap_size].key=infinity
	INCREASE_KEY(S,S.heap_size,x.key)
```

**[测试代码]**
```cpp
    int length;
    cin >> length;
    Node<string>*A = new Node<string>[length];

    for( int i = 0; i < length; i++ )
    {
        cin >> A[i].key >> A[i].contain;
    }

    priQueue<string> pri_queue = priQueue<string>( A, length );
    std::cout<<"\n最大优先队列:"<<std::endl;
    pri_queue.print();

    std::cout<<"\n添加元素";
    string str[]={"to","be","or","not","to","be","that","is","a","question","."};
    for(int i=11;i<=21;i++)
    {
        Node<string> insert_node;
        insert_node.key=i;
        insert_node.contain=str[i-11];
        pri_queue.insert(insert_node);

        std::cout<<"<"<<insert_node.key<<","<<insert_node.contain<<">"<<" ";
    }
    std::cout<<std::endl;
    pri_queue.print();

    Node<string> max_ele=pri_queue.extract_max();
    std::cout<<"\n删除最大元素:"<<std::endl;
    pri_queue.print();
    std::cout<<"最大元素:"<<max_ele.key<<" "<<max_ele.contain<<std::endl;

    max_ele=pri_queue.maximum();
    std::cout<<"\n返回最大元素:"<<std::endl;
    pri_queue.print();
    std::cout<<"最大元素:"<<max_ele.key<<" "<<max_ele.contain<<std::endl;
```

**[测试用例]**
```cpp
input:
10
6 ,
1 ,
2 i
5 world
7 do
4 the
9 ?
3 love
8 you
0 lydia
output:
最大优先队列:
9       8       6       5       7       4       2       3       1       0
?       you     ,       world   do      the     i       love    ,       lydia

添加元素<11,to> <12,be> <13,or> <14,not> <15,to> <16,be> <17,that> <18,is> <19,a> <20,question> <21,.>
21      20      14      17      19      11      13      9       16      18      7       4       6       2       12      3       5       1       15      0       8
.       question        not     that    a       to      or      ?       be      is      do      the     ,       i       be      love    world   ,       to      lydia   you

删除最大元素:
20      19      14      17      18      11      13      9       16      8       7       4       6       2       12      3       5       1       15      0
question        a       not     that    is      to      or      ?       be      you     do      the     ,       i       be      love    world   ,       to      lydia
最大元素:21 .

返回最大元素:
20      19      14      17      18      11      13      9       16      8       7       4       6       2       12      3       5       1       15      0
question        a       not     that    is      to      or      ?       be      you     do      the     ,       i       be      love    world   ,       to      lydia
最大元素:20 question
```

**[最大优先队列]**
```cpp
/**
*Author:lydia  lydia71@163.com
*Function:最大优先队列
*
*Input:
*Output:
*
*Case:
*Input:
*Output:
*/
#ifndef PRIQUEUE_H
#define PRIQUEUE_H

#include <utility>
#include <string>
#include <cstddef>
#include <limits>

#include "PairMaxHeap.h"

using namespace std;
template <typename T>
class priQueue
{
public:
    priQueue( Node<T> *A, int length )
    {
        this->length=length;
        Node<T> *tempA=NULL;
        tempA=new Node<T>[length];
        for(int i=0;i<length;i++)
        {
            tempA[i]=A[i];
            //std::cout<<A[i].first<<"\t"<<A[i].second<<std::endl;
        }

        heap=new PairMaxHeap<T>(tempA,length);

        PairMaxHeap<T>::build_max_heap(*heap);
        delete []tempA;
    };
    bool insert( const Node<T> &x )
    {
        heap->heap_size++;
        Node<T> insert_node=x;
        insert_node.key=std::numeric_limits<int>::min();
        (*heap)[heap->heap_size]=insert_node;
        //heap->print_heap_length();
        if(increase_key(heap->heap_size,x.key))
        {
            return true;
        }

        return false;
    };
    const Node<T> &maximum()
    {
        return (*heap)[1];
    };
    const Node<T> &extract_max()
    {
        Node<T> temp = (*heap)[1];
        (*heap)[1] = (*heap)[heap->length];
        (*heap)[heap->length] = temp;

        heap->heap_size--;
        heap->length--;
        PairMaxHeap<T>::max_heapify( *heap, 1 );

        return temp;
    };
    bool increase_key( int i, int k )//将元素i的关键字，增加至k
    {
        if(k<(*heap)[i].key)
        {
            std::cout<<"ERROR:new key is smaller than current!"<<std::endl;
            return false;
        }
        (*heap)[i].key=k;
        int parenti=PairMaxHeap<T>::PARENT(i);
        while(i>1&&(*heap)[parenti].key<(*heap)[i].key)
        {
            Node<T> temp=(*heap)[i];
            (*heap)[i]=(*heap)[parenti];
            (*heap)[parenti]=temp;
            i=parenti;
            parenti=PairMaxHeap<T>::PARENT(i);
        }
        return true;
    };

public:
    void print()
    {
        heap->print_heap_length();
    }
    virtual ~priQueue()
    {};

protected:

private:
    int length = 0;
    PairMaxHeap<string> *heap=NULL;
};

#endif // PRIQUEUE_H

```
### 课后练习

### SaySomting