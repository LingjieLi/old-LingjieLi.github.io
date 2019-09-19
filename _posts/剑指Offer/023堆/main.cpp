
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
#include <math.h>

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

        cout << size << "\n";
        if (size > capacity) {
            capacity *= 2;
            elements.resize(capacity + 1);
        }
        for (int i = 1; i <= size; i++) {
            elements[i] = data[i - 1];
        }

        //调整最小堆的结构 O(n)时间复杂度
        //从倒数第二层开始操作
        for (int i = parent(size); i >= 1; i--) {
            max_heapfy(i);
        }

        // for (int i = 1; i <= size; i++) {
        //     cout << elements[i] << "\t";
        // }
        // cout << "\n";
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

        elements[size + 1] = val;

        size++;
        //上滤
        for (int i = parent(size); i >= 1; i--) {
            // if (max_heapfy(i)) {
            //     break;
            // }
            max_heapfy(i);
        }

        return true;
    };

    bool deleteMin()
    {
        if (size == 0)
            return false;
        elements[1] = elements[size];
        size--;

        //下滤操作
        for (int i = 1; i <= size / 2; i++) {
            // if (max_heapfy(i)) {
            //     break;
            // }
            max_heapfy(i);
        }
        return true;
    };

    vector<int> getElements(int& _size) const
    {
        _size = size;
        return elements;
    };

private:
    //维护最大堆的性质
    bool max_heapfy(int idx)
    {
        int minestidx = idx;
        int lidx = left(idx);
        int ridx = right(idx);

        if (lidx <= size && elements[minestidx] > elements[lidx]) {
            minestidx = lidx;
        }
        if (ridx <= size && elements[minestidx] > elements[ridx]) {
            minestidx = ridx;
        }

        //swap elements[minestidx] elements[idx]
        if (minestidx != idx) {
            int tmp = elements[idx];
            elements[idx] = elements[minestidx];
            elements[minestidx] = tmp;

            return false;
        }
        return true;
    };
    int left(int idx)
    {
        return 2 * idx;
    };
    int right(int idx)
    {
        return 2 * idx + 1;
    };
    int parent(int idx)
    {
        return floor(idx / 2.0);
    }

private:
    int size = 0; //实际元素数量
    int capacity = 100; //容量

    vector<int> elements; //存储堆元素
};
ostream& operator<<(ostream& out, const MinHeap& heap)
{
    int size = 0;
    vector<int> data = heap.getElements(size);
    cout << size << "\n";
    for (int i = 1; i <= size; i++) {
        out << data[i] << "\t";
    }
    return out;
};
int main()
{
    vector<int> data{ 1, 3, 5, 9, 2, 4, 6, 8 };
    MinHeap heap(data);
    cout << "init:\n"
         << heap << "\n";
    heap.insert(0);
    cout << "insert 0:\n"
         << heap << "\n";
    heap.insert(10);
    cout << "insert 10:\n"
         << heap << "\n";
    heap.insert(7);
    cout << "insert 7:\n"
         << heap << "\n";
    heap.deleteMin();
    cout << "deletemin:\n"
         << heap << "\n";
    heap.deleteMin();
    cout << "deletemin:\n"
         << heap << "\n";
}