#include <iostream>

using namespace std;
#include <vector>
class A {
public:
    A(int val)
    {
        data = new int(val);

        cout << "construct 1\n";
    };

    A(A&& a)
        : data(a.data)
    {
        a.data = nullptr;
        cout << "construct 2\n";
    };
    A(const A& a)
    {
        data = new int(*a.data);
        cout << "construct 3\n";
    }
    ~A()
    {
        cout << "construct " << *data << "\n";
        if (data != nullptr) {
            delete data;
        }
    };

    int* data;
};

A test()
{
    A j(2);
    (*j.data)++;
    return j;
}

const char* test2()
{
    char* ch = "122";
    return ch;
}
char* test3()
{
    char* ch = "122";
    return ch;
}
void test4(const char* ch) {}
void test5(char* ch)
{
    *ch = '1';
    cout << "ch:" << ch << "\n";
}

int main()
{
    // char* ch = test2();
    // const char* ch = test3();

    // char* ch2 = "hlkd";
    // test4(ch2);

    // const char* ch3 = "wshlkd";
    // cout << ch3 << "\n";
    // test5(ch3);
    // cout << ch3 << "\n";

    vector<int> d;
    cout << d.capacity() << "\n";
    d.push_back(2);
    d.push_back(2);
    d.push_back(2);
    d.push_back(2);
    cout << d.capacity() << "\n";
    d.resize(2);
    cout << d.capacity() << "\n";
    cout << d.size() << "\n";

    return 0;
}