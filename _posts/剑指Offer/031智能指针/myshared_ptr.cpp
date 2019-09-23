

#include <iostream>

using namespace std;

template <typename T>
class SharedPtr {
public:
    ///构造函数
    //显式构造函数
    explicit SharedPtr(T* _ptr = nullptr)
    {
        if (_ptr) {
            count = new size_t(1);
            weak_count = new size_t(0);
        } else {
            count = new size_t(0);
            weak_count = new size_t(0);
        }
    };

    //拷贝构造函数
    SharedPtr(const SharedPtr<T>& rhs)
    {
        ptr = nullptr;
        count = nullptr;
        weak_count = nullptr;
    };

    //拷贝赋值运算符
    SharedPtr& operator=(const SharedPtr& rhs)
    {
        if (this == &rhs) {
            return *this; //自我赋值不能增加
        }
        if (this->ptr == rhs.ptr) {
            return *this; //不能增加
        }

        this->ptr = rhs->ptr;
        this->count = rhs->count;
        (*this->count)++;
        return *this;
    };

    ///修改器
    void reset(SharedPtr* ptr = nullptr){

    };
    void swap(SharedPtr* ptr){};

    ///观察器
    T* get() const
    {
        return this->ptr;
    };
    void swap(SharedPtr& rhs)
    {
        size_t* tmp_count = rhs.count;
        T* temp_ptr = rhs.ptr;
        size_t* tmp_weak_count = rhs.weak_count;

        this->count = rhs.count;
        this->ptr = rhs.ptr;
        this->weak_count = rhs.weak_count;

        rhs.count = tmp_count;
        rhs.ptr = temp_ptr;
        rhs.weak_count = tmp_weak_count;
    };

    //解引用锁存储的指针，如果存储的指针为空，则行为未定义
    T& operator*()
    {
        return *(this->ptr);
    };
    T* operator->()
    {
        return this->ptr;
    };
    size_t use_count()
    {
        return *this->count;
    };
    bool unique()
    {
        if (*this->count == 1)
            return true;
        return false;
    };

    ~SharedPtr()
    {
        clear();
    };

private:
    void clear()
    {
        if (this->ptr != nullptr) {
            (*this->count)--;
            if (*this->count == 0) {
                delete this->ptr;
                delete this->count;
                delete this->weak_count;
                this->ptr = nullptr;
                this->count = nullptr;
                this->weak_count = nullptr;
            }
        }
    };

private:
    T* ptr;
    size_t* count;
    size_t* weak_count;
};

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

int main()
{
    SharedPtr<int> sharedptr = SharedPtr<int>(new int(2));
    cout << "count: " << sharedptr.use_count() << "\n";

    Repeater* xiaoming = new Repeater(2, "xiaoming");
    Repeater xiaohong(3, "xiaohong");
    SharedPtr<Repeater> pshared1, pshared2, pshared3, pshared4, pshared5; //内部是空指针

    // //构造
    // //pshared4 = SharedPtr<Repeater>(xiaohong); //错误，参数为指针类型 pshared4过期时，应用于分堆内存，这是错误的
    // pshared4 = SharedPtr<Repeater>(xiaoming);
    // cout << "[1]count: " << pshared4.use_count() << "\n"; //1

    // pshared5 = SharedPtr<Repeater>(new Repeater(5, "xiaohua"));
    // cout << "[2]count: " << pshared5.use_count() << "\n"; //1

    // SharedPtr<Repeater> pshared6 = SharedPtr<Repeater>(xiaoming); //不能增加引用计数
    // cout << "[3]count: " << pshared6.use_count() << "\t" << pshared4.use_count() << "\n"; //1   1

    // SharedPtr<Repeater> pshared7(pshared4); //拷贝构造，引用计数+1
    // cout << "[4]count: " << pshared7.use_count() << "\t" << pshared4.use_count() << "\n"; //2   2

    //pshared7 = xiaoming; //错误，不存隐式转换

    ///make_shared用法
    //pshared1 = make_shared<Repeater>(xiaoming); //错误，参数为对象类型
    // pshared1 = make_shared<Repeater>(Repeater(5, "xiaofang")); //参数为对象
    // cout << "[5]count: " << pshared1.use_count() << "\n"; //1

    // pshared2 = make_shared<Repeater>(xiaohong);
    // cout << "[6]count: " << pshared2.use_count() << "\n"; //1

    // pshared3 = make_shared<Repeater>(4, "xiaolan");
    // cout << "[7]count: " << pshared3.use_count() << "\n"; //1

    // SharedPtr<Repeater> pshared9 = pshared3; //引用计数+1
    // cout << "[8]count: " << pshared9.use_count() << "\t" << pshared3.use_count() << "\n"; //2    2

    // pshared3 = pshared1; //pshread1引用计数+1，pshared3原来的引用计数-1，pshared3的引用计数和pshared1相同
    // cout << "[9]count: " << pshared3.use_count() << "\t" << pshared1.use_count() << "\t" << pshared9.use_count() << "\n"; //2    2   1

    // // pshared3 = SharedPtr<Repeater>(xiaoming);//不推荐，两个智能指针管理同一块内存
    // SharedPtr<Repeater> pshared10 = make_shared<Repeater>(xiaohong); //不能增加引用计数
    // cout << "[10]count: " << pshared10.use_count() << "\t" << pshared2.use_count() << "\n"; //1  1

    // SharedPtr<Repeater> pshared10;
    // Repeater* getPtr = pshared10.get();
    // if (getPtr != nullptr) {
    //     cout << "[11]" << *getPtr << "\n"; //3 0x767ec8 xiaohong
    // } else {
    //     cout << "[11]"
    //          << "pshared10 use_count is :" << pshared10.use_count() << "\n";
    // }

    // cout << "[12]" << pshared3.use_count() << "\t" << pshared10.use_count() << "\n"; //2    1
    // pshared10.swap(pshared3); //交换pshared10和pshared9的指针
    // cout << "[13]" << pshared3.use_count() << "\t" << pshared10.use_count() << "\n"; //1    2

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