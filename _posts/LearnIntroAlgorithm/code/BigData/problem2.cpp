/*
 * @Description: problem 1:实现可以获取最小值的栈O(1)
 * @LastEditors: lydia
 * @LastEditTime: 2019-09-04 12:03:13
 * @Author: lydia
 * @Date: 2019-09-04 10:09:04
 */
#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;
/*
push 1      1  
push 4      1 1
push 3      1 1 1
push 2      1 1 1 1
pop         2         
min         1
push 
*/

class Solution1 {
public:
    ///两个栈等长
    void Sol(string cmd, int val = -1)
    {
        if (cmd == "push") {
            cin >> val;
            data.push(val);
            if (min.empty() || val < min.top()) {
                min.push(val);
            } else {
                min.push(min.top());
            }
        } else if (cmd == "pop") {
            if (data.empty()) {
                cout << "empty\n";
                return;
            }
            cout << data.top() << "\n";
            if (data.top() >= min.top()) {
                min.pop();
            }
            data.pop();
        } else if (cmd == "min") {
            if (data.empty()) {
                cout << "empty\n";
                return;
            }
            cout << min.top() << "\n";
        } else {
            cout << "wrong commond\n";
        }
    }

private:
    stack<int> data;
    stack<int> min;
};

class Solution2 {
public:
    ///索引法
    void Sol(string cmd, int val = -1)
    {
        if (cmd == "push") {
            cin >> val;
            if (data.empty()) {
                min.push_back(0);
            } else {
                if (data[*min.rbegin()] > val) {
                    min.push_back(data.size());
                }
            }
            data.push_back(val);

        } else if (cmd == "pop") {
            if (data.size() == 0) {
                cout << "empty\n";
                return;
            }
            cout << *data.rbegin() << "\n";
            if (data.size() - 1 == *min.rbegin()) {
                min.erase(min.end() - 1);
            }
            data.erase(data.end() - 1);

        } else if (cmd == "min") {
            if (data.size() == 0) {
                cout << "empty\n";
                return;
            }
            cout << data[*min.rbegin()] << "\n";
        } else {
            cout << "wrong commond\n";
        }
    }

private:
    vector<int> data;
    vector<int> min; //min栈中保存最小值所在的序号
};
int main()
{
    string cmd;
    // Solution1* sol1 = new Solution1;
    // while (cin >> cmd) {
    //     sol1->Sol(cmd);
    // }

    Solution2* sol2 = new Solution2;
    while (cin >> cmd) {
        if (cmd == "exit")
            break;
        sol2->Sol(cmd);
    }

    return 0;
}
