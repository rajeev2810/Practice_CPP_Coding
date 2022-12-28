// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
private:
    vector<vector<int>> ver;
    int V;
public:
    Graph(int v) : V(v) {
        ver.resize(V);
    }

    void add_edges(int src, int dest) {
        ver[src].push_back(dest);
    }

    void BFS(int vertices)
    {
        vector<bool> visited{};
        visited.resize(V, false);
        visited[vertices] = true;

        list<int> q;
        q.push_back(vertices);

        while (!q.empty()) {
            int s = q.front();
            cout << s << endl;
            q.pop_front();
            for (auto adj : ver[vertices])
            {
                if (!visited[adj])
                {
                    visited[adj] = true;
                    q.push_back(adj);
                }
            }
        }
    }
};

int main()
{
    Graph g(4);
    g.add_edges(0, 1);
    g.add_edges(0, 2);
    g.add_edges(1, 2);
    g.add_edges(2, 0);
    g.add_edges(2, 3);
    g.add_edges(3, 3);

    cout << "Following is Breadth First Traversal "
        << "(starting from vertex 2) \n";
    g.BFS(1);

    return 0;
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
