/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-18 19:54:08
 * @Author: lydia
 * @Date: 2019-08-18 15:57:08
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    Solution(vector<int> _weight, vector<int> _value)
        : weight(_weight)
        , value(_value)
        , n(_weight.size())
    {
        weight.insert(weight.begin(), 0);
        value.insert(value.begin(), 0);
    };

    ///O(nW^2)
    int solve1(int Weight)
    {
        int rows = n + 1;
        int cols = Weight + 1; //[0,Weight]

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                int K = j / weight[i]; //最多能放几个
                int tmp = dp[i - 1][j]; //不使用
                for (int k = 1; k <= K; k++) {
                    if (dp[i - 1][j - k * weight[i]] + k * value[i] > tmp) {
                        tmp = dp[i - 1][j - k * weight[i]] + k * value[i];
                    }
                }
                dp[i][j] = tmp;
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << dp[r][c] << "\t";
            }
            cout << endl;
        }

        return dp[rows - 1][cols - 1];
    };

    ///O(nW) 改进dp
    int solve2(int Weight)
    {
        int rows = n + 1;
        int cols = Weight + 1; //[0,Weight]

        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (j >= weight[i]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i]] + value[i]);
                } else { ///不使用
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                cout << dp[r][c] << "\t";
            }
            cout << endl;
        }

        return dp[rows - 1][cols - 1];
    }

private:
    vector<int> weight; ///重量
    vector<int> value; ///价值量
    int n; ///数据数量
};

int main()
{
    int Weight = 7;
    vector<int> weight{ 3, 4, 2 };
    vector<int> value{ 4, 5, 3 };
    Solution sol(weight, value);
    int val = sol.solve1(Weight);
    cout << val << "\n";
    ///改进dp
    val = sol.solve2(Weight);

    cout << "improve:" << val << "\n";
    return 0;
}