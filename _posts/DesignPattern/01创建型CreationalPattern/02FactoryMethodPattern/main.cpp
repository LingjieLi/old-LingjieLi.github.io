
/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/01创建型CreationalPattern/02FactoryMethodPattern
* @fileName    main.cpp
* @brief       工厂方法模式
*
* @author  lydia <vera71@126.com>
* @date    2019-07-09 18:28:14
*
**/
#include <iostream>

using namespace std;

///抽象产品
class Product {
public:
    virtual void info(){};
};
class AProduct : public Product {
public:
    void info()
    {
        cout << "create A product\n";
    };
};
class BProduct : public Product {
public:
    void info()
    {
        cout << "create B product\n";
    };
};

///抽象工厂
class Factory {
public:
    virtual Product* createProduct(){};
};
class AFactory : public Factory {
    Product* createProduct()
    {
        return new AProduct();
    };
};
class BFactory : public Factory {
    Product* createProduct()
    {
        return new BProduct();
    };
};

int main()
{
    //create A product
    Factory* _afactory = new AFactory();
    Product* _aproduct = _afactory->createProduct();
    _aproduct->info();

    //create B product
    Factory* _bfactory = new BFactory();
    Product* _bproduct = _bfactory->createProduct();
    _bproduct->info();
    return 1;
}