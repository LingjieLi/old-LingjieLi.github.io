/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/01创建型CreationalPattern/03AbstractFactoryPattern
* @fileName    main.cpp
* @brief       抽象工厂模式
*
* @author  lydia <vera71@126.com>
* @date    2019-07-09 18:28:37
*
**/

#include <iostream>

using namespace std;

///抽象产品(一系列)
class AbstractProductA {
public:
    ///打印产品系列
    virtual void type_series(){};
};
class AbstractProductB {
public:
    ///打印产品信息
    virtual void type_info(){};
};
///系列A的具体产品
class ProductA1 : public AbstractProductA {
public:
    void type_series()
    {
        cout << "series A\n";
    };
};
class ProductA2 : public AbstractProductA {
public:
    void type_series()
    {
        cout << "series A\n";
    };
};

///系列B的具体产品
class ProductB1 : public AbstractProductB {
public:
    void type_info()
    {
        cout << "product B series created by factory 1\n";
    }
};
class ProductB2 : public AbstractProductB {
public:
    void type_info()
    {
        cout << "product B series created by factory 2\n";
    }
};
///抽象工厂
class AbstractFactory {
public:
    virtual void info();
    // virtual AbstractProductA* createProductA(){};
    // virtual AbstractProductB* createProductB(){};
};

///具体工厂 生产1号产品
class ConcreteFactory1 : public AbstractFactory {
public:
    void info()
    {
        cout << "factory 1\n";
    };
    // AbstractProductA* createProductA()
    // {
    //     return new ProductA1;
    // };
    // AbstractProductB* createProductB()
    // {
    //     return new ProductB1;
    // };
};
///具体工厂 生产2号产品
class ConcreteFactory2 : public AbstractFactory {
public:
    void info()
    {
        cout << "factory 2\n";
    };
    // AbstractProductA* createProductA()
    // {
    //     return new ProductA2;
    // };
    // AbstractProductB* createProductB()
    // {
    //     return new ProductB2;
    // };
};

///客户端代码
int main()
{
    ///1号工厂
    AbstractFactory* _factory1 = new ConcreteFactory1;
    AbstractFactory* _factory2 = new ConcreteFactory2;
    _factory1->info();
    _factory2->info();
    // AbstractProductA* _a1product =
    //_factory1->createProductA;
    // AbstractProductB* _b1product = _factory1->createProductB;
    // AbstractProductA* _a2product = _factory2->createProductA;
    // AbstractProductB* _b2product = _factory2->createProductB;

    // _a1product->type_series();
    // _a2product->type_series();
    // _b1product->type_info();
    // _b2product->type_info();

    return 1;
};