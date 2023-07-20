#include <bits/stdc++.h>
#include <vector>
using namespace std;
int main()
{
    int V, E; // V = Vertices...E = Edges
    cin >> V >> E;
  
    /*  ***Graph Representation Matrix Way
    
    int adj[V+1][V+1];
    for(int i=0; i<E; i++) {
        int u, v;
        cin>>u>>v;

        adj[u][v]=1;
        adj[v][u]=1;  // this statement will be removed in case of directed graph
    }
    */

    /*  ******Graph Representation List Way

    vector<int>adj[V+1];
    for(int i=0; i<E; i++) {
        int u, v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u); // this statement will be removed in case of directed graph

    }
    */
}
