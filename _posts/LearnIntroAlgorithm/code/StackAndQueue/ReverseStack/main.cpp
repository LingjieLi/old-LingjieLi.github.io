/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-10 16:54:33
 * @Author: lydia
 * @Date: 2019-08-10 16:12:26
 */
#include <stack>
#include <iostream>

using namespace std;
class Solution {
public:
    void reverse(stack<int>& s)
    {
        if (s.empty()) {
            return;
        }
        int last = getAndremoveLastElement(s);
        reverse(s);
        s.push(last);
    };

private:
    int getAndremoveLastElement(stack<int>& s)
    {
        int result = s.top();
        s.pop();
        while (s.empty()) {
            return result;
        }
        int last = getAndremoveLastElement(s);
        s.push(result);
        return last;
    };
};

int main()
{
    stack<int> s, tmp;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    tmp = s;
    while (!tmp.empty()) {
        cout << tmp.top() << "\t";
        tmp.pop();
    }
    cout << "\n";

    Solution* sol = new Solution();
    sol->reverse(s);
    tmp = s;
    while (!tmp.empty()) {
        cout << tmp.top() << "\t";
        tmp.pop();
    }
    cout << "\n";
}