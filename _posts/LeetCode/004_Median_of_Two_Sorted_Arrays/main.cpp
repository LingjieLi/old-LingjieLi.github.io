#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        int m = nums1.size(); //i
        int n = nums2.size(); //j
        bool even; //偶数个元素
        (m + n) % 2 == 0 ? even = true : even = false;
        int media_idx = (m + n) / 2;
        std::cout << "media idx: " << media_idx << endl;
        int idx = 0;

        vector<int> list;
        int i = 0;
        int j = 0;
        while (i < m && j < n) {
            if (nums1[i] >= nums2[j]) {
                list.push_back(nums2[j]);
                j++;
            } else {
                list.push_back(nums1[i]);
                i++;
            }

            if (idx == media_idx) {
                if (even) {
                    return (list[idx] + list[idx - 1]) / 2.0;
                } else {
                    return list[idx];
                }
            }
            idx++;
        }
        while (i < m) {
            list.push_back(nums1[i]);
            i++;

            if (idx == media_idx) {
                if (even) {
                    return (list[idx] + list[idx - 1]) / 2.0;
                } else {
                    return list[idx];
                }
            }
            idx++;
        }
        while (j < n) {
            list.push_back(nums2[j]);
            j++;

            if (idx == media_idx) {
                if (even) {
                    return (list[idx] + list[idx - 1]) / 2.0;
                } else {
                    return list[idx];
                }
            }
            idx++;
        }
    }
};

int main()
{
    vector<int> nums1 = { 1, 2 };
    vector<int> nums2 = { 3, 4 };
    vector<int> nums3 = { 1, 3 };
    vector<int> nums4 = { 2 };
    Solution sol;
    double media = sol.findMedianSortedArrays(nums1, nums2);
    cout << "media value: " << media << endl;
    media = sol.findMedianSortedArrays(nums3, nums4);
    cout << "media value: " << media << endl;
    return 0;
}