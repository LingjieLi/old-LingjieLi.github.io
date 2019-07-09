#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 超过1/2的才是众数
class Solution {
public:
    /**
    * @name     majorityElement 算法1
    * @brief    空间复杂度:hash表存放了n-ceil(n/2)个元素，占用空间为O(n)
    *           时间复杂度:hash插入查找都是O(1),所有事件复杂度是O(n+n-ceil(n/2))~O(n)
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-25 10:35:13
    * @return
    *
    **/
    int majorityElement1(vector<int>& nums)
    {
        // 建立hashmap
        map<int, int> counts;
        for (int i = 0; i < nums.size(); i++) {
            if (counts.find(nums[i]) != counts.end()) {
                counts[nums[i]]++;
            } else {
                counts[nums[i]] = 1;
            }
        }

        int majority = nums[0];
        int size = counts.at(majority);

        for (auto kv : counts) {
            if (kv.second > size) {
                majority = kv.first;
                size = kv.second;
            }
        }
        return majority;
    }

    /**
    * @name     majorityElement2 摩尔投票算法(对碰抵消)
    * @brief    时间复杂度O(n),空间复杂度O(1)
    *
    * @parm
    * @author  lydia <vera71@126.com>
    * @date    2019-06-25 10:49:36
    * @return
    *
    **/
    int majorityElement2(vector<int>& nums)
    {
        int majority = nums[0];
        int size = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (size == 0 || nums[i] == majority) {
                majority = nums[i];
                size++;
            } else if (nums[i] != majority) {
                size--;
            }
        }
        return majority;
    }
};

int main(int argc, char* argv[])
{
    vector<int> nums{ 1, 2, 3, 4, 2, 7, 2, 8, 2, 2, 2, 2 };
    Solution sol;
    int majority = sol.majorityElement2(nums);

    std::cout << majority << std::endl;
    return 0;
}
