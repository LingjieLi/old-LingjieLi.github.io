/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/02结构型模式StructuralPattern/02DecoratorPattern
* @fileName    main.cpp
* @brief       装饰模式
*
* @author  lydia <vera71@126.com>
* @date    2019-07-09 20:29:18
*
**/
#include <iostream>
#include <string>

using namespace std;

///抽象构件
class Component {
public:
    Component(string name)
        : _name(name){};
    virtual void operation(){};

protected:
    string _name;
};
///具体构件
class ConcreteComponent : public Component {
public:
    ConcreteComponent(string name)
        : Component(name){};
};

///抽象装饰器
class Decorator : public Component {
public:
    Decorator(string name)
        : Component(name){};
    void decorate(Component* component)
    {
        this->comp = component;
    };
    void operation() ///递归输出
    {
        if (comp != nullptr) {
            comp->operation();
        }
        cout << _name << "\n";
    };

protected:
    Component* comp;
};
///具体装饰器
class ConcreteDecoratorA : public Decorator {
public:
    ConcreteDecoratorA(string name)
        : Decorator(name){};
    void behaviorA()
    {
        cout << "behavior A\n";
    };
    void operation() ///递归输出
    {
        if (comp != nullptr) {
            cout << _name << "\t";
            behaviorA();
            comp->operation();
        }
    };
};
///具体装饰器
class ConcreteDecoratorB : public Decorator {
public:
    ConcreteDecoratorB(string name)
        : Decorator(name){};
    void behaviorB()
    {
        cout << "behavior B\n";
    };
    void operation() ///递归输出
    {
        if (comp != nullptr) {
            cout << _name << "\t";
            behaviorB();
            comp->operation();
        }
    };
};

int main()
{
    ConcreteComponent* c = new ConcreteComponent("concrete person");

    ///透明装饰模式
    Decorator* da1 = new ConcreteDecoratorA("decorator A1");
    Decorator* da2 = new ConcreteDecoratorA("decorator A2");
    Decorator* db1 = new ConcreteDecoratorB("decorator B1");

    da1->decorate(c);
    da2->decorate(da1);
    db1->decorate(da2);

    db1->operation();

    return 1;
};