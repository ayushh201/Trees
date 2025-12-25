#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, int parent, vector<vector<int>> &edges, vector<int> &ans){
    ans.push_back(curr);
    for(int &neighbour : edges[curr]){
        if(neighbour != parent){
            dfs(neighbour, curr, edges, ans);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n,vector<int>());
    for(int i=0;i<n-1;i++){
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    vector<int> ans;
    dfs(0, -1, edges, ans);
    cout << "DFS Traversal " << endl;
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
