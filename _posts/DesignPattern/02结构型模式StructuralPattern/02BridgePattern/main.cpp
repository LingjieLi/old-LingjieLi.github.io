/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/02结构型模式StructuralPattern/02BridgePattern
* @fileName    main.cpp
* @brief       桥接模式
*
* @author  lydia <vera71@126.com>
* @date    2019-08-06 14:32:52
*
**/
#include <iostream>

using namespace std;

class Implementor {
public:
    virtual void operationImp(){};
};

class Abstraction {
public:
    Abstraction(Implementor* imp)
        : pImp(imp){};
    virtual void operation(){};

protected:
    Implementor* pImp;
};

class ConcreteImplementorA : public Implementor {
public:
    void operationImp()
    {
        cout << "ImplementorA operation!\n";
    };
};

class ConcreteImplementorB : public Implementor {
public:
    void operationImp()
    {
        cout << "ImplementorB operation!\n";
    };
};

class RefinedAbstraction : public Abstraction {
public:
    RefinedAbstraction(Implementor* imp)
        : Abstraction(imp){};
    void operation()
    {
        pImp->operationImp();
    };
};

int main()
{
    Implementor* pImp = new ConcreteImplementorA();
    Abstraction* pa = new RefinedAbstraction(pImp);
    pa->operation();

    Abstraction* pb = new RefinedAbstraction(new ConcreteImplementorB());
    pb->operation();

    delete pa;
    delete pb;

    return 0;
};