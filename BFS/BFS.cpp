// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Graph {
private:
    vector<vector<int>> ver{ 10 };
    map<int, bool> visited;
public:

    void add_edges(int src, int dest) {
        ver[src].push_back(dest);
    }

    void BFS(int vertices)
    {
        visited[vertices] = true;

        queue<int> q;
        q.push(vertices);

        while (!q.empty()) {
            int s = q.front();
            cout << s << endl;
            q.pop();
            for (auto adj : ver[vertices])
            {
                if (!visited[adj])
                {
                    visited[adj] = true;
                    q.push(adj);
                }
            }
        }
    }
};

int main()
{
    Graph g;
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
