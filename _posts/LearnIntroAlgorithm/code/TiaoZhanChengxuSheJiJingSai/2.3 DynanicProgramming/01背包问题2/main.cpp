/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-19 16:20:45
 * @Author: lydia
 * @Date: 2019-08-19 10:01:19
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <limits>
#include <math.h>

using namespace std;

class Solution {
public:
    long MAX_WEIGHT = pow(10, 7);
    long MAX_THINGS = 100;
    long SUM_WEIGHT = MAX_WEIGHT * MAX_THINGS;
    int solve(vector<int> weight, vector<int> value, int Weight)
    {
        int rows = weight.size() + 1;
        int cols = 1;
        for (int val : value) {
            cols += val;
        }

        vector<vector<long>> dp(rows, vector<long>(cols, SUM_WEIGHT));
        //初始化数据
        dp[0][0] = 0;
        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < cols; j++) {
                if (j < value[i]) {
                    dp[i + 1][j] = dp[i][j];
                } else {
                    dp[i + 1][j] = min(dp[i][j], dp[i][j - value[i]] + weight[i]);
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << dp[i][j] << "\t";
            }
            cout << endl;
        }

        int res = 0;
        for (int j = 0; j < cols; j++) {
            if (dp[rows - 1][j] <= Weight) {
                res = j;
            }
        }
        return res;
    };
};

int main()
{
    vector<int> weight{ 2, 1, 3, 2 };
    vector<int> value{ 3, 2, 4, 2 };
    int Weight = 5;
    Solution sol;
    int val = sol.solve(weight, value, Weight);
    cout << val << "\n";
    return 0;
}