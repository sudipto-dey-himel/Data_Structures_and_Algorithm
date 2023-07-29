#include <bits/stdc++.h>
#include <vector>
using namespace std;

const int M = 1e5 + 7;

vector<int> graph[M];
bool visited[M];

void DFS(int st)
{
    visited[st] = true;
    cout << st << " ";
    for (auto neighbor : graph[st])
    {
        if (!visited[neighbor])
            DFS(neighbor);
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of Vertices : ";
    cin >> vertices;
    cout << "Enter the number of Edges : ";
    cin >> edges;

    cout << "Enter Edges :: " << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter starting Vertex : ";
    cin >> start;

    cout << "DFS :: ";
    DFS(start);

    return 0;
}

/*  Input format :
Enter the number of Vertices : 6
Enter the number of Edges : 8
Enter Edges ::
0 1
1 4
4 5
4 3
3 2
2 1
2 0
0 4
Enter starting Vertex : 0

Output format :
DFS :: 0 1 4 5 3 2
*/
