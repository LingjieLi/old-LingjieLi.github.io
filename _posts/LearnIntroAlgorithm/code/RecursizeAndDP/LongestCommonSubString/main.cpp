/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-09 19:10:47
 * @Author: lydia
 * @Date: 2019-08-09 18:50:29
 */

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int LongestCommonSubString(string text1, string text2)
    {
        int rows = text2.size();
        int cols = text1.size();

        int end = 0;
        int length = 0;

        vector<vector<int>> dp;
        dp.resize(rows);
        for (vector<int>& vec : dp) {
            vec.resize(cols);
        }

        dp[0][0] = text1[0] == text2[0] ? 1 : 0;
        for (int r = 1; r < rows; r++) {
            dp[r][0] = min(text2[r] == text1[0] ? dp[r - 1][0] + 1 : dp[r - 1][0], 1);
        }
        for (int c = 1; c < cols; c++) {
            dp[0][c] = min(text1[c] == text2[0] ? dp[0][c - 1] + 1 : dp[0][c - 1], 1);
        }

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (text2[r] == text1[c]) {
                    dp[r][c] = 1 + dp[r - 1][c - 1];
                    if (dp[r][c] > length) {
                        length = dp[r][c];
                        end = c;
                    }
                }
            }
        }

        for (vector<int> vec : dp) {
            for (int c : vec) {
                cout << c << "\t";
            }
            cout << "\n";
        }

        cout << "substring : " << text1.substr(end - length + 1, length) << "\n";

        return length;
    };
};

int main()
{
    string text1 = "1ABC23D567890DEF789";
    string text2 = "ABC3456789";
    Solution sol;
    int length = sol.LongestCommonSubString(text1, text2);

    cout << "length = " << length << "\n";
    ;
    return 1;
}