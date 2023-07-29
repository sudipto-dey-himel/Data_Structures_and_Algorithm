#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

void BFS(vector<vector<int>> &graph, int start, vector<bool> visited)
{
    queue<int> q;
    visited[start] = true;
    q.push(start);
    while (!q.empty())
    {
        int current = q.front();
        cout << current << " ";
        q.pop();
        for (auto neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of Vertices :: ";
    cin >> vertices;
    cout << "Enter the number of Edges :: ";
    cin >> edges;

    cout << "Enter Edges : " << endl;
    vector<vector<int>> graph(vertices);
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting Node : ";
    cin >> start;
    cout << "BFS :: " << endl;
    vector<bool> visited(vertices, false);
    BFS(graph, start, visited);
    return 0;
}


/* input format:
Enter the number of Vertices :: 6
Enter the number of Edges :: 8
Enter the vertices :
0 1
0 2
0 4
1 2
1 4
2 3
3 4
4 5
Enter starting Node : 0

Output format:
BFS ::
0 1 2 4 3 5
*/
