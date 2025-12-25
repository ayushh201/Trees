#include <bits/stdc++.h>
using namespace std;

void dfs(int curr, int parent, vector<vector<int>> &edges, vector<int> &level){
    if(parent == -1){
        level[curr] = 0;
    }else{
        level[curr] = level[parent] + 1;
    }
    for(int &neighbour : edges[curr]){
        if(neighbour != parent){
            dfs(neighbour, curr, edges, level);
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
    vector<int> level(n,-1);
    dfs(0, -1, edges, level);
    cout << "Levels of each node " << endl;
    for(int i=0;i<level.size();i++){
        cout << i << " : " << level[i] << endl;
    }
    return 0;
}
