/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LearnIntroAlgorithm/code/ExchangeMoney
* @fileName    exchangecoins4.cpp
* @brief
*
* @author  lydia <vera71@126.com>
* @date    2019-08-07 21:02:00
*
**/
#include <iostream>
#include <vector>

using namespace std;

int exchangemoney(vector<int> arr, int aim)
{
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }
    int rows = arr.size();
    int cols = aim + 1;

    vector<vector<int>> dp;
    dp.resize(rows);
    for (auto& vec : dp) {
        vec.resize(cols);
    }

    for (int r = 0; r < rows; r++) {
        dp[r][0] = 1;
    }
    for (int c = 0; arr[0] * c <= aim; c++) {
        dp[0][arr[0] * c] = 1;
    }

    for (int r = 1; r < rows; r++) {
        for (int c = 1; c < cols; c++) {
            dp[r][c] = dp[r - 1][c];
            dp[r][c] += c - arr[r] >= 0 ? dp[r][c - arr[r]] : 0;
        }
    }

    for (vector<int> vec : dp) {
        for (int v : vec) {
            cout << v << "\t";
        }
        cout << "\n";
    }

    return dp[rows - 1][cols - 1];
};

int main()
{
    vector<int> arr{ 5, 10, 15, 1 };
    int aim = 9;

    int ways = exchangemoney(arr, aim);
    cout << "ways : " << ways << "\n";
    return 0;
};
