#include<bits/stdc++.h>
using namespace std;

void Knapsack(int n, int c, int profit[], int weight[]) {
    int dp[n+1][c+1];
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=c; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(weight[i-1] <= j) {
                dp[i][j] = max((profit[i-1]+dp[i-1][j-weight[i-1]]), dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    int result =  dp[n][c];
    cout<<"Max Profit :: "<<dp[n][c]<<endl;
    int w = c;
    cout<<"selected Items : "<<endl;
    for(int i=n; i>0 && result>0; i--) {
        if(result != dp[i-1][w]) {
            cout<<i-1<<" ";
            result -= profit[i-1];
            w -= weight[i-1];
        }
    }
    cout<<endl;
}

int main() {
    int n, capacity;
    cin>>n>>capacity;
    int profit[n];
    for(int i=0; i<n; i++)
    cin>>profit[i];
    int weight[n];
    for(int i=0; i<n; i++) 
    cin>>weight[i];

    Knapsack(n, capacity, profit, weight);
}
