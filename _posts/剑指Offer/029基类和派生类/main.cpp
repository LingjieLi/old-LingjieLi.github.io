#include <iostream>

using namespace std;

class Animals { //动物基类
public:
    Animals(string _name)
        : name(_name)
    {
        cout << "construct Animals\n";
    };

    friend ostream& operator<<(ostream& out, const Animals& a);

protected:
    //static string type; //基类和派生类共用 不合理
    string type = "Animals"; //派生类可见

private:
    string name = ""; //派生类不可见
};

//string Animals::type = "Animal";

ostream& operator<<(ostream& out, const Animals& a)
{
    out << a.type << "\t" << a.name;
}

class Birds : public Animals { //鸟类
public:
    Birds(string _name = "xiao Birds")
        : Animals(_name)
    {
        type = "Birds";
        cout << "construct Birds\n";
    }

    ostream& operator<<(ostream& out)
    {
        out << "Birds :" << type;
        return out;
    }
};
// ostream& operator<<(ostream& out, const Animals& a)
// {
//     out << "Birds :" << a.type;
//     return out;
// }

class Fishes : public Animals { //鱼类
public:
    Fishes(string _name = "da Fishes")
        : Animals(_name)
    {
        type = "Fishes";
        cout << "construct Fishes\n";
    }
};

class Pigeons : public Birds { //鸽子
public:
    Pigeons(string _name = "ai Pigeons")
        : Birds(_name)
    {
        type = "Pigeons";
        cout << "construct Pigeons\n";
    };
};

int main()
{
    Animals* pigeons = new Pigeons;
    cout << *pigeons << "\n";

    cout << "----------------\n";
    Animals* fishes = new Fishes;
    cout << *fishes << "\n";

    cout << "----------------\n";
    Animals* bird1 = new Birds("bird 1");
    cout << *bird1 << "\n";

    cout << "----------------\n";
    Birds* bird2 = new Birds("bird 2");
    cout << *bird2 << "\n";
}