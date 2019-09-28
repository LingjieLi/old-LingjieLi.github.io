/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/创建型CreationalPattern/SimpleFactoryPattern
* @fileName    main.cpp
* @brief    简单工厂模式 Simple Factory Pattern
*
* @author  lydia <vera71@126.com>
* @date    2019-07-09 17:01:34
*
**/
#include <iostream>
using namespace std;

enum PROTYPE {
    ATYPE,
    BTYPE
};

///抽象产品
class Product {
public:
    virtual void info(){};
};
///具体产品
class AProduct : public Product {
public:
    void info()
    {
        cout << "Crete Protect A\n";
    };
};
///具体产品
class BProduct : public Product {
public:
    void info()
    {
        cout << "Crete Protect B\n";
    };
};

///工厂
class Factory {
public:
    Product* creteProduct(PROTYPE type)
    {
        Product* p;
        switch (type) {
        case ATYPE:
            p = new AProduct;
            break;
        case BTYPE:
            p = new BProduct;
            break;
        default:
            break;
        }
    };
};

///客户端代码
int main()
{
    Factory* _factory = new Factory;
    Product* _productA = _factory->creteProduct(ATYPE);
    Product* _productB = _factory->creteProduct(BTYPE);

    _productA->info();
    _productB->info();
}