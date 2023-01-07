// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
#include <utility>

template<typename T>
class Array {
private:
    T* m_ptr{ nullptr };
    size_t m_size{ 0 };

    bool IsValidIndex(int index) const {
        return (index >= 0 && index < m_size);
    }
public:
    Array() = default;

    explicit Array(size_t size) {
        if (size > 0)
        {
            m_size = size;
            m_ptr = new T[size];
        }
    }

    Array(const Array& source) {
        if (!source.IsEmpty())
        {
            m_size = source.m_size;
            m_ptr = new T[m_size];
        }
        for (int i = 0; i < m_size; i++) {
            m_ptr[i] = source.m_ptr[i];
        }
    }

    Array(Array&& source): m_size(source.m_size), m_ptr(source.m_ptr) {
        source.m_ptr = nullptr;
        source.m_size = 0;        
    }

    ~Array() {
        if (m_ptr)
            delete[] m_ptr;
    }

    Array& operator=(Array& source) {
        swap(this->m_size, source.m_size);
        swap(this->m_ptr, source.m_ptr);

        return *this;
    }

    int size() const {
        return m_size;
    }

    bool IsEmpty() const
    {
        return m_size == 0;
    }

    T& operator[] (int index) {
        return m_ptr[index];
    }

    T operator[] (int index) const {
        return m_ptr[index];
    }
};

template<typename T>
inline std::ostream& operator<< (std::ostream& cout, const Array<T>& arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << "]";

    return cout;
}

int main()
{
    Array<int> a{ 3 };
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;

    std::cout << "a = " << a << std::endl;

}
