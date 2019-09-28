#ifndef SHAREDPTR_H
#define SHAREDPTR_H

#include <iostream>

using namespace std;

template <typename T>
class SharedPtr {
public:
	///���캯��
	//��ʽ���캯��
	explicit SharedPtr(T* _ptr = nullptr)
	{
		if (_ptr) {
			ptr = _ptr;
			count = new size_t(1);
			weak_count = new size_t(0);
		}
		else {
			count = new size_t(0);
			weak_count = new size_t(0);
		}
	};

	//�������캯��
	SharedPtr(const SharedPtr<T>& rhs)
	{
		this->count = rhs.count;
		this->ptr = rhs.ptr;
		this->weak_count = rhs.weak_count;
		(*this->count)++;
	};

	//������ֵ�����
	SharedPtr& operator=(const SharedPtr& rhs)
	{
		if (this == &rhs) {
			return *this; //���Ҹ�ֵ��������
		}
		if (this->ptr == rhs.ptr) {
			return *this; //��������
		}

		(*this->count)--;

		this->ptr = rhs.ptr;
		this->count = rhs.count;
		(*this->count)++;
		return *this;
	};

	//bool operator()() const
	//{
	//	return ptr == nullptr;
	//}

	template <typename... Args>
	friend SharedPtr<T> my_make_shared(Args&&... args);

	//template <typename T>
	friend SharedPtr<T> my_make_shared(const T& object);

	///�޸���
	void reset(T* ptr = nullptr)
	{
		if (ptr == nullptr) {
			*(this->count) = 0;
			(this->ptr) = nullptr;
		}
		else {
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

	///�۲���
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

	//���������洢��ָ�룬����洢��ָ��Ϊ�գ�����Ϊδ����
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
	void setPtr(T* ptr)
	{
		this->ptr = ptr;
	}
	size_t* getCount()
	{
		return count;
	}
	void setCount(size_t* count)
	{
		this->count = count;
	}
	size_t* getWeakCount()
	{
		return weak_count;
	}
	void setWeakCount(size_t* weak_count)
	{
		this->weak_count = weak_count;
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
				this->ptr = nullptr;
			}

			if (*(this->weak_count) == 0 && *(this->count) == 0) {
				delete this->count;
				delete this->weak_count;

				this->count = nullptr;
				this->weak_count = nullptr;
			}
		}
	};

private:
	T * ptr;
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