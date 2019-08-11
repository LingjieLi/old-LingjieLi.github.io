/**
* @projectName /home/lydia/code/LingjieLi.github.io/_posts/DesignPattern/02结构型模式StructuralPattern/03CompositePattern
* @fileName    main.cpp
* @brief       组合模式
*
* @author  lydia <vera71@126.com>
* @date    2019-08-05 20:47:44
*
**/
#include <string>
#include <list>
#include <iostream>

using namespace std;

class Component {
public:
    Component(string name)
        : _name(name){};
    string name() const { return _name; };
    bool operator==(const Component& a) const
    {
        return a.name() == _name;
    };
    bool operator!=(const Component& a) const
    {
        return !(_name == a.name());
    };
    virtual void Add(Component* c){};
    virtual void Remove(Component* c){};
    virtual void Display(int depth){};

protected:
    string _name;
};

class Composite : public Component {
public:
    Composite(string name)
        : Component(name){};
    void Add(Component* c)
    {
        children.push_back(c);
    };
    void Remove(Component* c)
    {
        children.remove(c);
    };
    void Display(int depth)
    {
        cout << string(depth, '-') << _name << "\n";
        for (Component* c : children) {
            c->Display(depth + 2);
        }
    };

private:
    list<Component*> children; ///指针　引用　动态绑定
};

class Leaf : public Component {
public:
    Leaf(string name)
        : Component(name){};
    void Display(int depth)
    {
        cout << string(depth, '-') << _name << "\n";
    };
};
int main()
{
    Composite* root = new Composite("root");
    root->Add(new Leaf("Lear A"));
    root->Add(new Leaf("Lear B"));

    Composite* comp = new Composite("Composite X");
    comp->Add(new Leaf("Leaf XA"));
    comp->Add(new Leaf("Leaf XB"));

    root->Add(comp);

    Composite* comp2 = new Composite("Composite XY");
    comp2->Add(new Leaf("Leaf XYA"));
    comp2->Add(new Leaf("Leaf XYB"));

    comp->Add(comp2);

    root->Add(new Leaf("Leaf C"));

    root->Display(1);

    return 1;
};