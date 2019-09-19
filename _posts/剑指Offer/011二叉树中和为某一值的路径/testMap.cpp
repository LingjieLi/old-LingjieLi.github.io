#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    string line;
    getline(cin, line);
    istringstream is(line + ",");
    int val;
    char ch;
    vector<int> nums;
    while (is >> val) {
        nums.push_back(val);
        is >> ch;
    }

    if (nums.size() == 0) {
        cout << 0 << "\n";
        return 0;
    }
    vector<int> res;
    int last_val = nums[0];
    res.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != last_val) {
            res.push_back(nums[i]);
            last_val = nums[i];
        }
    }
    cout << res.size() << "\n";
    return 0;
}