#include "myshared_ptr.h"

int main()
{
    SharedPtr<int> sharedptr = SharedPtr<int>(new int(2));
    cout << "count: " << sharedptr.use_count() << "\n";

    Repeater* xiaoming = new Repeater(2, "xiaoming");
    Repeater xiaohong(3, "xiaohong");
    SharedPtr<Repeater> pshared1, pshared2, pshared3, pshared4, pshared5; //内部是空指针

    //构造
    //pshared4 = SharedPtr<Repeater>(xiaohong); //错误，参数为指针类型 pshared4过期时，应用于分堆内存，这是错误的
    pshared4 = SharedPtr<Repeater>(xiaoming);
    cout << "[1]count: " << pshared4.use_count() << "\n"; //1

    pshared5 = SharedPtr<Repeater>(new Repeater(5, "xiaohua"));
    cout << "[2]count: " << pshared5.use_count() << "\n"; //1

    SharedPtr<Repeater> pshared6 = SharedPtr<Repeater>(xiaoming); //不能增加引用计数
    cout << "[3]count: " << pshared6.use_count() << "\t" << pshared4.use_count() << "\n"; //1   1

    SharedPtr<Repeater> pshared7(pshared4); //拷贝构造，引用计数+1
    cout << "[4]count: " << pshared7.use_count() << "\t" << pshared4.use_count() << "\n"; //2   2

    //pshared7 = xiaoming; //错误，不存隐式转换

    ///make_shared用法
    //pshared1 = make_shared<Repeater>(xiaoming); //错误，参数为对象类型
    pshared1 = my_make_shared<Repeater>(Repeater(5, "xiaofang")); //参数为对象
    cout << "[5]count: " << pshared1.use_count() << "\n"; //1

    pshared2 = my_make_shared<Repeater>(xiaohong);
    cout << "[6]count: " << pshared2.use_count() << "\n"; //1

    pshared3 = my_make_shared<Repeater>(4, "xiaolan");
    cout << "[7]count: " << pshared3.use_count() << "\n"; //1

    SharedPtr<Repeater> pshared9 = pshared3; //引用计数+1
    cout << "[8]count: " << pshared9.use_count() << "\t" << pshared3.use_count() << "\n"; //2    2

    pshared3 = pshared1; //pshread1引用计数+1，pshared3原来的引用计数-1，pshared3的引用计数和pshared1相同
    cout << "[9]count: " << pshared3.use_count() << "\t" << pshared1.use_count() << "\t" << pshared9.use_count() << "\n"; //2    2   1

    // pshared3 = SharedPtr<Repeater>(xiaoming);//不推荐，两个智能指针管理同一块内存
    SharedPtr<Repeater> pshared10 = my_make_shared<Repeater>(xiaohong); //不能增加引用计数
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

    // if (!pshared10) {
    //     cout << "[14]"
    //          << "null object\n";
    // } else {
    //     cout << "[14]"
    //          << "not null object\n"; //not null object
    // }

    // if (pshared10.unique()) {
    //     cout << "[15]"
    //          << "pshared 10 use_count is 1\n";
    // } else {
    //     cout << "[15]"
    //          << "pshared 10 use_count > 1\n"; //pshared 10 use_count > 1
    // }

    return 0;
}