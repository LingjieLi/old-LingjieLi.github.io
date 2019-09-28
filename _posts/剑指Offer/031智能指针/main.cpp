#include <memory>
#include <string>
#include <iostream>

using namespace std;

class Repeater {
public:
    Repeater(int _data, string _name)
        : data(_data)
    {
        ptr = new string(_name);
    }
    void comment() const
    {
        cout << *ptr;
    };
    ~Repeater()
    {
        delete ptr;
    };

    friend ostream& operator<<(ostream& os, Repeater& repeater);

private:
    int data;
    string* ptr = nullptr;
};
ostream& operator<<(ostream& os, Repeater& repeater)
{
    os << repeater.data << " " << repeater.ptr << " " << *repeater.ptr;
}

int main()
{
    Repeater* xiaoming = new Repeater(2, "xiaoming");
    Repeater xiaohong(3, "xiaohong");
    shared_ptr<Repeater> pshared1, pshared2, pshared3, pshared4, pshared5; //内部是空指针

    //构造
    //pshared4 = shared_ptr<Repeater>(xiaohong); //错误，参数为指针类型 pshared4过期时，应用于分堆内存，这是错误的
    pshared4 = shared_ptr<Repeater>(xiaoming);
    cout << "[1]count: " << pshared4.use_count() << "\n"; //1

    pshared5 = shared_ptr<Repeater>(new Repeater(5, "xiaohua"));
    cout << "[2]count: " << pshared5.use_count() << "\n"; //1

    shared_ptr<Repeater> pshared6 = shared_ptr<Repeater>(xiaoming); //不能增加引用计数
    cout << "[3]count: " << pshared6.use_count() << "\t" << pshared4.use_count() << "\n"; //1   1

    shared_ptr<Repeater> pshared7(pshared4); //拷贝构造，引用计数+1
    cout << "[4]count: " << pshared7.use_count() << "\t" << pshared4.use_count() << "\n"; //2   2

    //pshared7 = xiaoming; //错误，不存隐式转换

    ///make_shared用法
    //pshared1 = make_shared<Repeater>(xiaoming); //错误，参数为对象类型
    pshared1 = make_shared<Repeater>(Repeater(5, "xiaofang")); //参数为对象
    cout << "[5]count: " << pshared1.use_count() << "\n"; //1

    pshared2 = make_shared<Repeater>(xiaohong);
    cout << "[6]count: " << pshared2.use_count() << "\n"; //1

    pshared3 = make_shared<Repeater>(4, "xiaolan");
    cout << "[7]count: " << pshared3.use_count() << "\n"; //1

    shared_ptr<Repeater> pshared9 = pshared3; //引用计数+1
    cout << "[8]count: " << pshared9.use_count() << "\t" << pshared3.use_count() << "\n"; //2    2

    pshared3 = pshared1; //pshread1引用计数+1，pshared3原来的引用计数-1，pshared3的引用计数和pshared1相同
    cout << "[9]count: " << pshared3.use_count() << "\t" << pshared1.use_count() << "\t" << pshared9.use_count() << "\n"; //2    2   1

    // pshared3 = shared_ptr<Repeater>(xiaoming);//不推荐，两个智能指针管理同一块内存
    shared_ptr<Repeater> pshared10 = make_shared<Repeater>(xiaohong); //不能增加引用计数
    cout << "[10]count: " << pshared10.use_count() << "\t" << pshared2.use_count() << "\n"; //1  1

    Repeater* getPtr = pshared10.get();
    if (getPtr != nullptr) {
        cout << "[11]" << *getPtr << "\n"; //3 0x767ec8 xiaohong
    } else {
        cout << "[11]"
             << "pshared10 use_count is :" << pshared10.use_count() << "\n";
    }

    cout << "[12]" << pshared3.use_count() << "\t" << pshared10.use_count() << "\n"; //2    1
    pshared10.swap(pshared3); //交换pshared10和pshared9的指针
    cout << "[13]" << pshared3.use_count() << "\t" << pshared10.use_count() << "\n"; //1    2

    if (!pshared10) {
        cout << "[14]"
             << "null object\n";
    } else {
        cout << "[14]"
             << "not null object\n"; //not null object
    }

    if (pshared10.unique()) {
        cout << "[15]"
             << "pshared 10 use_count is 1\n";
    } else {
        cout << "[15]"
             << "pshared 10 use_count > 1\n"; //pshared 10 use_count > 1
    }

    ///unique

    Repeater* lala = new Repeater(9, "lala");
    unique_ptr<Repeater> punique1 = unique_ptr<Repeater>(lala);
    punique1->comment();
    cout << "\n";

    unique_ptr<Repeater> punique2; //空智能指针

    //unique_ptr<Repeater> punique2(punique1); //错误，不能拷贝
    //unique_ptr<Repeater> punique2 = punique1; //错误，不能拷贝
    //punique2 = punique1; //错误，不能赋值

    punique2 = move(punique1); //正确，移动语义
    if (punique2) {
        cout << "[16]move success!\n";
    } else {
        cout << "[16]move failed!\n";
    }

    punique2->comment();
    cout << "\n";

    punique2 = nullptr; //释放指向的对象,并将punique2置为空
    if (lala == nullptr) {
        cout << "[17]release success!\n";
        lala = new Repeater(10, "lala"); //重新申请内存
    } else {
        lala->comment();
        cout << "\n[17]release failed!\n";
    }

    if (!punique2) {
        cout << "[18]release success!\n";
    } else {
        cout << "[18]release failed!\n";
    }

    punique2 = unique_ptr<Repeater>(lala);
    getPtr = punique2.release(); //释放所有权，并置将智能指针置为空
    if (!punique2) {
        cout << "[19]release success!\n";
    } else {
        cout << "[19]release failed!\n";
    }

    punique2 = unique_ptr<Repeater>(lala);
    punique2.reset(); //释放指向的对象，并且置为空智能指针

    if (!punique2) {
        cout << "[20]release success!\n";
    } else {
        cout << "[20]release failed!\n";
    }
    if (lala == nullptr) {
        cout << "[20]release success!\n";
        lala = new Repeater(10, "lala"); //重新申请内存
    } else {
        lala->comment();
        cout << "\n[20]release failed!\n";
    }

    punique2.reset(lala); //释放指向的对象，并且指向新对象
    punique2.reset(nullptr); //释放指向的对象，并且置为空智能指针

    return 0;
}

//超过punique2的作用域，內存釋放