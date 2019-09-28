/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/04SingletonPattern
* @fileName    main.cpp
* @brief       单例模式
*
* @author  lydia <vera71@126.com>
* @date    2019-07-09 19:13:58
*
**/
#include <iostream>

using namespace std;

class Singleton {
private:
    Singleton(){};

public:
    static Singleton* getInstance()
    {
        if (singleton == nullptr) {
            singleton = new Singleton;
        }
        return singleton;
    };

    void info()
    {
        if (singleton != nullptr) {
            time++;
            cout << "access " << time << " times\n";
        }
    }

    ~Singleton()
    {
        delete singleton;
    };

private:
    static Singleton* singleton;
    int time = 0;
};
Singleton* Singleton::singleton = nullptr;

int main()
{
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->info(); //access 1 times

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->info(); //access 2 times
}