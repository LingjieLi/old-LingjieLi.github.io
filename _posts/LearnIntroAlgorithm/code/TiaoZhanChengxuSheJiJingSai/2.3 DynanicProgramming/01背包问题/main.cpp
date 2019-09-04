/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-19 10:00:56
 * @Author: lydia
 * @Date: 2019-08-16 09:51:09
 */
/// 递归写法

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> _weight, vector<int> _value)
        : weight(_weight)
        , value(_value)
        , n(_weight.size()){};
    ///递归写法
    ///从第i个开始 <=j的最大价值
    int solve1(int i, int j)
    {
        int res = 0; ///最大价值
        if (i == n) {
            res = 0;
        } else if (weight[i] > j) { ///不能选择
            res = solve1(i + 1, j);
        } else {
            res = max(solve1(i + 1, j), solve1(i + 1, j - weight[i]) + value[i]);
        }
        return res;
    };

    ///dp写法
    int solve2(int Weight)
    {
        int rows = n;
        int cols = Weight + 1;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        ///初始化
        for (int j = 0; j < cols; j++) {
            if (j < weight[n - 1]) {
                dp[n - 1][j] = 0;
            } else {
                dp[n - 1][j] = value[n - 1];
            }
        }

        ///开始填写数据
        for (int r = rows - 2; r >= 0; r--) {
            for (int c = 0; c < cols; c++) {
                if (c < weight[r]) { //不选择
                    dp[r][c] = dp[r + 1][c];
                } else {
                    dp[r][c] = max(dp[r + 1][c], dp[r + 1][c - weight[r]] + value[r]);
                }
            }
        }

        ///打印dp
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << dp[r][c] << " ";
            }
            cout << endl;
        }

        return dp[0][cols - 1];
    };

private:
    vector<int> weight; ///重量
    vector<int> value; ///价值量
    int n; ///数据数量
};

int main()
{
    int Weight = 5;
    vector<int> weight{ 2, 1, 3, 2 };
    vector<int> value{ 3, 2, 4, 2 };

    Solution sol(weight, value);
    int res = sol.solve1(0, Weight);
    cout << res << endl;

    res = sol.solve2(Weight);
    cout << res << endl;
    return 0;
}