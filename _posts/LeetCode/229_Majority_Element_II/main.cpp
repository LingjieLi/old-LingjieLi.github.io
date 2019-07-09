#include <vector>
#include <iostream>
#include <math.h>

using namespace std;

class Solution {
public:
    /**
    * @name     majorityElement
    * @brief    寻找超过1/3的元素,那么这样的元素至多有两个
    *
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-25 11:23:28
    * @return
    *
    **/
    vector<int> majorityElement(vector<int>& nums)
    {
        int majority0 = -1;
        int majority1 = -2;
        int count0 = 0;
        int count1 = 0;

        //std::cout << "value\tmaj0\tcount0\tmaj1\tcount1\n";
        for (int i = 0; i < nums.size(); i++) {
            if (majority0 == nums[i]) {
                count0++;
            } else if (majority1 == nums[i]) {
                count1++;
            } else if (count0 == 0) {
                majority0 = nums[i];
                count0++;
            } else if (count1 == 0) {
                majority1 = nums[i];
                count1++;
            } else {
                count0--;
                count1--;
            }

            //std::cout << nums[i] << "\t" << majority0 << "\t" << count0 << "\t" << majority1 << "\t" << count1 << "\n";
        }
        vector<int> majority;
        if (count0 != 0) {
            majority.push_back(majority0);
        }
        if (count1 != 0) {
            majority.push_back(majority1);
        }
        /* int m0_size = 0, m1_size = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == majority0) {
                m0_size++;
            }
            if (nums[i] == majority1) {
                m1_size++;
            }
        }
        if (count0 != 0 && m0_size > std::ceil(nums.size() / 3)) {
            majority.push_back(majority0);
        }
        if (count1 != 0 && m1_size > std::ceil(nums.size() / 3)) {
            majority.push_back(majority1);
        }
        */

        return majority;
    }
};

int main()
{
    vector<int> _case{ 1, 1, 1, 3, 3, 2, 2, 2 };
    Solution sol;
    vector<int> result = sol.majorityElement(_case);

    for (int val : result) {
        std::cout << val << " ";
    }
    std::cout << "\n";
}