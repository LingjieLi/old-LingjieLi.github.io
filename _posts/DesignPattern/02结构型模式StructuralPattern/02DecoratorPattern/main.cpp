/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/02结构型模式StructuralPattern/02DecoratorPattern
* @fileName    main.cpp
* @brief       装饰模式
*
* @author  lydia <vera71@126.com>
* @date    2019-07-09 20:29:18
*
**/
///抽象构件
class Component {
};
///具体构件
class ConcreteComponent : public Component {
};

///抽象装饰器
class Decorator : public Component {
};
///具体装饰器
class ConcreteDecoratorA : public Decorator {
};
///具体装饰器
class ConcreteDecoratorB : public Decorator {
};

int main()
{
    ConcreteComponent* _component = new ConcreteComponent;
    return 1;
};