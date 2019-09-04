/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-11 20:06:52
 * @Author: lydia
 * @Date: 2019-08-10 15:30:17
 */

#include <queue>
#include <iostream>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        !q1.empty() ? q1.push(x) : q2.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int t;
        if (!q1.empty()) {
            while (q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            t = q1.front();
            q2.push(q1.front());
            q1.pop();
        } else {
            while (q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }
            t = q2.front();
            q2.pop();
        }

        return t;
    }

    /** Get the top element. */
    int top()
    {
        int t;
        if (!q1.empty()) {
            while (q1.size() != 1) {
                q2.push(q1.front());
                q1.pop();
            }
            t = q1.front();
            q2.push(q1.front());
            q1.pop();
        } else {
            while (q2.size() != 1) {
                q1.push(q2.front());
                q2.pop();
            }
            t = q2.front();
            q1.push(q2.front());
            q2.pop();
        }

        return t;
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty() && q2.empty();
    }

private:
    queue<int> q1;
    queue<int> q2;
};

int main()
{
    MyStack* stack = new MyStack();

    stack->push(1);
    stack->push(2);
    cout << stack->top() << "\n";
    cout << stack->pop() << "\n";
    cout << stack->pop() << "\n";
    cout << stack->empty() << "\n";
    return 0;
}