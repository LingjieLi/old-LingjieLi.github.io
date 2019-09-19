/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-09 14:23:33
 * @Author: lydia
 * @Date: 2019-09-05 17:19:38
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>
using namespace std;

struct Node {
    Node(int _idx = -1, int _next = -1, int _isFind = false)
        : idx(_idx)
        , next(_next)
        , isFind(_isFind){};
    int idx = -1;
    int next = -1;
    bool isFind = false;
};

typedef vector<Node*> MData;
typedef unordered_map<int, MData> MTree;

int dfs(int start, MTree& mtree, MData& mdata)
{
    //cout << start << "\t";
    mdata[start]->isFind = true;
    MData nei = mtree[start];

    int max_length = 0;
    for (Node* val : nei) {
        if (!val->isFind) {
            int l = dfs(val->idx, mtree, mdata);
            if (l > max_length) {
                max_length = l;
                mdata[start]->next = val->idx;
            }
        }
    }
    return max_length + 1;
}

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        vector<int> res;
        if (n < 1) {
            return res;
        }
        mdata = MData(n, nullptr);
        for (int i = 0; i < n; i++) {
            mdata[i] = new Node(i);
            mtree.insert(pair<int, vector<Node*>>(i, vector<Node*>()));
        }
        for (vector<int> edge : edges) {
            mtree[edge[0]].push_back(mdata[edge[1]]);
            mtree[edge[1]].push_back(mdata[edge[0]]);
        }

        int s = 0, t;
        int diameter = dfs(s, mtree, mdata);
        vector<int> route = getRoute(s);
        //print(diameter, route);
        t = *route.rbegin();

        resetData(mdata);

        diameter = dfs(t, mtree, mdata);
        route = getRoute(t);
        //print(diameter, route);
        s = *route.rbegin();

        if (route.size() % 2 == 0) {
            res.push_back(route[route.size() / 2 - 1]);
            res.push_back(route[route.size() / 2]);
        } else {
            res.push_back(route[route.size() / 2]);
        }

        return res;
    }

    void resetData(MData& mdata)
    {
        for (Node* val : mdata) {
            val->isFind = false;
            val->next = -1;
        }
    }
    vector<int> getRoute(int start)
    {
        vector<int> route;
        route.push_back(start);
        while (mdata[start]->next != -1) {
            start = mdata[start]->next;
            route.push_back(start);
        }

        return route;
    }

    void print(int diameter, const vector<int>& route)
    {
        cout << "diameter = " << diameter << "\nroute size = " << route.size() << ":";
        for (int val : route) {
            cout << val << " -> ";
        }
        cout << endl;
    }

private:
    MData mdata;
    MTree mtree;
};

int main()
{
    int n = 8;
    vector<vector<int>> edges = { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 0, 4 }, { 2, 5 }, { 4, 6 }, { 3, 7 } };
    n = 4;
    edges = { { 1, 0 }, { 1, 2 }, { 1, 3 } };
    n = 1;
    edges = {};

    Solution* sol = new Solution;
    vector<int> res = sol->findMinHeightTrees(n, edges);
    for (int val : res) {
        cout << val << " ";
    }
    return 0;
}