// OutputExcercise1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class A {
public:
    virtual int f() {
        return 10;
    }
    virtual ~A()
    {

    }
};
class B : public A {
    int f() {
        return 11;
    }
    virtual ~B() {

    }
};

template<class T>
class C
{
    T _v;
public:
    C(T v) : _v(v) {

    }
    template <class T>
    friend ostream& operator<< (ostream& c, const C<T>& v);
    //friend ostream& operator<<(ostream& c, const C<int>& v);
};

//template<class T> class C;
//template <class T>
//ostream& operator<< (ostream& c, const C<T>& v);

//This code won't compile because it is a template function
template <class T>
ostream& operator<< (ostream& c, const C<T>& v) {
    c << v._v;
    return c;
}
/*
ostream& operator<< (ostream& c, const C<int>& v) {
    c << v._v;
    return c;
}
*/
int main()
{
    vector<A*> v;
    for (int i = 10; i > 0; i--) {
        i % 2 > 0 ? v.push_back(new A) : v.push_back(new B);
    }
    auto it = v.begin();
    while (it != v.end()) {
        cout << v.back()->f() << " ";
        v.pop_back();
        it++;
    }
    cout << "\n======================================" << endl;
    C<int> c(10);
    C<char> d('a');
    cout << c << endl;
    cout << "\n======================================" << endl;
    cout << d << endl;
}
