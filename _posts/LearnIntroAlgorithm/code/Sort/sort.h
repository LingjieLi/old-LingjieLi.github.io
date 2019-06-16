#include <iostream>

/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LearnIntroAlgorithm/code/Sort
* @fileName    sort.h
* @brief       1.基于比较的排序；
*              2.length是有意义的 
*              3.只讨论内部排序（所有数据能够一次加入内存中）
*              4.稳定性
*              5.没有一种排序方法是在所有情况下都是最好的
*              6.从小到大排序 
* @author  lydia <vera71@126.com>
* @date    2019-06-14 21:22:04
*
**/
class Sort {
public:
    ///简单排序算法
    template <typename T>
    static bool bubble_sort(T* data, int length);
    template <typename T>
    static bool selection_sort(T* data, int length);
    template <typename T>
    static bool insertion_sort(T* data, int length);

    ///高级排序算法
    template <typename T>
    static bool shell_sort(T* data, int length);
    template <typename T>
    static bool head_sort1(T* data, int length);
    template <typename T>
    static bool head_sort2(T* data, int length);
    template <typename T>
    static bool quick_sort(T* data, int length);
    template <typename T>
    static bool merge_recursive_sort(T* data, int length);
    template <typename T>
    bool merge_norecursive_sort(T* data, int length);

private:
    template <typename T>
    void Merge(T* data, T* tmp_data, int left, int right, int right_end);
    template <typename T>
    void Merge1(T* data, T* tmp_data, int left, int right, int right_end);
    template <typename T>
    void Swap(T& d1, T& d2);
    template <typename T>
    static void MSort(T* data, T* tmp_data, int left, int right_end);
    template <typename T>
    static void QSort(T* data, int left, int right_end);
    template <typename T>
    static uint Median(T* data, int left, int right_end);
    template <typename T>
    static bool merge_pass(T* data, T* tmp_data, uint length, uint N);
};

/**
* @name     bubble_sort 冒泡排序
* @brief    冒泡排序:   (1)优化:flag=0时，说明数组已经有序，结束排序过程
*                      (2)严格大于，保证是稳定排序
*                      (3)最好情况，数组是排序好的，T=O(N)最坏情况：逆序T=O(N^2)
*                      (4)交换的次数是逆序对的个数
*                       
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-14 21:41:43
* @return
*
**/
template <typename T>
bool Sort::bubble_sort(T* data, int length)
{
    for (uint i = length - 1; i >= 0; i--) {
        bool flag = 0; ///(1)
        for (uint j = 0; j < i; j++) {
            if (data[j] > data[j + 1]) { ///(2)保证算法稳定性
                Swap(data[j], data[j + 1]);
                flag = 1;
            }
        }
        if (!flag) { ///(1)这一趟已经有序
            break;
        }
    }
}
/**
* @name     selection_sort(选择排序)
* @brief    分成两部分，前半部分是有序的，后半部分是无序的
*           从后半部分一次抽取最小元素，与后半部分的起始元素交换
*           T=theat(N^2)
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-15 10:51:53
* @return
*
**/
template <typename T>
bool Sort::selection_sort(T* data, int length)
{
    for (uint i = 0; i < length; i++) {
        uint temp = i;
        for (uint j = i + 1; j < length; j++) { ///找到最小元，浪费时间
            if (data[j] < data[temp]) {
                temp = j;
            }
        }
        T val = data[temp];
        data[temp] = data[i];
        data[i] = val;
    }
    return true;
}
/**
* @name   insertion_sort(插入排序)  
* @brief    分成两部分，前半部分是有序的，后半部分是无序的
            从后半部分一次抽取一张牌，插入前半部分合适的位置
            (1)第0张牌已经有序
            (2)严格小于，保证稳定性
            (3)最好情况，数组是排序好的，T(N)=O(N)最坏情况：逆序T(N)=O(N^2)
            (4)交换的次数是逆序对的个数 T(N,I)=O(N+I) I逆序对的个数
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-14 21:48:02
* @return
*
**/
template <typename T>
bool Sort::insertion_sort(T* data, int length)
{
    for (uint i = 1; i < length; i++) { ///(1)
        T temp = data[i]; ///取出一个元素
        for (uint j = i; j > 0 && data[j - 1] > temp; j--) { ///(2)
            data[j] = data[j - 1]; ///向后移动一位
        }
        data[i] = temp; ///插入取出的元素
    }
    return true;
}

