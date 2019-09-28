/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-09 09:06:53
 * @Author: lydia
 * @Date: 2019-09-09 09:06:52
 */
#include <iostream>
#include <vector>

using namespace std;

bool isIncreasingTree(vector<vector<int>>& tree)
{
    for (int i = 0; i < tree.size(); i++) {
        int left_value = tree[i][1] != -1 ? tree[tree[i][1]][0] : 0;
        int right_value = tree[i][2] != -1 ? tree[tree[i][2]][0] : 0;

        if (left_value + right_value == 0)
            continue;
        if (left_value + right_value < tree[i][0]) {
            return false;
        }
    }

    return true;
}

int main()
{
    int T;
    cin >> T; // T [0, 50]

    vector<int> N(T); // N [0, 1000]
    vector<vector<vector<int>>> trees(T);

    for (int i = 0; i < T; i++) {
        // N
        cin >> N[i];
        int tmp = N[i];
        trees[i] = vector<vector<int>>(tmp, vector<int>(3));
        vector<vector<int>>& cur_tree = trees[i];

        for (int j = 0; j < tmp; j++) {
            // Value LEFT RIGHT
            cin >> cur_tree[j][0] >> cur_tree[j][1] >> cur_tree[j][2];
        }
    }

    for (int i = 0; i < T; i++) {
        if (isIncreasingTree(trees[i])) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
