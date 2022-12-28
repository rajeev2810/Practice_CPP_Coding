// DFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "map"
#include <unordered_map>

using namespace std;

class Graph {
private:
    vector<vector<int>> v{ 10 };
    map<int, bool> visited;

public:
    void add_edges(int src, int dest) {
        v[src].push_back(dest);
    }

    void DFS(int a)  {
        visited[a] = true;
        std::cout << a << " ";
        
        vector<int>::iterator it = v[a].begin();
        for (; it != v[a].end(); it++) {
            if(!visited[*it])
                DFS(*it);
        }
    }
};

class Graph1 {
    vector<vector<int>> vertices{ 10};
    unordered_map<int, bool> visited{};

public:
    void add_edges(int src, int dest) {
        vertices[src].push_back(dest);
    }

    void DFS(int a) {
        visited[a] = true;

        std::cout << a << "\t";

        auto it = vertices[a].begin();
        for (; it != vertices[a].end(); it++)
        {
            if (!visited[*it]) {
                DFS(*it);
            }
        }
    }
};

int main()
{
    Graph1 g;
    g.add_edges(0, 1);
    g.add_edges(0, 2);
    g.add_edges(1, 2);
    g.add_edges(2, 0);
    g.add_edges(2, 3);
    g.add_edges(3, 3);

    cout << "Following is Depth First Traversal"
        " (starting from vertex 2) \n";

    // Function call
    g.DFS(2);
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
