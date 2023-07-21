#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main() {
    int vertices, edges;
    cout<<"Enter the number of vertex :: ";
    cin>>vertices;
    cout<<"Enter the number of edge :: ";
    cin>>edges;

    vector<vector<int>>graph(vertices);
    for(int i=0; i<edges; i++) {
        int u, v;
        cin>>u>>v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(int i=0; i<vertices; i++) {
        cout<<"Vertex : "<<i<<" -> ";
        for(int it:graph[i])
        cout<<it<<" ";

        cout<<endl;
    }
}

/*
Input format :

Enter the number of vertex :: 5
Enter the number of edge :: 7
0 1
0 2
1 2
1 3
1 4
2 3
3 4

Output format : 

Vertex : 0 -> 1 2
Vertex : 1 -> 0 2 3 4
Vertex : 2 -> 0 1 3
Vertex : 3 -> 1 2 4
Vertex : 4 -> 1 3
*/
