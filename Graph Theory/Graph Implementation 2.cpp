// *** Graph Implementation Matrix Way :: 

#include<bits/stdc++.h>
#define ll long long
#define pb(V) push_back(V)
#define ppb(V) pop_back(V)

using namespace std;

int main() {
    ll vertices, edges;
    cout<<"Enter the number of vertices : ";
    cin>>vertices;
    cout<<"Enter the number of edges : ";
    cin>>edges;
    vector<vector<ll>> adjMatrix(vertices+1, vector<ll>(vertices+1, 0));
    for(ll i=0; i<edges; i++) {
        ll u, v;
        cin>>u>>v;
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // this statement will be removed in case of Directed Graph
    }

    for(ll i=1; i<=vertices; i++) {
        for(ll j=1; j<vertices; j++) {
            cout<<adjMatrix[i][j]<<"";
        }
        cout<<endl;
    }

    return 0;
}

/* Input :

Enter the number of vertices : 4
Enter the number of edges :  4
0 1
0 2
0 3
1 2

Output :

0 1 1 1 
1 0 1 0 
1 1 0 0 
1 0 0 0

*/
