// MapObjects.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <map>
#include <string>

class A
{
private:
    int a;
    std::string b;

public:
    A(int init_a, std::string init_b) : a(init_a), b(init_b) {};
    void output_a() { std::cout << a << "\t" << b << std::endl; }
};

int main()
{

    std::map<size_t, A> result_map;
    for (size_t iter = 0; iter < 10; ++iter)
    {
        result_map.emplace(iter, A(iter, std::to_string(rand())));
    }

    auto f = result_map.begin();
    for (;f != result_map.end(); f++)
        f->second.output_a();

    return 0;
}