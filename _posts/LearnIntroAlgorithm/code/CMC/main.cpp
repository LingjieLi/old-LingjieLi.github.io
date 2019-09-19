/*
 * @Description: 黄金数字
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-06 17:01:15
 * @Author: lydia
 * @Date: 2019-09-06 15:52:54
 */
#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int size = 0;
    for (int num = 2; num <= N; num++) {
        int sum = 1;
        for (int seed = 2; seed < num; seed++) {
            if (num % seed == 0) {
                sum *= seed;
            }
        }
        if (sum == num) {
            size++;
        }
    }

    cout << size << "\n";
}