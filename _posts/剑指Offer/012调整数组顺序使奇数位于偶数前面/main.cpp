/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/012调整数组顺序使奇数位于偶数前面
* @fileName    main.cpp
* @brief 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和* 奇数，偶数和偶数之间的相对位置不变。
*
* @author  lydia <vera71@126.com>
* @date    2019-09-12 20:20:53
*
**/
#include <vector>
#include <iostream>
using namespace std;

//插入排序思想 稳定排序
class Solution {
public:
    void reOrderArray(vector<int>& array)
    {

        if (array.size() < 2) {
            return;
        }

        //[0,i)奇数
        //[i,  未知
        for (int i = 0; i < array.size(); i++) {
            cout << array[i] << "\t\t";
            if (isOdd(array[i])) { //奇数
                for (int j = i; j >= 1; j--) {
                    if (!isOdd(array[j - 1])) { //偶数
                        //swap
                        int tmp = array[j - 1];
                        array[j - 1] = array[j];
                        array[j] = tmp;
                    } else {
                        break;
                    }
                }
            } else {
            }
            print(array);
        }
    }

private:
    bool isOdd(int value) //奇数
    {
        return value % 2 != 0;
    }
    void print(vector<int> array)
    {
        for (int val : array) {
            cout << val << "\t";
        }
        cout << "\n";
    }
};

int main()
{
    vector<int> array{ 1, 2, 3, 4, 5, 6 };
    Solution* sol = new Solution;
    sol->reOrderArray(array);
    return 0;
}