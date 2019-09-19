/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-10 15:00:15
 * @Author: lydia
 * @Date: 2019-08-10 14:43:26
 */

#include <stack>

using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while (!popstack.empty()) {
            pushstack.push(popstack.top());
            popstack.pop();
        }
        pushstack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        while (!pushstack.empty()) {
            popstack.push(pushstack.top());
            pushstack.pop();
        }

        int t = popstack.top();
        popstack.pop();
        return t;
    }

    /** Get the front element. */
    int peek()
    {
        while (!pushstack.empty()) {
            popstack.push(pushstack.top());
            pushstack.pop();
        }

        return popstack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return pushstack.empty() && popstack.empty();
    }

private:
    stack<int> pushstack; //负责push操作
    stack<int> popstack; //负责pop、peek操作
};

int main()
{

    return 1;
}