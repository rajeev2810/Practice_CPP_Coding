#include <iostream>
#include <string>

using namespace std;

class NoVirtual {
  int a;
  float b;
  double c;
  //string d;
public:
  void x() const {}
  int i() const { return 1; }
  void ret() {}

};

class OneVirtual {
  //int a;
public:
  virtual void x() const {}
  int i() const { return 1; }
};

class TwoVirtuals {
  //int a;
public:
  virtual void x() const {}
  virtual int i() const { return 1; }
};

int main() {
  cout << "int: " << sizeof(int) << endl;
  cout << "NoVirtual: "
       << sizeof(NoVirtual) << endl;
  cout << "void* : " << sizeof(void*) << endl;
  cout << "OneVirtual: "
       << sizeof(OneVirtual) << endl;
  cout << "TwoVirtuals: "
       << sizeof(TwoVirtuals) << endl;
}