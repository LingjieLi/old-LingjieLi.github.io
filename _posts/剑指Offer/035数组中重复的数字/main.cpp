/**
* @projectName E:\LingjieLi.github.io\_posts\剑指Offer\035数组中重复的数字
* @fileName    main.cpp
* @brief
*在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。 例如，如果输入长度为7的数组{2,3,1,0,2,5,3}，那么对应的输出是第一个重复的数字2。
* @author  lydia <vera71@126.com>
* @date    2019-09-26 22:04:50
*
**/

#include <unordered_map>
#include <map>
#include <iostream>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication)
    {
        int idx;
        for (int i = 0; i < length; i++) {
            idx = numbers[i];
            while (idx != i && idx < length) { //值与位置不匹配
                //swap with numbers[idx]
                if (numbers[idx] == idx) {
                    *duplication = idx;
                    return true;
                }
                swap(numbers[idx], numbers[i]);
                idx = numbers[i];
            }
        }
        *duplication = -1;
        return false;
    }
};

int main()
{
    //int a[] = { 2, 3, 1, 2, 3, 2, 0 };
    int a[] = { 2, 1, 3, 0, 4 };

    Solution sol;
    int* dupl = new int();
    bool res = sol.duplicate(a, 7, dupl);
    if (res) {
        cout << *dupl << "\n";
    } else {
        cout << *dupl << "\n";
    }
}