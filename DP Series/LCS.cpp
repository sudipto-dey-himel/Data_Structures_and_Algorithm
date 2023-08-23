#include<bits/stdc++.h>
using namespace std;

int LCS(string s1, string s2, int m, int n, vector<vector<int> >&dp) {
    for(int i=0; i<=m; i++) {
        for(int j=0; j<=n; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(s1[i-1]==s2[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}

void printLCS(string s1, string s2, int m, int n, vector<vector<int> >&dp) {
    string lcs = " ";
    int i=m, j=n;
    while(i>0 && j>0) {
        if(s1[i-1]==s2[j-1]) {
            lcs = s1[i-1]+lcs;
            i--; j--;
        }
        else if(dp[i-1][j]>=dp[i][j-1]) {
            i--;
        }
        else {
            j--;
        }
    }
    cout<<lcs<<endl;
}

int main() {
    string s1, s2;
    cout<<"Enter String 1 :: ";
    cin>>s1;
    cout<<"Enter String 2 :: ";
    cin>>s2;

    int m = s1.size();
    int n = s2.size();

    vector<vector<int> >dp(m+1, vector<int>(n+1, 0));

    cout<<"Length of Longest Common Subsequence :: "<<LCS(s1, s2, m, n, dp)<<endl;

    cout<<"Longest Common Subsequence :: ";
    printLCS(s1, s2, m, n, dp);

    return 0;
}

/*
INPUT : 
Enter String 1 :: AXGTAYB
Enter String 2 :: AGGTAB

OUTPUT : 
Length of Longest Common Subsequence :: 5
Longest Common Subsequence :: AGTAB 
*/
