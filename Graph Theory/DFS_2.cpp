#include <bits/stdc++.h>
#include <vector>
#include <stack>
using namespace std;

const int M = 1e5 + 7;
vector<int> graph[M];
bool visited[M];

void DFS(int st)
{
    stack<int> s;
    s.push(st);
    visited[st] = true;
    while (!s.empty())
    {
        int current = s.top();
        cout << current << " ";
        s.pop();
        for (auto neighbor : graph[current])
        {
            if (!visited[neighbor])
            {
                s.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main()
{
    int vertices, edges;
    cout << "Enter the number of Vertices : ";
    cin >> vertices;
    cout << "Enter the number of Edges : ";
    cin >> edges;

    cout << "Enter Edges : " << endl;
    for (int i = 0; i < edges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int start;
    cout << "Enter the starting vertex : ";
    cin >> start;

    cout << "DFS :: ";
    DFS(start);

    return 0;
}

/* Input format :
Enter the number of Vertices : 6
Enter the number of Edges : 8
Enter Edges :
0 1
0 2
0 4
1 2
1 4
2 3
3 4
4 5
Enter the starting vertex : 0

Output format :
DFS :: 0 4 5 3 2 1
*/
