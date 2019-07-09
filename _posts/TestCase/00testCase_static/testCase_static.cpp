/**
* @projectName /home/lydia/Documents/面试笔试资料
* @fileName    testCase_static.cpp
* @brief       C++ 面试宝典导读 2.1 static关键字的作用
*
* @author  lydia <vera71@126.com>
* @date    2019-05-31 10:42:30
*
**/
#include <iostream>
#include "auxiliary.h"

static int para = 2;

int main()
{
    std::cout << static_para_in_test << std::endl;
    printDate();
    printDate();

    return 0;
}