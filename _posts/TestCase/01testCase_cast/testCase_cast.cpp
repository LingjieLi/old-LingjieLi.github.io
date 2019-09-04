#include <iostream>

void testcase1()
{
    char ch = 'a';
    std::cout << (uint64_t)&ch << std::endl; //140725614332263
    const char* pc = &ch; //指向const的指针
    //* pc = 'c';//错误，pc是指向const的指针，可以用在接口返回值，用户不可修改函数返回指针指向的值

    char* p = const_cast<char*>(pc); //正确，去常量行为

    std::cout << (uint64_t)p << std::endl; //140725614332263
    *p = 'b'; //正确，去常量后，可以修改(c++ primer plus P.209 冲突)
    std::cout << (uint64_t)&ch << std::endl; //140725614332263
    std::cout << (uint64_t)p << std::endl; //140725614332263
    std::cout << (uint64_t)pc << std::endl; //140725614332263

    std::cout << *p << "\n" //b
              << *pc << "\n" //b
              << ch //b
              << std::endl;
}
void testcase2()
{

    const char ch = 'a';
    std::cout << (uint64_t)&ch << std::endl; //140725614332263
    const char* pc = &ch; //指向const的指针
    //* pc = 'c';//错误，pc是指向const的指针，可以用在接口返回值，用户不可修改函数返回指针指向的值

    char* p = const_cast<char*>(pc); //正确，去常量行为

    std::cout << (uint64_t)p << std::endl; //140725614332263
    *p = 'b'; //正确，去常量后，可以修改(c++ primer plus P.209 冲突)
    std::cout << (uint64_t)&ch << std::endl; //140725614332263
    std::cout << (uint64_t)p << std::endl; //140725614332263
    std::cout << (uint64_t)pc << std::endl; //140725614332263

    std::cout << *p << "\n" //b
              << *pc << "\n" //b
              << ch //a,引起了未定义行为？
              << std::endl;

    /// 注释
    //自始至终指针p,pc,&ch没有变，ch内存中的值变为a，输出的确是b
}

int main()
{
    std::cout << "test case #1:\n";
    testcase1();
    std::cout << "\ntest case #2:\n";
    testcase2();

    return 0;
}