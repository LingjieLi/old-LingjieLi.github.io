#include <ctime>
#include <chrono>
#include <iostream>
///文件内作用域,在G++7.8上并没有测试出这条性质
static void printDate()
{
    ///静态局部变量，存储在静态存储区的变量值一直存在,测出了这条性质
    static int _time = 0;
    auto start = std::chrono::system_clock::now();
    std::time_t start_time = std::chrono::system_clock::to_time_t(start);
    std::cout << "print " << _time << "\t"
              << "current time : " << std::ctime(&start_time) << "";
    _time++;
};

///文件内作用域,在G++7.8上并没有测试出这条性质
static int static_para_in_test = 8;