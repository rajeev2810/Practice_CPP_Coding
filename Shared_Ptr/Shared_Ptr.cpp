// Shared_Ptr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

template <typename T>
class sharedptr {
private:
	T* ptr{ nullptr };
	unsigned int* ref_count {nullptr};
public:
	sharedptr() : ptr(nullptr), ref_count(new unsigned int(0)) {

	}

	sharedptr(T* ptr) : ptr(ptr), ref_count(new unsigned int(1)) {

	}

	sharedptr(const sharedptr& sh)
	{
		ptr = sh.ptr;
		ref_count = sh.ref_count;
		if (nullptr != sh.ptr)
		{
			(*this->ref_count)++; // if the pointer is not null, increment the refCount
		}
	}

	sharedptr& operator= (sharedptr& sh)
	{
		cleanup();
		ptr = sh.ptr;
		ref_count = sh.ref_count;
		if (nullptr != sh.ptr)
		{
			(*this->ref_count)++; // if the pointer is not null, increment the refCount
		}
		return *this;
	}

	/*** Move Semantics ***/
	sharedptr(sharedptr&& dyingObj) // move constructor
	{
		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.ref_count;

		dyingObj.ptr = dyingObj.ref_count = nullptr; // clean the dying object
	}

	sharedptr& operator=(sharedptr&& dyingObj) // move assignment
	{
		cleanup(); // cleanup any existing data

		this->ptr = dyingObj.ptr; // share the underlying pointer
		this->refCount = dyingObj.ref_count;

		dyingObj.ptr = dyingObj.ref_count = nullptr; // clean the dying object
	}

	unsigned int get_count() const
	{
		return *this->ref_count; // *this->refCount
	}

	T* get() const
	{
		return this->ptr;
	}

	T* operator *() {
		return this->ptr;
	}

	T& operator->() {
		return *this->ptr;
	}

	~sharedptr() // destructor
	{
		cleanup();
	}
private:
	void cleanup() {
		(*ref_count)--;
		if (*ref_count == 0)
		{
			if (ptr != nullptr)
				delete ptr;
			
			delete ref_count;
		}
	}
};

class Box
{
public:
	int length, width, height;
	Box() : length(0), width(0), height(0)
	{
	}
};

int main()
{
	sharedptr<Box> obj;
	cout << obj.get_count() << endl; // prints 0
	sharedptr<Box> box1(new Box());
	cout << box1.get_count() << endl; // prints 1
	sharedptr<Box> box2(box1); // calls copy constructor
	cout << box1.get_count() << endl; // prints 2
	cout << box2.get_count() << endl; // also prints 2

	return 0;
}

