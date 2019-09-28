/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-01 21:37:48
 * @Author: lydia
 * @Date: 2019-09-01 21:37:48
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
2
1 1
2 2

3

3
1 3
1 1
4 1

6

*/

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> b(n + 1);
    vector<long long> c(n + 1);
    unsigned long long result = 0;

    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        c[i] = a[i] - b[i];
    }

    sort(c.begin() + 1, c.end());
    for (int i = n; i >= 1; i--) {
        result += (c[i] * (n - i + 1));
        result += b[i] * n - a[i];
    }

    cout << result << endl;
    return 0;
}
