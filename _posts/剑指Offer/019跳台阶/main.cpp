/**
* @projectName ~/windows_data/LingjieLi.github.io/_posts/剑指Offer/019跳台阶
* @fileName    main.cpp
* @brief      一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
*
* @author  lydia <vera71@126.com>
* @date    2019-09-14 21:52:43
*
**/
#include <vector>
#include <iostream>

using namespace std;
class Solution {
public:
    int jumpFloor(int number)
    {
        if (number == 0) {
            return 0;
        } else if (number == 1) {
            return 1;
        } else {
            vector<int> dp(number, 0); //位于第i级台阶的跳法i<number
            dp[number - 1] = 1;
            dp[number - 2] = 2;

            for (int i = number - 3; i >= 0; i--) {
                dp[i] = dp[i + 1] + dp[i + 2];
            }

            for (int val : dp) {
                cout << val << "\t";
            }
            cout << "\n";
            return dp[0];
        }
    }
};
int main()
{
    int number;
    cin >> number;
    Solution* sol = new Solution;
    int res = sol->jumpFloor(number);
    cout << res << "\n";
}