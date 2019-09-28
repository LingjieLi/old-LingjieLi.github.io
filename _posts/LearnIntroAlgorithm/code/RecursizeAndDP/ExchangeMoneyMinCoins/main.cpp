#include <vector>
#include <limits>
#include <iostream>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount)
    {
        if (coins.size() == 0 || amount < 0) {
            return -1;
        }

        int rows = coins.size();
        int cols = amount + 1;

        int max_num = std::numeric_limits<int>::max();

        vector<vector<int>> dp;
        dp.resize(rows);
        for (vector<int>& vec : dp) {
            vec.resize(cols);
        }

        for (int c = 1; c < cols; c++) {
            dp[0][c] = max_num;
            if (c - coins[0] >= 0 && dp[0][c - coins[0]] != max_num) {
                dp[0][c] = dp[0][c - coins[0]] + 1;
            }
        }

        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                int left = max_num;
                if (c - coins[r] >= 0 && dp[r][c - coins[r]] != max_num) { //1个coins[r] vs 0个coins[r]
                    left = dp[r][c - coins[r]] + 1;
                }
                dp[r][c] = min(left, dp[r - 1][c]);
            }
        }

        // for (vector<int> vec : dp) {
        //     for (int v : vec) {
        //         cout << v << "\t";
        //     }
        //     cout << "\n";
        //}

        return dp[rows - 1][cols - 1] != max_num ? dp[rows - 1][cols - 1] : -1;
    }
};

int main()
{
    vector<int> coins{ 1, 2, 5 };
    int amount = 11;
    Solution sol;
    int size = sol.coinChange(coins, amount);
    cout << size << "\n";
    return 1;
}