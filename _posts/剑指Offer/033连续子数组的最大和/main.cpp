#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array)
    {
        int left = 0;
        int right = 0;
        int curSum = 0;
        int max = std::numeric_limits<int>::min();
        int maxLeft = 0;
        int maxRight = 0;

        //cout << "left: " << left << "\tright: " << right << "\tcurSum: " << curSum << "\tmax: " << max << "\n";
        while (right < array.size()) {
            curSum += array[right];
            maxRight = curSum >= max ? right : maxRight;
            maxLeft = curSum >= max ? left : maxLeft;
            max = curSum > max ? curSum : max;
            //cout << "left: " << left << "\tright: " << right << "\tcurSum: " << curSum << "\tmax: " << max << "\n";
            if (curSum < 0) {
                curSum = 0;
                left = right + 1;
            }
            right++;
        }

        //cout << "sum[" << maxLeft << " ," << maxRight << "] = " << max << "\n";
        //cout << "sum[" << array[maxLeft] << " ," << array[maxRight] << "] = " << max << "\n";
        return max;
    }
};

int main()
{
    vector<int> data;
    int val;
    while (cin >> val) {
        data.push_back(val);
        if (getchar() == '\n')
            break;
    }

    Solution* sol;
    int res = sol->FindGreatestSumOfSubArray(data);
    cout << res << "\n";
}