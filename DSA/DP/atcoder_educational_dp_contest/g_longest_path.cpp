#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<bool> &vis, stack<int>& st, vector<vector<int>>& adj){
    for(auto nbr : adj[node]){
        if(!vis[node]){
            vis[node] = true;
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

int main(){

    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++){
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }

    vector<bool>vis(n+1, false);
    stack<int> st;
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            vis[i] = true;
            dfs(i, vis, st, adj);
        }
    }

    vector<int> dist(n+1, 1);

    while(!st.empty()){
        int top = st.top(); st.pop();
        for(auto nbr : adj[top]){
            if(dist[nbr] < dist[top] + 1){
                dist[nbr] = dist[top] + 1;
            }
        }
    }

    cout << *max_element(dist.begin(), dist.end()) << endl;

    return 0;
}