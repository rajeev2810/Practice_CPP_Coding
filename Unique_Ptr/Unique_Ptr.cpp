#include <iostream>

using namespace std;

template <typename T>
class uniqueptr
{
private:
	T* ptr{ nullptr };

public:
	uniqueptr() : ptr(nullptr) {

	}

	uniqueptr(T* a): ptr(a)
	{
	}

	uniqueptr(const uniqueptr& ptrobj) = delete;

	uniqueptr& operator= (uniqueptr& ptrobj) = delete;

	/*** Move Semantics ***/
	uniqueptr(uniqueptr&& dyingObj) noexcept// move constructor
	{
		this->ptr = dyingObj.ptr; // share the underlying pointer
		dyingObj.ptr = nullptr; // clean the dying object
		cout << "Move constructor called for unique ptr" << endl;
	}

	uniqueptr& operator=(uniqueptr&& dyingObj) noexcept// move assignment
	{
		if (ptr != nullptr)
			delete ptr;

		this->ptr = dyingObj.ptr; // share the underlying pointer
		dyingObj.ptr = nullptr; // clean the dying object

		cout << "Move assignment called for unique ptr" << endl;
		return *this;
	}

	~uniqueptr()
	{
		if(ptr != nullptr)
			delete ptr;
	}

	T& operator->()
	{
		return *ptr;
	}

	T* operator*()
	{
		return ptr;
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
	uniqueptr<Box> obj;
	uniqueptr<Box> box1(new Box());
	uniqueptr<Box> box2(std::move(box1)); // calls move constructor
	uniqueptr<Box> box3;
	box3 = std::move(box2);	// calls move assignment

	return 0;
}