/**
* @projectName /home/lydia/Documents/面试笔试资料/code/testCase_undefined_behavior
* @fileName    testCase_undefined_behavior.cpp
* @brief       测试一些未定义行为
               在C++中，程序可以按照预期正确执行，可以跑出异常，
               还有一种情况是，语句没有按照预期执行(逻辑上已经出错)，
               但是程序的预期已经不可预测了：程序可能发生运行时错误，
               可能给出错误结果，甚至可能给出正确的结果。
               对于有的未定义行为，现代编译器有时候可以给出警告，或者变异失败。
*
* @author  lydia <vera71@126.com>
* @date    2019-05-31 19:42:45
*
**/

#include <iostream>
#include <cmath>
using namespace std;

int* get(int tmp);
int f();
int cal(int a, int b);
int getincress(int i);

int main()
{
    std::cout << "case #1:\n";
    ///尝试修改字符串的字面值会产生未定义行为
    //char* p = "string";                       //gcc7.4 编译是警告ISO C++ forbids converting a string constant to ‘char*’
    //p[0] = 'S';                               //未定义错误，运行时错误,溢出
    //std::cout << p << std::endl;

    //解决
    char p[] = "string"; // 正确
    p[0] = 'S';
    std::cout << sizeof(p) << '\t' << p << std::endl;

    std::cout << "case #2:\n";
    ///除以0
    //int x;
    //cin >> x;
    //std::cout << x / 0 << std::endl;          //未定义行为,gcc7.4编译时警告,运行时错误

    std::cout << "case #3:\n";
    ///解引用一个未初始化的指针；
    //int* foo = get(10);
    //std::cout << *foo << std::endl;           //未定义行为，解引用一个指向局部指针地址(),g++7.4运行时错误

    std::cout << "case #4:\n";
    ///指针访问越界(超出数组边界的指针)
    int arr[] = { 1, 2, 3, 4 };
    std::cout << *(arr + 4) << std::endl; //未定义行为，gcc7.4编译通过，运行输出随机值

    std::cout << "case #5:\n";
    ///解引用一个未初始化的指针
    //int* bar = 0; //未初始化
    //*bar = 2;                                 //未定义行为，解引用一个未初始化的指针，运行时错误;
    //std::cout << *bar << std::endl;
    int* bar = new int; //初始化指针
    *bar = 2; //正确
    std::cout << *bar << std::endl;

    std::cout << "case #6:\n";
    ///解引用一个nullptr
    //int* val = nullptr;
    //*val = 2; //未定义行为，解引用一个nullptr，gcc7.4运行时错误;
    //std::cout << *val << std::endl;

    std::cout << "case #7:\n";
    /// 有返回值的函数没有return语句
    int a = f(); //未定义行为，函数没有返回值,gcc7.4编译成功，运行时返回随机值
    std::cout << a << std::endl;

    std::cout << "case #8:\n";
    float val_arr[4];
    for (int n = 0; n < 4;) {
        val_arr[n] = n++;
        //printf("%d %.2f\n", ++n, pow(2, n));
    }
    for (float val : val_arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::cout << "case #9:\n";
    ///static_cast将void*转换为原来的类型，但是转换的类型不一致
    int val = 2;
    void* val_ptr = &val;
    float* val_double = static_cast<float*>(val_ptr);
    std::cout << val_double << ":" << *val_double << std::endl; //未定义行为,未定义类型，gcc7.4编译通过，输出随机值

    std::cout << "case #10:\n";
    ///函数参数的执行顺序是未定义的行为
    cout << cal(getincress(0), getincress(10)) << endl; //未定义行为，10 0 12 或 0 10 12

    std::cout << "case #11:\n";
    int x = 1;
    printf("%d\n", &x); //未定义行为,gcc7.4编译时警告：%d预期int类型的实际参数
    printf("%p\n", &x); //未定义行为：%p预期void*类型的实际参数
    printf("%p\n", (void*)&x); //%p和void*类型的实际参数匹配，不在此引发未定义行为

    std::cout << "case #12:\n";
    //void* ptri = &x;
    //std::cout << *ptri << std::endl; //错误,error: ‘void*’ is not a pointer-to-object type

    return 0;
}

int* get(int tmp) //复制变量
{
    return &tmp; //错误，返回局部指针地址,gcc7.4编译时警告
}
int f() {}

int cal(int a, int b)
{
    return a + b;
}
int getincress(int i)
{
    cout << i << " ";
    return i + 1;
}