/**
* @name     shell_sort(希尔排序)
* @brief    原始希尔排序 增量序列是D_M=\floor(N/2),D_k=\floor(D_(k+1)/2)
*           最坏情况T(N)=\theta(N^2)  --theta既是上届也是下界，安装N^2增长
*           (1)多个子序列插入排序
*           (2)改进增量序列Sedgewick增量序列
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-15 09:55:20
* @return
*
**/
template <typename T>
bool Sort::shell_sort(T* data, int length)
{
    for (uint D = length / 2; D > 0; D = D / 2) {
        for (uint i = D; i < length; i++) { ///(1)插入排序
            T temp = data[i];
            for (uint j = i; j >= 0 && data[j - D] > temp; j -= D) {
                data[j] = data[j - D];
            }
            data[i] = temp;
        }
    }
    return true;
}
/**
* @name     heap_sort(堆排序) 非原址排序版本
* @brief    选择排序的改进，可以很方便的取得最小元
*           (1)构建最小堆，O(N)
*           (2)删除最小元,O(lgN)
*           (3)复制O(N)
*           (4)时间复杂度O(NlgN)，需要额外空间O(N)
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-15 11:17:05
* @return
*
**/
template <typename T>
bool Sort::head_sort1(T* data, int length)
{
    ///buildMinHeap(data)构建一个最小堆 ///(1)
    ///T *temp=new T[length];
    ///for(uint i=0;i<length;i++){
    ///     temp[i] = deleteMin(data);///(2)
    ///}
    ///for(uint i=0;i<length;i++){///(3)
    ///     data[i] = temp[i];
    ///}
}
/**
* @name     head_sort2(堆排序)，原址排序
* @brief    (1)构建最小堆
*           (2)将最大元素放在最后
*           (3)维度最大堆，向下过滤函数
*           (4)事件复杂度，O(NlogN) 实际应用不如希尔排序Sedgewick增量序列
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-15 16:02:16
* @return
*
**/
template <typename T>
bool Sort::head_sort2(T* data, int length)
{
    // buildMaxHeap(data); ///(1)
    // for (uint i = N - 1; i > 0; i--) {
    //     Swap(data[0], data[i]); ///(2)
    //     PercDown(data, 0, i - 1) ///(3)
    // }
}
/**
* @name
* @brief    在现实情况下是最好的，分治法
*           主元的选取很影响效率，最好的情况是每次主元都位于数据的中间
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-15 22:06:27
* @return
*
**/
template <typename T>
bool Sort::quick_sort(T* data, int length)
{
    uint left = 0, right_end = length - 1;
    if (left < right_end) {
        QSort(left, right_end);
    }
    return true;
}
/**
* @name     merge_sort(归并排序) 递归的 归并法
* @brief    左右部分分别排序，将排序结果归并
*           稳定排序，事件复杂度严格O(NlogN)
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-15 16:33:08
* @return
*
**/
template <typename T>
bool Sort::merge_recursive_sort(T* data, int length)
{
    T* tmp_data = new T[length];
    if (tmp_data != nullptr) {
        MSort(data, tmp_data, 0, length - 1);
        delete[] tmp_data;
    } else {
        return false;
    }
    return true;
}
template <typename T>
bool Sort::merge_norecursive_sort(T* data, int length)
{
    T* tmp_data = new T[length];
    if (tmp_data != nullptr) {
        for (uint i = 1; i <= length / 2; i *= 2) { ///子序列的长度
            merge_pass(data, tmp_data, i, length);
            i *= 2;
            merge_pass(tmp_data, data, i, length);
            i *= 2;
        }

        delete[] tmp_data;
    } else {
        return false;
    }
    return true;
}

