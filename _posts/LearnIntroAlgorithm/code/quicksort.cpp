#include <iostream>
#include <vector>
#include <stack>
#include <math.h>

using namespace std;

template <typename T>
int partition1(vector<T>& list, int p, int r)
{
    if (p < 0 || r >= list.size())
        return false;

    T x = list[r]; //主元
    int i = p - 1; //i比主元小的右边界
    for (int j = p; j < r; j++) { //j比主元大的右边界
        if (list[j] <= x) {
            /// 把右边界后面的一个和list[j]交换
            i++;
            T temp = list[j];
            list[j] = list[i];
            list[i] = temp;
        }
    }
    T temp = list[i + 1];
    list[i + 1] = list[r];
    list[r] = temp;
    return i + 1;
}
///1, 75, 3, 16, 90, 29, 101, 56
//从大到小
template <typename T>
int partition2(vector<T>& list, int p, int r)
{
    T x = list[p];
    int i = p - 1;
    int j = r + 1;
    while (true) {
        do {
            j--;
        } while (list[j] <= x);
        do {
            i++;
        } while (list[i] >= x);
        if (i < j) {
            T temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        } else {
            T temp = list[j];
            list[j] = list[p];
            list[p] = temp;
            //std::cout << i << "," << j << std::endl;
            return floor(float(i + j) / 2.0);
        }
    }
}
//从小到大
template <typename T>
int partition3(vector<T>& list, int p, int r)
{
    T x = list[p];
    int i = p;
    int j = r;
    while (true) {
        while (list[j] >= x) {
            j--;
        };
        while (list[i] <= x) {
            i++;
        };
        if (i < j) {
            T temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        } else {
            T temp = list[i - 1];
            list[i - 1] = list[p];
            list[p] = temp;
            //std::cout << i << "," << j << std::endl;
            return ceil(float(i + j) / 2.0);
        }
    }
}
template <typename T>
bool QuickSort1(vector<T>& list, int p, int r)
{
    if (p < 0 || r >= list.size())
        return false;

    if (p < r) {
        int q = partition3(list, p, r);
        for (T val : list) {
            std::cout << val << " ";
        }
        std::cout << "\n";
        QuickSort(list, p, q - 1);
        QuickSort(list, q + 1, r);
    }
    return true;
};

//非递归版本
template <typename T>
void QuickSort2(vector<T>& list, int p, int r)
{
    if (p >= r)
        return;
    stack<T> s;
    s.push(p);
    s.push(r);

    while (!s.empty()) {
        int r = s.top();
        s.pop();
        int p = s.top();
        s.pop();

        std::cout << "left:" << r << "\tright:" << p << std::endl;
        if (p < r) {
            int boundary = partition1(list, p, r);
            // 左区间
            s.push(p);
            s.push(boundary);
            // 右区间
            s.push(boundary + 1);
            s.push(r);
        }
    }
}
int main()
{
    vector<int> a{ 1, 75, 3, 16, 90, 29, 101, 56 };
    QuickSort2(a, 0, a.size() - 1);

    for (int val : a) {
        std::cout << val << " ";
    }
    std::cout << "\n";

    return 1;
}