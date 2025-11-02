#include <bits/stdc++.h>
using namespace std;
void dfs(int v,vector<vector<int>> &adj,vector<int> &visited,vector<int> &dp){
    int answer = 0;
    visited[v] = true;
    for(int &x:adj[v]){
        if(!visited[x]){
            dfs(x,adj,visited,dp);
            answer += 1+dp[x];
        }
    }
    dp[v] = answer;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> adj(n+1);
    int value = 2;
    for(int i=0;i<n-1;i++){
        int k;
        cin >> k;
        adj[k].push_back(value);
        value++;
    }
    vector<int> dp(n+1,0);
    vector<int> visited(n+1,0);
    dfs(1,adj,visited,dp);
    for(int i=1;i<=n;i++){
        cout<<dp[i]<<" ";
    }
    return 0;
}