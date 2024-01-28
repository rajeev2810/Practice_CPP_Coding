// VectorClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class Vector {
private:
    size_t size;
    size_t capacity;
    T* arr;
public:
    Vector() : size(0), capacity(1), arr(new T[1]){

    }

    T& operator[](int index) {
        return arr[index];
    }

    const T& operator[](int index) const {
        return arr[index];
    }

    void push_back(const T& x) {
        if (size == capacity) {
            size_t newCapacity = 2 * capacity + 1;
            if (newCapacity < size)
                return;

            T* newArray = new T[newCapacity];
            for (int k = 0; k < size; ++k)
                newArray[k] = std::move(arr[k]);

            capacity = newCapacity;
            std::swap(arr, newArray);
            delete[] newArray;
        }
        arr[size++] = x;
    }

    void insert(size_t index, T data) {
        if (size == capacity) {
            push_back(data);
        }
        else {
            arr[index] = data;
            size++;
        }
    }

    size_t length() const {
        return size;
    }
};

int main()
{
    int n;
    Vector<string> names;
    cout << "How many names? " << flush;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter name #" << i+1 << ": " << flush;
        std::string aName;
        cin >> aName;
        names.push_back(aName);
    }

    for (int i = 0; i < names.length(); i++) {
        cout << names[i] << endl;
    }
}
