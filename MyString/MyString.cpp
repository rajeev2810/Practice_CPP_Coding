// MyString.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ostream>

class my_string
{
private:
	char* buf = nullptr;
	unsigned int size = 0;

public:
	my_string() : buf(nullptr), size(0) // default constructor
	{
	}

	my_string(const char* const buffer) // constructor
	{
		size = strlen(buffer);
		buf = new char[size + 1]; // + 1 for the keeping the null character
		strncpy_s(buf, size + 1, buffer, size); // copy from the incoming buffer to character buffer of the new object
	}

	my_string(const my_string& obj) // copy constructor
	{
		size = obj.size;
		buf = new char[size + 1]; // + 1 for the keeping the null character
		strncpy_s(buf, size + 1, obj.buf, size); // copy from the incoming buffer to character buffer of the new object
	}

	my_string& operator=(const my_string& obj) // copy assignment
	{
		__cleanup__(); // cleanup any existing data

		// Copy data from the newly assigned my_string object
		size = obj.size;
		buf = new char[size + 1]; // + 1 for the keeping the null character
		strncpy_s(buf, size + 1, obj.buf, size); // copy from the incoming buffer to character buffer of the new object
		return *this;
	}

	my_string(my_string&& dyingObj) noexcept // move constructor
		// && is a reference operator defined in the C++11 standard 
		// which means "dyingObj" is an r-value reference.
		// Compiler calls this constructor when the object passed in the argument
		// is about to die due to scope end or such
	{
		__cleanup__(); // cleanup any existing data

		// Copy data from the incoming object
		size = dyingObj.size;

		// Transfer ownership of underlying char buffer from incoming object to this object
		buf = dyingObj.buf;
		dyingObj.buf = nullptr;
	}

	my_string& operator=(my_string&& dyingObj) noexcept // move assignment
	{
		__cleanup__(); // cleanup any existing data

		// Copy data from the incoming object
		size = dyingObj.size;

		// Transfer ownership of underlying char buffer from incoming object to this object
		buf = dyingObj.buf;
		dyingObj.buf = nullptr;

		return *this;
	}

	my_string operator+(const my_string& obj) // concatenation
	{
		my_string s; // create a new string named 's'
		s.size = this->size + obj.size;
		s.buf = new char[s.size + 1]; // allocate memory to keep the concatenated string
		strncpy_s(s.buf, this->size + 1, this->buf, this->size); // copy the 1st string
		strncpy_s(s.buf + this->size, obj.size + 1, obj.buf, obj.size);

		return s;
	}

	unsigned int length()
	{
		return size;
	}

	const char* c_str() const
	{
		return buf;
	}

	~my_string() // destructor
	{
		__cleanup__();
	}

private:
	void __cleanup__()
	{
		if (buf != nullptr)
		{
			delete[] buf;
		}
		size = 0;
	}
};

std::ostream& operator<<(std::ostream& cout, const my_string& obj)
{
	cout << obj.c_str();
	return cout;
}

int main()
{
	my_string a("FirstName");
	my_string b("LastName");
	my_string c = a + b;
	std::cout << c;
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
