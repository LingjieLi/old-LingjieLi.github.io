/**
* @projectName E:\LingjieLi.github.io\_posts\剑指Offer\022二叉查找树
* @fileName    main.cpp
* @brief       二叉查找树
*
* @author  lydia <vera71@126.com>
* @date    2019-09-18 14:55:17
*
**/

#include <iostream>

using namespace std;

class A {
public:
    A(){};
    A(int _d)
        : d(_d){};
    A(A& a)
        : d(a.d){};
    const A& operator=(const A& rhs) //常引用不能作为左值
    {
        if (this != &rhs) {
            d = rhs.d;
        }
        return *this;
    };
    int& getData()
    {
        return d;
    };
    void print()
    {
        cout << d << "\n";
    }

public:
    int d = 2;
};

int main()
{
    A a1(3);
    A a2 = a1; //拷贝构造
    a2.print();
    A a3;
    a3 = a2; //赋值构造
    a3.print();
    a2.print();
    a3.d = 5;
    a2.print();
    a3.print();
    a3.getData() = 6;
    a3.print();
    return 0;
}