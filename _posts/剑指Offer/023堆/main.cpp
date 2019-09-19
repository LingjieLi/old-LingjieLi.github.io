
/**
* @projectName E:\LingjieLi.github.io\_posts\剑指Offer\023堆
* @fileName    main.cpp
* @brief       小顶堆
*
* @author  lydia <vera71@126.com>
* @date    2019-09-19 16:48:11
*
**/

#include <vector>
#include <iostream>

using namespace std;

class MinHeap {
public:
    MinHeap(int _capacity = 100)
        : capacity(_capacity)
    {
        elements.resize(capacity + 1);
    };
    MinHeap(vector<int> data, int _capacity = 100)
        : capacity(_capacity)
    {
        size = data.size();
        elements.resize(capacity + 1);
        if (size > capacity) {
            capacity *= 2;
            elements.resize(capacity * 2);
        }
        for (int i = 1; i <= size; i++) {
            elements[i] = data[i - 1];
        }

        //调整最小堆的结构 O(n)时间复杂度
        //从倒数第二层开始操作
        for (int i = size / 2; i >= 1; i--) {
            max_heapfy(i);
        }
    };

    //上滤法
    bool insert(int val)
    {
        if (size >= capacity) {
            capacity *= 2;
            vector<int> tmp(capacity + 1);
            for (int i = 1; i <= size; i++) {
                tmp[i] = elements[i];
            }
            elements = tmp;
        }

        size++;
    };

    bool deleteMin(){};

private:
    //维护最大堆的性质
    void max_heapfy(int idx)
    {
        int minestidx;
        int lidx = left(idx);
        int ridx = right(idx);

        if (elements[minestidx] > elements[lidx]) {
            minestidx = lidx;
        }
        if (elements[minestidx] > elements[ridx]) {
            minestidx = ridx;
        }

        //swap elements[minestidx] elements[idx]
        if (minestidx != idx) {
            int tmp = elements[idx];
            elements[idx] = elements[minestidx];
            elements[minestidx] = tmp;
        }
    };
    int left(int idx)
    {
        return 2 * idx;
    };
    int right(int idx)
    {
        return 2 * idx + 1;
    };

private:
    int size = 0; //实际元素数量
    int capacity = 100; //容量

    vector<int> elements; //存储堆元素
};

int main()
{
}