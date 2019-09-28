#ifndef WEAKPTR_H
#define WEAKPTR_H

#include "SharedPtr.h"

template <typename T>
class WeakPtr {
public:
    WeakPtr()
    {
        ptr = nullptr;
        count = new size_t(0);
        weak_count = new size_t(0);
    };
    WeakPtr(SharedPtr<T>& rhs)
    {
        ptr = rhs.getPtr();
        count = rhs.getCount();
        weak_count = rhs.getWeakCount();
        if (rhs.getWeakCount() == nullptr)
            return;
        (*weak_count)++;
    };

    size_t use_count()
    {
        return *weak_count;
    }

    WeakPtr<T>& operator=(SharedPtr<T>& rhs)
    {
        clear();
        if (rhs.getPtr() == nullptr)
            return *this;
        count = rhs.getCount();
        weak_count = rhs.getWeakCount();
        ptr = rhs.getPtr();
        (*weak_count)++;
        return *this;
    }

private:
    void clear()
    {
        if (ptr == nullptr) {
            return;
        }

        (*weak_count)--;

        if ((*count) == 0 && (*weak_count) == 0) {
            delete ptr;
            delete count;
            delete weak_count;

            ptr = nullptr;
            count = nullptr;
            weak_count = nullptr;
        }
    }

    T* ptr;
    size_t* count;
    size_t* weak_count;
};

#endif