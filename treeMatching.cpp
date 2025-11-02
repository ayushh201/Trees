#include <bits/stdc++.h>
using namespace std;
int dp[200001][2];

int treeMatching(int vertex,bool isIncluded,vector<vector<int>> &adj,int parent){
    if(dp[vertex][isIncluded]!=-1) return dp[vertex][isIncluded];
    if(isIncluded){
        int ans = 0;
        for(int &ngbr:adj[vertex]){
            if(ngbr != parent){
                ans += treeMatching(ngbr,1,adj,vertex);
            }
        }
        int result = 0;
        for(int &ngbr:adj[vertex]){
            if(ngbr != parent){
                result = max(result,ans-dp[ngbr][1]+1+treeMatching(ngbr,0,adj,vertex));
            }
        }
        dp[vertex][isIncluded] = result;
        return result;
    }else{
        int ans = 0;
        for(int &ngbr:adj[vertex]){
            if(ngbr != parent){
                ans += treeMatching(ngbr,1,adj,vertex);
            }
        }
        dp[vertex][isIncluded] = ans;
        return ans;
    }
}
int main()
{
    int n;
    cin>>n;
    int temp = n-1;
    vector<vector<int>> adj(n+1);
    memset(dp,-1,sizeof(dp));
    while(temp--){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cout<<max(treeMatching(1,0,adj,-1), treeMatching(1,1,adj,-1))<<endl;
    return 0;
}