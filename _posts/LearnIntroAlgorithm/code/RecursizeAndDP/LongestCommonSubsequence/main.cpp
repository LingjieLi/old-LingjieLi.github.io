/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-09 13:13:03
 * @Author: lydia
 * @Date: 2019-08-09 10:07:19
 */

#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int cols = text1.size();
        int rows = text2.size();

        vector<vector<int>> dp;
        dp.resize(rows);
        for (vector<int>& vec : dp) {
            vec.resize(cols);
        }

        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (int r = 1; r < rows; r++) {
            dp[r][0] = min(text2[r] == text1[0] ? 1 : 0 + dp[r - 1][0], 1);
        }
        for (int c = 1; c < cols; c++) {
            dp[0][c] = min(text2[0] == text1[c] ? 1 : 0 + dp[0][c - 1], 1);
        }

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {

                int inc = text2[r] == text1[c] ? 1 : 0;
                int cur = max(dp[r - 1][c], dp[r][c - 1]);
                dp[r][c] = max(dp[r - 1][c - 1] + inc, cur);
            }
        }

        return dp[rows - 1][cols - 1];
    }
};

int main()
{
    string text1 = "hofubmnylkra";
    string text2 = "pqhgxgdofcvmr";
    Solution sol;
    int length = sol.longestCommonSubsequence(text1, text2);

    cout << "length = " << length << "\n";
    return 1;
};