/*
 * @Description:
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-10 20:37:59
 * @Author: lydia
 * @Date: 2019-08-10 20:09:25
 */
#include <vector>
#include <deque> //双端队列
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> getMaxWindow(vector<int> arr, int length)
    {
        vector<int> res;
        deque<int> qmax;
        int amount = 0;
        int left = 0;
        for (int i = 0; i < arr.size(); i++) {
            amount++;
            if (qmax.empty()) {
                qmax.push_back(i); //O(1)
            } else {
                while (!qmax.empty() && arr[i] > arr[qmax.back()]) {
                    qmax.pop_back(); //O(1)
                }
                qmax.push_back(i);

                if (amount == length) {
                    res.push_back(qmax.front());
                    amount--;
                    left++;
                    if (qmax.front() < left) {
                        qmax.pop_front();
                    }
                }
            }
        }

        return res;
    };
};

int main()
{
    vector<int> arr{ 4, 3, 5, 4, 3, 3, 6, 7 };
    vector<int> res;
    Solution sol;
    res = sol.getMaxWindow(arr, 3);

    for (int val : res) {
        cout << arr[val] << "\t";
    }
    cout << "\n";
    return 1;
}
