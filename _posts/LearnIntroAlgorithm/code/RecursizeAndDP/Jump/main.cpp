/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-09 19:42:01
 * @Author: lydia
 * @Date: 2019-08-09 19:30:36
 */
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int Jump(vector<int> arr)
    {
        if (arr.size() == 0) {
            return 0;
        }
        int steps = 0, cur = 0 /*跳steps步最远距离*/, next = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (cur < i) {
                steps++;
                cur = next;
            }
            next = max(next, i + arr[i]);
        }
        return steps;
    };
};

int main()
{
    vector<int> arr{ 3, 2, 3, 1, 4 };
    Solution sol;
    int steps = sol.Jump(arr);
    cout << "steps = " << steps << "\n";
    return 1;
}