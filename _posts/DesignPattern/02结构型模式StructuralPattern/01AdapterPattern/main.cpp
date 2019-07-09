/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/02结构型模式StructuralPattern/01AdapterPattern
* @fileName    main.cpp
* @brief       适配器模式-对象适配器
*
* @author  lydia <vera71@126.com>
* @date    2019-07-09 20:11:22
*
**/
#include <iostream>

using namespace std;

///目标接口
class Target {
public:
    virtual void request(){};
};
class Adaptee {
public:
    void special_request()
    {
        cout << "aquire special request\n";
    };
};
///适配器类
class Adapter : public Target {
public:
    Adapter(Adaptee* _adaptee)
    {
        _madaptee = _adaptee;
    };
    virtual void request()
    {
        _madaptee->special_request();
    };

private:
    Adaptee* _madaptee; ///包装适配者类
};

int main()
{
    Adaptee* _adaptee;
    Target* target = new Adapter(_adaptee);
    target->request();
    return 1;
};
