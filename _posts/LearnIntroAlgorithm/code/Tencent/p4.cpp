/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-01 21:29:39
 * @Author: lydia
 * @Date: 2019-09-01 21:29:39
 */
#include <iostream>
#include <vector>
#include <stack>
#include <time.h>
#include <algorithm>
using namespace std;

int Sum(vector<int>& num, int i, int j) //计算num[i]到num[j]的和
{
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += num[k];
    }
    return sum;
}

int func(vector<int>& num)
{
    stack<long long> s;
    long long sum = 0;
    long long maxSum = 0;
    int size_n = num.size();

    for (int i = 0; i < size_n; i++) {
        if (s.empty() || num[i] >= num[s.top()]) {
            s.push(i);
        } else {
            while (!s.empty() && num[s.top()] >= num[i]) {
                long long top = s.top();
                s.pop();
                long long tmp = s.empty() ? Sum(num, 0, i - 1) : Sum(num, s.top() + 1, i - 1);
                long long curSum = num[top] * tmp;
                maxSum = max(curSum, maxSum);
            }
            s.push(i);
        }
    }
    while (!s.empty()) {
        long long top = s.top();
        s.pop();
        long long tmp = s.empty() ? Sum(num, 0, size_n - 1) : Sum(num, s.top() + 1, size_n - 1);
        long long curSum = num[top] * tmp;
        maxSum = max(curSum, maxSum);
    }
    return maxSum;
}

/*
5 
7 2 4 6 5

*/

int main()
{
    int n;
    cin >> n;

    vector<int> w(n);
    for (int i = 0; i < n; i++)
        cin >> w[i];

    cout << func(w);

    return 0;
}
