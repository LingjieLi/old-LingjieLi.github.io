#ifndef SHAREDPTR_H
#define SHAREDPTR_H

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
        this->count = rhs.count;
        this->ptr = rhs.ptr;
        this->weak_count = rhs.weak_count;
        (*this->count)++;
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

        (*this->count)--;

        this->ptr = rhs.ptr;
        this->count = rhs.count;
        (*this->count)++;
        return *this;
    };

    bool operator()() const
    {
        return ptr == nullptr;
    }

    template <typename... Args>
    friend SharedPtr<T> my_make_shared(Args&&... args);

    //template <typename T>
    friend SharedPtr<T> my_make_shared(const T& object);

    ///修改器
    void reset(T* ptr = nullptr)
    {
        if (ptr == nullptr) {
            *(this->count) = 0;
            (this->ptr) = nullptr;
        } else {
            *(this->count) = 1;
            (this->ptr) = ptr;
        }
    };
    void swap(SharedPtr* ptr)
    {
        T* tmp_ptr = ptr->ptr;
        size_t* tmp_count = ptr->count;
        size_t* tmp_weak_count = ptr->weak_count;

        ptr->ptr = this->ptr;
        ptr->count = this->count;
        ptr->weak_count = this->weak_count;

        this->ptr = tmp_ptr;
        this->count = tmp_count;
        this->weak_count = tmp_weak_count;
    };

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

        rhs.count = this->count;
        rhs.ptr = this->ptr;
        rhs.weak_count = this->weak_count;

        this->count = tmp_count;
        this->ptr = temp_ptr;
        this->weak_count = tmp_weak_count;
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

    T* getPtr()
    {
        return ptr;
    }
    size_t* getCount()
    {
        return count;
    }
    size_t* getWeakCount()
    {
        return weak_count;
    }

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

template <typename T, typename... Args>
SharedPtr<T> my_make_shared(Args&&... args)
{
    SharedPtr<T> sharedptr;
    T* objectptr = new T(args...);

    sharedptr.reset(objectptr);

    return sharedptr;
};

template <typename T>
SharedPtr<T>& my_make_shared(const T& object)
{
    SharedPtr<T> sharedptr;
    sharedptr.reset(&object);
    return sharedptr;
}

#endif