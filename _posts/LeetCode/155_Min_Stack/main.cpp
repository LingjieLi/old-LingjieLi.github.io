/*
 * @Description: 
 * @LastEditors: lydia
 * @LastEditTime: 2019-08-10 14:36:12
 * @Author: lydia
 * @Date: 2019-08-09 20:37:18
 */
#include <vector>
#include <iostream>
#include <limits>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (min.size() == 0) {
            cur_min = x;
        } else {
            cur_min = x < min[min.size() - 1] ? x : min[min.size() - 1];
        }
        store.push_back(x);
        min.push_back(cur_min);
    }

    void pop()
    {
        store.pop_back();
        min.pop_back();
    }

    int top()
    {
        return store[store.size() - 1];
    }

    int getMin()
    {
        return min[min.size() - 1];
    }

    void print()
    {
        for (int i = 0; i <= store.size(); i++) {
            std::cout << store[i] << "\t";
        }
        std::cout << "\n";

        /*for (int i = 0; i <= _top; i++) {
            std::cout << min[i] << "\t";
        }
        std::cout << "\n";
        */
    }

private:
    vector<int> store;
    vector<int> min;
    int cur_min = std::numeric_limits<int>::max();
};

int main()
{

    // Your MinStack object will be instantiated and called as such:
    // MinStack* obj = new MinStack();
    // obj->push(3);
    // obj->push(4);
    // obj->push(5);
    // obj->print();
    // obj->pop();
    // obj->print();
    // obj->push(1);
    // obj->push(2);
    // obj->print();
    // int param_3 = obj->top();
    // std::cout << param_3 << "\n";
    // int param_4 = obj->getMin();
    // std::cout << param_4 << "\n";

    int size = 18;
    string opt[] = { "MinStack", "push", "push", "push", "top", "pop", "getMin", "pop", "getMin", "pop", "push", "top", "getMin", "push", "top", "getMin", "pop", "getMin" };
    int val[][1] = { {}, { 2147483646 }, { 2147483646 }, { 2147483647 }, {}, {}, {}, {}, {}, {}, { 2147483647 }, {}, {}, { -2147483648 }, {}, {}, {}, {} };

    MinStack* obj;
    for (int i = 0; i < 18; i++) {
        std::cout << i << "-----------------\n";
        if (opt[i] == "MinStack") {
            obj = new MinStack();
            //obj->print();
        } else if (opt[i] == "push") {
            obj->push(val[i][0]);
            cout << "push ";
            obj->print();
        } else if (opt[i] == "top") {
            int parm = obj->top();
            cout << "top " << parm << "\n";
            obj->print();
        } else if (opt[i] == "pop") {
            obj->pop();
            cout << "pop ";
            obj->print();
        } else if (opt[i] == "getMin") {
            int parm = obj->getMin();
            cout << "getMin " << parm << "\n";
            obj->print();
        }
    }

    return 0;
}