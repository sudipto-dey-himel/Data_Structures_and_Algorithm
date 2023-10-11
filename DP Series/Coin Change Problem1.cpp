#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;

void minCoins(vector<int>coins, int n, int V) {
    vector<int>dp(V+1, INF);
    vector<int>coinUsed(V+1, -1);
    dp[0] = 0;
    coinUsed[0] = -1;
    for(int i=1; i<=V; i++) {
        for(int j=0; j<n; j++) {
            if(coins[j]<=i) {
                if(dp[i-coins[j]]!=INF && dp[i-coins[j]]+1<dp[i]) {
                    dp[i] = dp[i-coins[j]]+1;
                    coinUsed[i] = j;
                }
            }
        }
    }
    cout<<"Minimum coins required is :: "<<dp[V]<<endl;
    int value = V;
    cout<<"Coins Used are :: ";
    while(value>0) {
        int index = coinUsed[value];
        cout<<coins[index]<<" ";
        value -= coins[index];
    }
    cout<<endl;
    //return dp[V] == INF ? -1 : dp[V];
}

int main() {
    int n;
    cout<<"Enter the number of coins :: ";
    cin>>n;
    vector<int>coins(n);
    cout<<"Enter the coins :: ";
    for(int i=0; i<n; i++)
    cin>>coins[i];
    int sum;
    cout<<"Enter the value of sum :: ";
    cin>>sum;
    minCoins(coins, n, sum);
}

/* Input : 
Enter the number of coins :: 5
Enter the coins :: 1 5 10 20 100
Enter the value of sum :: 43

Output : 
Minimum coins required is :: 5
Coins Used are :: 1 1 1 20 20
*/
