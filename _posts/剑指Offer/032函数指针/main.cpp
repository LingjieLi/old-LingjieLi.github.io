#include <iostream>

using namespace std;

int add(int a, int b)
{
    return a + b;
}
int mimus(int a, int b)
{
    return a - b;
}
int (*funptr[])(int, int){ //函数指针数组
    add,
    mimus
};
int calculate(int a, int b, int op)
{
    return funptr[op](a, b); //访问数组的不同元素
}

int (*fp)(int, int); //函数指针
int main()
{
    cout << calculate(1, 2, 0) << "\n";
    cout << calculate(1, 2, 1) << "\n";

    fp = &add; //绑定函数指针
    cout << fp(3, 4) << "\n";
    fp = &mimus; //绑定函数指针
    cout << fp(3, 4) << "\n";

    return 0;
}