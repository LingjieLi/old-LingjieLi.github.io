/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/020滑动窗口的最大值
* @fileName    main.cpp
* @brief       给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}； 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}， {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}， {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
*
* @author  lydia <vera71@126.com>
* @date    2019-09-14 22:07:37
*
**/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
    }
};

int main()
{
    vector<int> num{ 2, 3, 4, 2, 6, 2, 5, 1 };
    int size = 5;
    Solution* sol = new Solution;
    vector<int> res = sol->maxInWindows(num, size);

    for (int val : res) {
        cout << val << "\t";
    }
    cout << "\n";
    return 0;
}
