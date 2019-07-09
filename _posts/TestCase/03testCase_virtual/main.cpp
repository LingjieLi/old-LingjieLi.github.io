#include <iostream>

using namespace std;

///基类
class A {
public:
    virtual void vfunc1()
    {
        cout << "class A function vfunc1\n";
    };
    virtual void vfunc2()
    {
        cout << "class A function vfunc2\n";
    };
};

class B : public A {
public:
    virtual void vfunc1()
    {
        cout << "class B function vfunc1\n";
    };
    virtual void vfunc3()
    {
        cout << "class B function vfunc3\n";
    };
    void func1()
    {
        cout << "class B function func1\n";
    };
};

class C : public B {
public:
    virtual void vfunc3()
    {
        cout << "class C function vfunc3\n";
    };
    void func1()
    {
        cout << "class C function func1\n";
    };
    void func2()
    {
        cout << "class C function func2\n";
    };
};

int main()
{
    B bObject;
    A* Ap = &bObject;
    Ap->vfunc1();
    Ap->vfunc2();
    cout << "======\n";
    C cObject;
    B* Bp = &cObject;
    Bp->vfunc1();
    Bp->vfunc2();
    Bp->vfunc3();
    Bp->func1();
    cout << "======\n";
    cObject.vfunc1();
    cObject.vfunc2();
    cObject.vfunc3();
    cObject.func1();
    cObject.func2();
    cout << "======\n";
    A& _a = bObject;
    _a.vfunc1();
    _a.vfunc2();
}