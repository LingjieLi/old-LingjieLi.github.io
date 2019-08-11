#include <iostream>
#include <vector>

using namespace std;

int exchangemoney(vector<int> arr, int aim);

int main()
{
    vector<int> arr{ 5, 10, 15, 1 };
    int aim = 9;

    int ways = exchangemoney(arr, aim);
    cout << "ways : " << ways << "\n";
    return 0;
};

int exchangemoney(vector<int> arr, int aim)
{
    if (arr.size() == 0 || aim < 0) {
        return 0;
    }
    int rows = arr.size();
    int cols = aim + 1;

    vector<int> dp;
    dp.resize(aim + 1);

    for (int j = 0; arr[0] * j <= aim; j++) {
        dp[arr[0] * j] = 1;
    }

    for (int i = 1; i < arr.size(); i++) {
        for (int j = 1; j <= aim; j++) {
            dp[j] += j - arr[i] >= 0 ? dp[j - arr[i]] : 0;
        }
    }

    return dp[aim];
};