/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/018变态跳台阶
* @fileName    main.cpp
* @brief       一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
*
* @author  lydia <vera71@126.com>
* @date    2019-09-14 21:34:26
*
**/

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int jumpFloorII(int number)
    {
        vector<int> dp(number, 0); //位于第i(i<n)级台阶总共有多少种跳法
        dp[number - 1] = 1;
        for (int i = number - 2; i >= 0; i--) {
            for (int j = i + 1; j < number; j++) {
                dp[i] += dp[j];
            }
            dp[i] += 1;
        }

        // for (int val : dp) {
        //     cout << val << "\t";
        // }
        // cout << "\n";

        return dp[0];
    }
};

int main()
{
    int n = 10;
    cin >> n;
    Solution* sol = new Solution;
    int res = sol->jumpFloorII(n);
    cout << res << "\n";
    return 0;
}