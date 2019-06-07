#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    void merge( vector<int> &nums1, int m, vector<int> &nums2, int n )
    {
        int i = 0, j = 0;
        vector<int> list;
        while( i < m && j < n ) {
            if( nums1[i] <= nums2[j] ) {
                list.push_back( nums1[i] );
                i++;
            } else {
                list.push_back( nums2[j] );
                j++;
            }
        }
        while( i < m ) {
            list.push_back( nums1[i] );
            i++;
        }
        while( j < n ) {
            list.push_back( nums2[j] );
            j++;
        }
        nums1 = list;
    }
};

int main()
{
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3;
    int n = 3;
    Solution sol;
    sol.merge( nums1, m, nums2, n );
    for( int val : nums1 ) {
        std::cout << val << ",";
    }
    std::cout << std::endl;
}
