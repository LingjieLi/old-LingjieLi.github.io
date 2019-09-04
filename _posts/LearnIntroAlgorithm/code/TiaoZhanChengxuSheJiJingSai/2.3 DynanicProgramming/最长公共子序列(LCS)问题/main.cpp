/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-18 15:38:39
 * @Author: lydia
 * @Date: 2019-08-18 14:56:53
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string solve(string s1, string s2)
    {
        string cs = "";
        int rows = s1.length() + 1;
        int cols = s2.length() + 1;
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        ///init
        for (int i = 0; i < rows - 1; i++) {
            for (int j = 0; j < cols - 1; j++) {
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                    cs.push_back(s1[i]);
                } else {
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }

        for (auto vec : dp) {
            for (int val : vec) {
                cout << val << "\t";
            }
            cout << endl;
        }
        return cs;
    }
};

int main()
{
    string s1 = "abcd";
    string s2 = "bcde";

    Solution sol;
    string cs = sol.solve(s1, s2); //common subsequence
    cout << cs.length() << "\t" << cs << "\n";

    return 0;
}