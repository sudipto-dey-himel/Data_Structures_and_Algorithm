#include<bits/stdc++.h>
#define V 5

using namespace std;

int minCost(int cost[], bool mstSET[]) {
    int minimum=INT_MAX, minIndex;
    for(int i=0; i<V; i++) {
        if(mstSET[i]==false && cost[i]<minimum) {
            minimum=cost[i];
            minIndex=i;
        }
    }
    return minIndex;
}
void printPrims(int parent[], int graph[V][V]) {
    cout<<"Edges \t Weight"<<endl;
    for(int i=1; i<V; i++) {
        cout<<parent[i]<<" -> "<<i<<"\t  "<<graph[i][parent[i]]<<endl;
    }
}
void prims(int graph[V][V]) {
    int parent[V], cost[V];
    bool mstSET[V];
    for(int i=0; i<V; i++) {
        cost[i]=INT_MAX;
        mstSET[i]=false;
    }
    cost[0]=0;
    parent[0]=-1;
    for(int i=0; i<V; i++) {
        int u=minCost(cost, mstSET);
        mstSET[u]=true;
        for(int j=0; j<V; j++) {
            if(graph[u][j] && mstSET[j]==false && graph[u][j]<cost[j]) {
                parent[j]=u;
                cost[j]=graph[u][j];
            }
        }
    }
     printPrims(parent, graph);
}

int main() {
    //int graph[v][v] = { {0, 1, 2, 0, 0}, {1, 0, 2, 3, 2}, {2, 0, 0, 1, 0}, {0, 3, 1, 0, 1}, {0, 2, 0, 1, 0}};
    //int graph[V][V] = { {0, 5, 8, 4, 7, 0}, {5, 0, 0, 0, 0, 2}, {8, 0, 0, 2, 3, 0}, {4, 0, 2, 0, 0, 3}, {7, 0, 3, 0, 0, 0}, {0, 2, 0, 3, 0, 0} };
    int graph[V][V] = { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };

    prims(graph);
}


/* Output:
Edges    Weight
0 -> 1    2
1 -> 2    3
0 -> 3    6
1 -> 4    5
*/
