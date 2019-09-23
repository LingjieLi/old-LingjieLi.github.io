#include <iostream>
#include <tuple>
#include <string>

using namespace std;

class A {
public:
    A()
    {
        pVal = new int;
        *pVal = 3;
        //cout << "default\n";
    };
    A(int _idx)
        : idx(_idx)
    {
        pVal = new int;
        *pVal = 3;
        //cout << "default\n";
    };
    A(int _idx, char _ch = 't', int _pVal = 3)
        : idx(_idx)
        , ch(_ch)
    {
        pVal = new int;
        *pVal = _pVal;
        // cout << "idx: " << idx << "\n";
    };
    A(const A& rhs) //拷贝构造
    {
        idx = rhs.idx;
        ch = rhs.ch;
        pVal = new int;
        *pVal = *rhs.pVal;
        //cout << "copy\n";
    };
    void operator()(){
        //函数调用运算符，定义了函数对象运算符的类称为函数对象，因为可以像调用类一样调用这种对象

    };
    void operator()(ostream& out, const string name)
    {
        out << name;
    };
    const A& operator=(const A& rhs) //赋值运算操作符
    {
        if (this != &rhs) {
            idx = rhs.idx;
            ch = rhs.ch;
            //pVal = new int;
            *pVal = *rhs.pVal;
            //cout << "operator =\n";
        }
        return *this;
    }
    const A& operator+(const A& rhs)
    {
        idx += rhs.idx;
        ch += rhs.ch;
        (*pVal) += (*rhs.pVal);
        return *this;
    };
    A& operator++() //规范形式，如果不返回引用结果上是没问题的，但是自增应该是返回自身，而不是返回自身的拷贝
    {
        idx++;
        ch++;
        (*pVal)++;
        return *this;
    }
    A operator++(int)
    {
        A tmp(*this); // copy
        operator++(); // pre-increment
        return tmp; // 返回原来的值
    }
    A& operator+=(const A& rhs)
    {
        idx += rhs.idx;
        ch += rhs.ch;
        (*pVal) += (*rhs.pVal);
        return *this;
    };

    // 非成员函数的运算符 operator<< 将拥有对 A 的私有成员的访问权
    friend ostream& operator<<(ostream& out, const A& a);
    friend istream& operator>>(istream& in, A& a);

    //friend bool operator<(const A& lhs, const A& rhs);
    friend bool operator<(const A& lhs, const A& rhs)
    {
        return lhs.idx < rhs.idx;
    };
    friend bool operator>(const A& lhs, const A& rhs)
    {
        return rhs < lhs;
    }
    friend bool operator<=(const A& lhs, const A& rhs)
    {
        return !(lhs > rhs);
    }
    friend bool operator>=(const A& lhs, const A& rhs)
    {
        return !(lhs < rhs);
    }
    friend bool operator==(const A& lhs, const A& rhs)
    {
        return lhs.idx == rhs.idx && lhs.ch == rhs.ch && *lhs.pVal == *rhs.pVal;
    }
    friend bool operator!=(const A& lhs, const A& rhs)
    {
        return !(lhs == rhs);
    }

private:
    int idx = 1;
    char ch = 't';
    int* pVal = nullptr;
};
// bool operator<(const A& lhs, const A& rhs)
// {
//     return std::tie(lhs.idx, lhs.ch, *lhs.pVal)
//         < std::tie(rhs.idx, rhs.ch, *rhs.pVal); // 保持相同顺序
// }
// bool operator>(const A& lhs, const A& rhs)
// {
//     return rhs < lhs;
// }
ostream& operator<<(ostream& out, const A& a)
{
    out << a.idx << "\t" << a.ch << "\t" << a.pVal << "\t" << *a.pVal;
};
istream& operator>>(std::istream& in, A& a)
{
    // 从流读取 obj
    int _idx;
    char _ch;
    int _pVal;
    if (in >> _idx >> _ch >> _pVal) {
        a.idx = _idx;
        a.ch = _ch;
        *a.pVal = _pVal;
    } else {
        in.setstate(std::ios::failbit);
    }
    return in;
}

int main()
{
    A a(2, 'm', 5);
    cout << "a: " << a << "\n";

    A b, c;
    cout << "b: " << b << "\n";
    b = a; //赋值构造函数
    cout << "b: " << b << "\n";

    cin >> c;
    cout << "c: " << c << "\n";

    c = a + b; //赋值操作符、加法操作符
    cout << "c: " << c << "\n";

    A d = b + c; //拷贝构造函数、加法操作符
    cout << "d: " << d << "\n";
    cout << "b: " << b << "\n";
    d++;
    cout << "d: " << d << "\n";
    cout << "b: " << b << "\n";
    cout << "c: " << c << "\n";

    A e = d++; //拷贝构造函数、自增操作
    cout << "e: " << e << "\n";
    cout << "d: " << d << "\n";

    A f = ++d;
    cout << "f: " << f << "\n";
    d(cout, "d: "); //函数调用运算符
    cout << d << "\n";

    bool compare = f > e;
    cout << "compare f>e: " << compare << "\n";
    compare = f == d;
    cout << "compare f==d: " << compare << "\n";

    A g(d);
    cout << "g: " << g << "\n";

    // A g = 3;
    // f(cout, "g:");
    // cout << g << "\n";
}