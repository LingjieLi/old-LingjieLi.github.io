/**
* @projectName E:\LingjieLi.github.io\_posts\剑指Offer\034英伟达面试题-数组去重
* @fileName    main.cpp
* @brief       去除一个有序数组中重复的元素，要求时间复杂度O(n) 空间复杂度O(1)
*
* @author  lydia <vera71@126.com>
* @date    2019-09-26 20:53:37
*
**/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int Dereplication(vector<int>& array)
    {
        int left = 0;
        int right = 1;

        while (right < array.size()) {
            //将后面的不断往前复制
            while (right < array.size() && array[left] != array[right]) {
                array[left + 1] = array[right];
                left++;
                right++;
            }
            right++;
        };

        array.resize(left + 1); //O(n)
        return left + 1;
    };
};

int main()
{
    vector<int> data{ 1, 1, 2, 3, 3, 5, 5 };
    Solution sol;
    int size = sol.Dereplication(data);
    cout << size << ":\n";
    for (int val : data) {
        cout << val << " ";
    }
    return 0;
}