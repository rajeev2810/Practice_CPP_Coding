// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
#include <vector>
#include <thread>
#include <atomic>
#include <memory>

using namespace std;

class A
{
public:
    int a;  
};

inline bool operator<(const A& lhs, const A& rhs)
{
    return lhs.a < rhs.a;
}

int fun(int a) {
    return a * a;
}

bool compareVectors(vector<int> v1, vector<int> v2) {
    // Check if the vectors are the same size
    if (v1.size() != v2.size()) {
        return false;
    }

    // Create a set from the second vector
    set<int> s2(v2.begin(), v2.end());

    // Iterate over the first vector and check if each element is in the set
    for (int element : v1) {
        if (!s2.count(element)) {
            return false;
        }
    }

    // If all the elements of the first vector are in the set, return true
    return true;
}


int main()
{
    std::set<std::shared_ptr<A>> setofstruct;
    std::shared_ptr<A> a1{new A()};
    a1->a = 10;
    setofstruct.insert(a1);
    std::vector<std::shared_ptr<A>> vecofstruct;
    vecofstruct.push_back(a1);

    std::atomic_int x{ 0 }; // Use std::atomic to prevent data race.
    std::thread t{ [&x] {   // Simple lambda that captures a reference of x.
        x = fun(2);        // Call function and assign return value.
    } };
    /* Do something while thread is running... */
    t.join();
    std::cout << "Value: " << x << std::endl;

    // Create two vectors
    vector<int> v1 = { 1, 2, 3 };
    vector<int> v2 = { 3, 2, 1 };

    // Compare the vectors
    bool result = compareVectors(v1, v2);

    // Print the result
    cout << result << endl;

}
/************************************
for (auto a_elt: a) {
    if (std::find(b.begin(), b.end(), a_elt) == b.end()) {
        return false;
    }
}
return true;
You can also use std::all_of:

return std::all_of(a.begin(), a.end(), [](int a_elt) {
    return std::find(b.begin(), b.end(), a_elt) != b.end();
});
**************************************/

/****Design Idea**************************
4 elevators / 10 floors

API:


class Lift
{
    NearestLift(current floor);
    ResetCount();
    GetOtherLiftsPosition();
};

class Traffic
{
    GoingUP();
    GoingDown();
    Traffic();
};
*****************************************/











