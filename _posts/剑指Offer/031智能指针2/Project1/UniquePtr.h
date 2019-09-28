#include <iostream>
using namespace std;

class Delete {
public:
	template<typename T>
	void operator()(T*p) const {
		delete p;
	};
};
template <typename T,typename D=Delete>
class UniquePtr {
public:
	explicit UniquePtr(T*_ptr = nullptr, const D &_del = D()) :ptr(_ptr), del(_del) {
	};
	~UniquePtr() {
		del(ptr);
	}

	UniquePtr(const UniquePtr&) = delete;
	UniquePtr &operator=(const UniquePtr) = delete;

	UniquePtr(UniquePtr &&rhs):ptr(rhs.ptr),del(std::move(rhs.del)) {
		rhs.ptr = nullptr;
	}

	template <typename... Args>
	friend UniquePtr<T> my_make_unique(Args&&... args);

	//template <typename T>
	friend UniquePtr<T> my_make_unique(const T& object);

	//右值
	UniquePtr &operator=(UniquePtr &&rhs) noexcept {
		if (*this != &rhs) {
			del(*this);
			ptr = rhs.ptr;
			del = std::move(rhs.del);
			rhs.ptr = nullptr;
		}
	}

	//放弃对指针的控制权
	T*release() {
		T*tmp = ptr;
		ptr = nullptr;
		return tmp;
	}
	//重置
	void reset() {
		del(ptr);
		ptr = nullptr;
	}
	void reset(T*p) {
		if (ptr) {
			del(ptr);
			ptr = p;
		}
		else {
			ptr = p;
		}
	}

	void swap(UniquePtr &rhs) {
		using std::swap;
		swap(ptr,rhs.ptr);
		swap(del,rhs.del);
	}

	T*get() {
		return ptr;
	}

	T& operator*() {
		return *ptr;
	}
	T* operator->() {
		return ptr;
	}

	T * ptr = nullptr;
	D del;
};


template <typename T, typename... Args>
UniquePtr<T> my_make_unique(Args&&... args)
{
	UniquePtr<T> uniqueptr;
	T* objectptr = new T(args...);

	uniqueptr.reset(objectptr);

	return uniqueptr;
};

template <typename T>
UniquePtr<T>& my_make_unique(const T& object)
{
	UniquePtr<T> uniqueptr;
	uniqueptr.reset(&object);
	return uniqueptr;
}