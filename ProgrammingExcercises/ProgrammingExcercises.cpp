// ProgrammingExcercises.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <algorithm>
#include <functional>

using namespace std;
template<class T>
struct Out {
    ostream& out;
    Out(ostream& o) : out(o) {

    }
    void operator() (const T& val) {
        out << val << " ";
    }
};

class A {
    int a;
public:
    A() = default;
    A(int a) :a(a) {

    }
    int getA() const { return a; }
    void setA(int a) { this->a = a; }
    bool operator==(A& b) {
        return a == b.a;
    }
};

struct Compare {
    bool operator()(const A& a, const A& b) {
        return a.getA() == b.getA();
    }

};

int main()
{
    char greetings[] = { 'W', 'e','l','\0' };
    std::cout << greetings;
    int myint[] = { 3,4,2,1,6,5,7,9,8,0 };
    vector<int>v(myint, myint + 10);
    set<int> s1(v.begin(), v.end());
    s1.insert(v.begin(), v.end());
    s1.erase(s1.lower_bound(2), s1.upper_bound(6));
    cout << "\n";
    for (auto it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << "\t";
    }
    cout << endl;
    cout << "======================================" << endl;
    deque<int>d1(myint, myint + 10);
    d1.empty(); // For testing
    v.empty();  // For testing
    cout << endl;
    if (v.empty()) {
        cout << "I am empty" << endl;
    }
    else
        cout << "I am not empty" << endl;

    cout << v.size() << "\t" << d1.size();
    cout << endl;
    cout << "======================================" << endl;
    int t1[] = { 1,2,3,4,5,6,7,8,9,0 };
    int t2[] = { 1,2,3,4,5,6,7,8,9,0 };
    vector<int> v1(t1, t1 + 10);
    vector<int> v2(t2, t2 + 10);
    vector<int> v3(10);
    transform(v1.begin(), v1.end(), v2.rbegin(), v3.begin(), minus<int>());
    for_each(v3.rbegin(), v3.rend(), Out<int>(cout));
    cout << endl;
    cout << "======================================" << endl;
    int t[] = { 1,2,3,4,5,1,2,3,4,5 };
    vector<A> v4{ t, t + 10 };
    A m1[] = {A(1), A(2), A(3)};
    vector<A>::iterator it;
    it = search(v4.begin(), v4.end(), m1, m1 + 3, Compare());
    cout << "Position: " << it->getA() <<"\t" << v4.begin()->getA() << endl;
    cout << "======================================" << endl;
}
