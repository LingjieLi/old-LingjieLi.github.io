/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-01 22:00:56
 * @Author: lydia
 * @Date: 2019-09-01 21:47:31
 */
#include <iostream>
using namespace std;

int function(int n, int k)
{
    int sum;
    int a[100010];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum % k == 0) {
                count++;
            }
        }
    }

    return count;
};
int main()
{
    int t, k;
    cin >> t >> k;

    int gId = 0;
    while (gId < t) {
        int sum = 0;
        int start, end;
        cin >> start >> end;
        for (int i = start; i < end; i++) {
            sum += function(i, k);
        }
        cout << sum << endl;
        gId++;
    }

    return 0;
}