template <typename T>
void Sort::Swap(T& d1, T& d2)
{
    T temp = d1;
    d1 = d2;
    d2 = temp;
}
/**
    * @name
    * @brief    两个有序子列的归并
    *           (1)保证稳定性
    *
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-15 16:48:46
    * @return
    *
    **/
template <typename T>
void Sort::Merge(T* data, T* tmp_data, int left, int right, int right_end)
{
    uint i = left;
    uint j = right;
    uint left_end = right - 1;
    uint tmp_idx = left;
    uint num = right_end - left + 1; ///元素数目
    while (i <= left_end && j <= right_end) {
        if (data[i] <= data[j]) { ///(1)
            tmp_data[tmp_idx++] = data[i++];
        } else {
            tmp_data[tmp_idx++] = data[j++];
        }
    }

    while (i <= left_end) {
        tmp_data[tmp_idx++] = data[i];
    }
    while (j <= right_end) {
        tmp_data[tmp_idx++] = data[j++];
    }

    for (uint j = right_end; j > right_end - num; j--) {
        data[j] = tmp_data[j];
    }
}
template <typename T>
void Sort::Merge1(T* data, T* tmp_data, int left, int right, int right_end)
{
    uint i = left;
    uint j = right;
    uint left_end = right - 1;
    uint tmp_idx = left;
    uint num = right_end - left + 1; ///元素数目
    while (i <= left_end && j <= right_end) {
        if (data[i] <= data[j]) { ///(1)
            tmp_data[tmp_idx++] = data[i++];
        } else {
            tmp_data[tmp_idx++] = data[j++];
        }
    }

    while (i <= left_end) {
        tmp_data[tmp_idx++] = data[i];
    }
    while (j <= right_end) {
        tmp_data[tmp_idx++] = data[j++];
    }
}
template <typename T>
void Sort::MSort(T* data, T* tmp_data, int left, int right_end)
{
    if (left < right_end) {
        uint center = (left + right_end) / 2;
        MSort(data, tmp_data, left, center);
        MSort(data, tmp_data, center + 1, right_end);
        Merge(data, tmp_data, left, right_end);
    }
}

template <typename T>
void Sort::QSort(T* data, int left, int right_end)
{
    if (left < right_end) {
        uint median = Median(data, left, right_end);
        uint i = left + 1, j = right_end - 2;
        uint pior = right_end - 1;
        while (i < j) {
            if (data[i] >= data[pior] && data[j] <= data[pior]) {
                Swap(data[i], data[j]);
                i++;
                j--;
            } else if (data[i] < data[pior]) {
                i++;
            } else if (data[j] > data[pior]) {
                j--;
            }
        }
        Swap(data[i], data[pior]);
        QSort(data, left, i - 1);
        QSort(data, i + 1, right_end);
    }
}
/**
* @name
* @brief    将中位数放在right_end-1位置
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-16 11:01:27
* @return
*
**/
template <typename T>
uint Sort::Median(T* data, int left, int right_end)
{
    int median = left + right_end;
    if (T[left] > T[right_end]) {
        Swap(data[left], data[right_end]);
    }
    if (T[median] > T[right_end]) {
        Swap(data[median], data[right_end]);
    }
    if (T[median] < T[left]) {
        Swap(data[median], data[left]);
    }
    Swap(data[median], data[right_end - 1]);
    return median;
}
/**
* @name     (merge_sort)归并排序
* @brief    稳定，最坏O(NlogN),最好，不被用于内排序，常用于外排序
*
* @parm
* @author  lydia <vera71@126.com>
* @date    2019-06-15 22:05:05
* @return
*
**/
template <typename T>
bool Sort::merge_pass(T* data, T* tmp_data, uint length, uint N)
{
    ///一趟归并
    for (uint j = 0; j <= N - 2 * length; j += 2 * length) { ///左边子序列的起始位置，至少还有两个子序列
        Merge1(data, tmp_data, j, j + length, j + 2 * length - 1); ///归并并复制到temp_data中
        if (j + length < N) { ///还有两个子列
            Merge1(data, tmp_data, j, j + length, N - 1);
        } else { ///还有最后一个子列
            for (uint p = j; p < N; p++) {
                tmp_data[p] = data[p];
            }
        }
    }
}
