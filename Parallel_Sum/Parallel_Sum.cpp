// Parallel_Sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <thread>

size_t parallel_sum(size_t first, size_t last) {
    size_t sum{};
    size_t thread_count = 6;
    std::vector<std::thread> parallel_jobs;

    for (int i = 0; i < thread_count; i++)
    {
        parallel_jobs.emplace_back(std::thread([]() {

        }));
    }

    return sum;
}


int main()
{
    std::cout << parallel_sum(0, 1'000'000) << "\n";
    std::cout << parallel_sum(0, 1'000'000) << "\n";
    std::cout << parallel_sum(0, 1'000'000) << "\n";
    std::cout << parallel_sum(0, 1'000'000) << "\n";
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
