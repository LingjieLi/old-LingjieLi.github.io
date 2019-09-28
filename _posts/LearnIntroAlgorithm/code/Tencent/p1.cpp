#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int func(vector<int>& a, vector<int>& b)
{
    int odd_a = 0, even_a = 0; // 奇数 偶数
    int odd_b = 0, even_b = 0;

    for (int va : a) {
        if (va % 2 == 0)
            even_a++;
        else
            odd_a++;
    }
    for (int vb : b) {
        if (vb % 2 == 0)
            even_b++;
        else
            odd_b++;
    }

    return min(odd_a, even_b) + min(even_a, odd_b);
}

/*
2 2
1 1
1 1

0

2 2
1 2
2 1


2
*/
int main()
{
    int n, m;
    vector<int> a;
    vector<int> b;

    cin >> n >> m;
    a.resize(n);
    b.resize(m);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int j = 0; j < m; ++j)
        cin >> b[j];

    int result = func(a, b);

    cout << result << endl;
    return 0;
}
