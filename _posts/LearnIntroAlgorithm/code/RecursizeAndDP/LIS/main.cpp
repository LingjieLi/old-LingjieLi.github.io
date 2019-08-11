/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/LearnIntroAlgorithm/code/RecursizeAndDP/LIS
* @fileName    main.cpp
* @brief       最长增长子序列问题
*
* @author  lydia <vera71@126.com>
* @date    2019-08-08 10:56:12
*
**/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size() == 0) {
            return 0;
        }
        vector<int> arr;
        arr.resize(nums.size());

        arr[0] = 1;

        for (int i = 1; i < nums.size(); i++) {
            int maxlength = 0;
            for (int j = 0; j < i; j++) {
                maxlength = arr[j] > maxlength && nums[j] < nums[i] ? arr[j] : maxlength;
            }
            arr[i] = maxlength + 1;
        }

        return *max_element(arr.begin(), arr.end());
    }

    int lengthOfLTS2(vector<int>& nums)
    {
        vector<int> helper; //helper暂存递增序列,长度是曾经的最大长度
        for (int val : nums) {
            auto it = lower_bound(helper.begin(), helper.end(), val); //log2(last - first) + O(1)
            if (it == helper.end()) { //helper中没有比val大的
                helper.push_back(val);
            } else {
                *it = val;
            }
        }
        return helper.size();
    }

    int generateLIS(vector<int>& nums, vector<int>& dp)
    {
        int res = 0;
        return res;
    };
};

int main()
{
    vector<int> arr{ 2, 1, 5, 3, 6, 3, 8, 9, 7 };
    vector<int> result;
    Solution sol;
    int length1 = sol.lengthOfLIS(arr);

    std::cout << "method 1 : "
              << "max length : " << length1 << "\n";
    int length2 = sol.lengthOfLTS2(arr);
    std::cout << "method 2 : "
              << "max length : " << length2 << "\n";

    // for (int c : result) {
    //     cout << c << "\t";
    // }
    // cout << "\n";
    return 1;
}