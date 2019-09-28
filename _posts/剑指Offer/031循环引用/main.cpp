#include <iostream>
#include <memory>

using namespace std;

class Child;
class Parent;

class Parent {
private:
    Child* myChild;

public:
    void setChild(Child* ch)
    {
        this->myChild = ch;
    }

    void doSomething()
    {
        if (this->myChild) {
        }
    }

    ~Parent()
    {
        cout << "~Parent()\n";
        delete myChild;
        myChild = nullptr;
    }
};

class Child {
private:
    Parent* myParent;

public:
    void setPartent(Parent* p)
    {
        this->myParent = p;
    }
    void doSomething()
    {
        if (this->myParent) {
        }
    }
    ~Child()
    {
        cout << "~Child()\n";
        delete myParent;
        myParent = nullptr;
    }
};

int main()
{
    {
        Parent* p = new Parent;
        Child* c = new Child;
        p->setChild(c);
        c->setPartent(p);
        delete c; //产生野指针
        // ~Child()
        // ~Parent()
        //delete p;
    }
    return 0;
}