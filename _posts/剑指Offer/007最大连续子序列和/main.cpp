#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    int result = INT32_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) {
        sum = max(sum + nums[i], nums[i]);
        result = max(result, sum);
    }
    return result;
}

int main()
{
    string line;
    vector<int> nums;
    getline(cin, line);
    istringstream is(line);

    int inter;
    char ch;
    is >> ch;
    while (is >> inter) {
        nums.push_back(inter);
        is >> ch;
    }

    cout << maxSubArray(nums) << "\n";
    return 0;
}