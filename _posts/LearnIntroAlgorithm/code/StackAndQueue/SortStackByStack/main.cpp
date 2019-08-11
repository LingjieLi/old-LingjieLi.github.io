/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-10 17:21:03
 * @Author: lydia
 * @Date: 2019-08-10 16:59:50
 */
#include <stack>
#include <limits>
#include <iostream>

using namespace std;
class Solution {
public:
    void SortStackBySTack(stack<int>& s)
    {
        stack<int> help;

        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            while (!help.empty() && help.top() < cur) {
                s.push(help.top());
                help.pop();
            }
            help.push(cur);
        }

        while (!help.empty()) {
            s.push(help.top());
            help.pop();
        }
    };
};

int main()
{
    stack<int> s;
    s.push(1);
    s.push(3);
    s.push(12);
    s.push(4);
    s.push(1);
    s.push(9);

    Solution sol;
    sol.SortStackBySTack(s);

    while (!s.empty()) {
        cout << s.top() << "\t";
        s.pop();
    }
    cout << "\n";

    return 1;
}