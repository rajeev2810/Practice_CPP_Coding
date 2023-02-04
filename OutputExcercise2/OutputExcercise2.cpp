// OutputExcercise2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

class B {
    int val;
public:
    B(int v=0) :val(v) {

    }
    int getv() const{
        return val;
    }
    operator int() const {
        return val;
    }
};

template<class T>
struct Out {
    ostream& out;
    Out(ostream& o) : out(o) {

    }
    void operator()(const T& val) {
        out << setw(3) << hex << val;
    }
};

int f1(int& x, int c) {
    c = c - 1;
    if (c == 0) return 1;
    x = x + 1;
    return f1(x, c) * c;
}

int main()
{
    
    int t[] = { 1,2,3,4,5,6,7,8,9,10,5,4,5,5 };
    fstream f("test.out", ios::trunc | ios::out);
    list<B> l(t, t + 14);
    for_each(l.begin(), l.end(), Out<B>(f));
    f.close();
    f.open("test.out");
    //Test1
    cout << count(l.begin(), l.end(), 4);
    /* Test2
    for (; f.good();) {
        B i;
        //f >> i;
        cout << i << " ";
    }
    */
    //Test3
    //int a, b, c;
    //cin >> a >> b >> c;
    //cout << a << b << c;
    //f.close();
    int a = 5;
    //Test4
    cout << "\n==============================" << endl;
    cout << f1(a, a);
    cout << "\n==============================" << endl;
    //Test5
    cout << rank<int[10]>::value;
    cout << "\n==============================" << endl;
    cout << rank<char[10]>::value;
    cout << "\n==============================" << endl;
    cout << rank<string[10]>::value;
    //Test6
    cout << "\n==============================" << endl;
    cout << is_array<int>::value;
    cout << "\n==============================" << endl;
    cout << is_array<char[10]>::value;
    cout << "\n==============================" << endl;
    cout << is_array<string>::value;
    return 0;
}
