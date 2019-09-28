/*
 * @Description: TSP
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-05 17:01:28
 * @Author: lydia
 * @Date: 2019-09-04 20:00:54
 */

#include <vector>
#include <limits>
#include <iostream>
#include <math.h>
/*
4
6
0 1 4
0 2 3
0 3 1
1 2 1
1 3 2
2 3 5
*/

/*
4
3
0 1 4
0 2 3
1 2 1
*/

using namespace std;
int main()
{
    int i, j, k, min, brief, n, m;
    cin >> n;
    cin >> m;

    int b = (int)pow(2, n - 1);
    vector<vector<int>>
    D(n, vector<int>(n, numeric_limits<int>::max()));
    int start, end, time;
    for (int line = 0; line < m; line++) {
        cin >> start >> end >> time;
        D[start][end] = time;
        D[end][start] = time;
    }

    vector<vector<int>> Route(n, vector<int>(n, -1));
    vector<vector<int>> Mat(n, vector<int>(n, -1));

    for (i = 0; i < n; i++) //初始化第0列
        Route[i][0] = D[i][0];
    for (i = 1; i < b - 1; i++)
        for (j = 1; j < n; j++) //依次进行第i次迭代
            if (((int)pow(2, j - 1) & i) == 0) //子集V[j不包含i
            {
                min = 999;
                for (k = 1; k < n; k++)
                    if ((int)pow(2, k - 1) & i) {
                        brief = D[j][k] + Route[k][i - (int)pow(2, k - 1)];
                        if (brief < min) {
                            min = brief;
                            Route[j][i] = min;
                            Mat[j][i] = k; //局部最优决策
                        }
                    }
            }
    min = 999;
    for (k = 1; k < n; k++) {
        brief = D[0][k] + Route[k][b - 1 - (int)pow(2, k - 1)];
        if (brief < min) {
            min = brief;
            Route[0][b - 1] = min; //最优解
            Mat[0][b - 1] = k;
        }
    }

    for (i = b - 1, j = 0; i > 0;) {
        int lj = j;
        j = Mat[j][i];
        i = i - (int)pow(2, j - 1);
        if (D[lj][j] == numeric_limits<int>::max()) {
            cout << "-1\n";
            return 0;
        }
    }

    cout << Route[0][b - 1] << endl; //最短路径长度

    return 0;
}