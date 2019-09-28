#include <iostream>
#include <vector>
#include <algorithm>
// 9012cc2ea7bd265ae545f28d2f4e06ea0f441574
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());

        for (auto interval : intervals) {
            std::cout << "[" << interval[0] << "," << interval[1] << "],";
        }
        std::cout << std::endl;

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (auto interval : intervals) {
            if (interval[0] <= end) { //连接
                end = max(end, interval[1]);
            } else { //分开
                result.push_back(vector<int>{ start, end });
                start = interval[0];
                end = interval[1];
            }
        }

        result.push_back(vector<int>{ start, end });
        return result;
    }
};

int main()
{
    vector<vector<int>> intervals = { { 1, 3 }, { 0, 6 }, { 8, 10 }, { 15, 18 } };
    Solution sol;
    vector<vector<int>> result;
    result = sol.merge(intervals);
    for (auto interval : result) {
        std::cout << "[" << interval[0] << "," << interval[1] << "],";
    }
    std::cout << std::endl;
    return 1;
}
