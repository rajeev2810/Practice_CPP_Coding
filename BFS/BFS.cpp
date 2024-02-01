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
