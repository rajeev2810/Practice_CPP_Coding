// CommonExcercise.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

class A {
public: 
    virtual string ParseMessage()
    {
        return "A";
    }
    virtual string ParseNode()
    {
        return ParseMessage();
    }
};

class B: public A {
public:
    virtual string ParseMessage()
    {
        return "B";
    }
    virtual string ParseNode()
    {
        return ParseMessage();
    }
};

class C : public B {
public:
    virtual string ParseMessage()
    {
        return "C";
    }
    virtual string ParseNode()
    {
        return ParseMessage();
    }
};

int main()
{
    A* a = new A();
    A* b = new B();
    A* c = new C();
    cout << a->ParseNode() << endl;
    cout << b->ParseNode() << endl;
    cout << c->ParseNode() << endl;
}
