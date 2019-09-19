/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-07 18:36:44
 * @Author: lydia
 * @Date: 2019-09-07 15:40:33
 */
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

//递归做法
/*class Solution {
public:
    int cutRope(int number)
    {
        sumLength = max(sumLength, number);
        if (number == 0) {
            return 1;
        }
        int res = numeric_limits<int>::min();
        for (int i = 1; i <= number && i < sumLength; i++) { //段数>1
            res = max(res, i * cutRope(number - i));
        }
        return res;
    }

private:
    int sumLength = numeric_limits<int>::min();
};*/

//dp做法 带备忘的自顶向下
/*class Solution {
public:
    int cutRope(int number)
    {
        map<int, int> store;
        sumLength = number;
        for (int i = 1; i <= number; i++) {
            store[i] = INT32_MIN;
        }
        store[0] = 1;
        return memorizedCutRodAux(number, store);
    }
    int memorizedCutRodAux(int number, map<int, int>& store)
    {
        if (store[number] >= 0) {
            return store[number];
        }
        int res = INT32_MIN;
        for (int i = 1; i <= number && i < sumLength; i++) {
            res = max(res, i * memorizedCutRodAux(number - i, store));
        }
        store[number] = res;
        return res;
    }
    int sumLength = INT32_MIN;
};*/
//dp作法 自底向上
class Solution {
public:
    int cutRope(int number)
    {
        vector<int> dp(number + 1, INT32_MIN);
        vector<int> store(number + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= number; i++) {
            int res = INT32_MIN;
            int maxj = 0;
            for (int j = 1; j <= i && j < number; j++) {
                if (j * dp[i - j] > res) {
                    maxj = j;
                    res = j * dp[i - j];
                }
            }
            dp[i] = res;
            store[i] = maxj;
        }

        for (int val : store) {
            cout << val << "\t";
        }
        cout << "\n";

        int l1 = store[number];
        int l2 = store[number - l1];
        cout << l1 << "\t" << l2 << "\t";
        while (l2 != 1) {
            l1 = store[l2];
            l2 = store[l2 - l1];
            cout << l1 << "\t" << l2 << "\t";
        }
        cout << "\n";

        // int length = store[number];
        // while (length != 0) {
        //     cout << length << "\t";
        //     length = store[length];
        // }
        return dp[number];
    }
};

int main()
{
    int length = 8;
    cin >> length;
    Solution* sol = new Solution;
    int res = sol->cutRope(length);
    cout << "output: " << res << "\n";
    return 0;
}
