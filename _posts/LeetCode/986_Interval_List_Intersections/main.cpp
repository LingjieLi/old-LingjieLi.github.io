/**************************************************************************
*
*   Copyright (C) 2019 by lydia <vera71@126.com>
*
*   All Rights Reserved
*
**************************************************************************/
#include <iostream>
#include <vector>

using namespace std;

/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LeetCode/986_Interval_List_Intersections
* @fileName    main.cpp
* @brief       ”实数“的交集
*
* @author  lydia <vera71@126.com>
* @date    2019-06-04 09:38:08
*
**/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B)
    {
        ///good solution
        int i = 0, j = 0;
        int N = A.size();
        int M = B.size();

        vector<vector<int>> result;

        while (i < N && j < M) {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);

            if (start <= end)
                result.push_back(vector<int>{ start, end });
            A[i][1] > B[j][1] ? j++ : i++;
        }

        return result;
        /*    int minA = (*A.begin())[0];
        int maxA = (*A.rbegin())[1];
        int minB = (*B.begin())[0];
        int maxB = (*B.rbegin())[1];
        int min = std::min(minA, minB);
        int max = std::max(maxA, maxB);
        vector<vector<int>> result;
        vector<int> list;
        list.resize(max - min + 1);
        for (int& val : list) {
            val = 0;
        }
        for (vector<int> interval : A) {
            int a = interval[0];
            int b = interval[1];
            for (int val = a; val <= b; val++) {
                list[val - min]++;
            }
        }

        for (vector<int> interval : B) {
            int a = interval[0];
            int b = interval[1];
            for (int val = a; val <= b; val++) {
                list[val - min]++;
            }
        }
        bool start = true;
        vector<int> interval;
        for (int i = 0; i < list.size(); i++) {
            if (list[i] == 2 && start) {
                interval.push_back(i + min);
                start = !start;
            }
            if (list[i] == 0 && !start) {
                interval.push_back(i + min - 1);
                start = !start;
                result.push_back(interval);
                interval.clear();
            }
        }
        return result; */
    }
};
