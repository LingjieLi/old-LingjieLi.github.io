/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LearnIntroAlgorithm/code/ExchangeMoney
* @fileName    exchangecoins3.cpp
* @brief       动态规划
*
* @author  lydia <vera71@126.com>
* @date    2019-08-07 16:27:15
*
**/

#include <vector>
#include <iostream>

using namespace std;
int exchangemoney(vector<int> arr, int aim);

int main()
{
    vector<int> arr{ 5, 10, 15, 1 };
    int aim = 9;

    int ways = exchangemoney(arr, aim);
    cout << "ways : " << ways << "\n";
    return 0;
}

int exchangemoney(vector<int> arr, int aim)
{
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }

    int rows = arr.size();
    int cols = aim + 1;

    vector<vector<int>> dp;
    dp.resize(rows);
    for (vector<int>& vec : dp) {
        vec.resize(cols);
    }

    for (int r = 0; r < rows; r++) {
        dp[r][0] = 1;
    }
    for (int c = 0; arr[0] * c <= aim; c++) {
        dp[0][arr[0] * c] = 1;
    }

    int num = 0;
    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            num = 0;
            for (int k = 0; c - arr[r] * k >= 0; k++) {
                num += dp[r - 1][c - arr[r] * k];
            }
            dp[r][c] = num;
        }
    }

    for (vector<int> vec : dp) {
        for (int v : vec) {
            cout << v << "\t";
        }
        cout << "\n";
    }
    return dp[rows - 1][cols - 1];
}