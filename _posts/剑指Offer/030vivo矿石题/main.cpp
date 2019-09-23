#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
* Welcome to vivo
*/

#define MAX_NUM 101

int solution(int n, int weight[])
{

    // TODO Write your code here
    int rows = 0;
    if (n % 2 == 0) {
        rows = n / 2;
    } else {
        rows = n / 2 + 1;
    }
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += weight[i];
    }
    int cols = sum / 2;

    vector<vector<bool>> dp(rows + 1, vector<bool>(cols + 1, false));
    dp[0][0] = true;

    for (int k = 1; k <= n; k++) {
        for (int i = min(k, rows); i >= 1; i--) {
            for (int v = 1; v <= cols; v++) {
                if (v >= weight[k - 1] && dp[i - 1][v - weight[k - 1]])
                    dp[i][v] = true;
            }
        }
    }

    // for (int r = 0; r <= rows; r++) {
    //     for (int c = 0; c <= cols; c++) {
    //         cout << dp[r][c] << "\t";
    //     }
    //     cout << "\n";
    // }

    int result = 0;
    for (int i = sum / 2; i >= 1; i--) {
        if (dp[rows][i]) {
            result = i;
            break;
        }
    }
    return abs(sum - result - result);
}

int main()
{
    string str("");
    getline(cin, str);
    int a[MAX_NUM];
    int i = 0;
    char* p;
    int count = 0;

    const char* strs = str.c_str();
    p = strtok((char*)strs, " ");
    while (p) {
        a[i] = atoi(p);
        count++;
        p = strtok(NULL, " ");
        i++;
        if (i >= MAX_NUM)
            break;
    }

    int result = solution(count, a);
    cout << result << endl;
    return 0;
}
