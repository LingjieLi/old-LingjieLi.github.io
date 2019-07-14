#include <iostream>
#include <thread>

using namespace std;
void func1(int& n)
{
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread " << n << "\n";
    }
    this_thread::sleep_for(chrono::milliseconds(10));
}

void func2(int& n)
{
    for (int i = 0; i < 10; i++) {
        std::cout << "Thread 2 executing\n";
        ++n;
    }
    this_thread::sleep_for(chrono::milliseconds(20));
}

int main()
{
    int n = 0;
    thread t1(func1, std::ref(n));
    thread t2(func2, std::ref(n));
    t1.join();
    t2.join();

    std::cout << "Final value of n " << n << "\n";

    return 1;
}