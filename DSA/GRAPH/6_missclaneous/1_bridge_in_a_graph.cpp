#include <bits/stdc++.h>


void dfs(int node, unordered_map<int, vector<int>>& adj, int &timer, int parent, vector<int>& disc, vector<int>& low, vector<bool>& vis, vector<vector<int>> &result) {
    vis[node] = true;
    disc[node] = low[node] = timer++;

    for (auto nbr : adj[node]) {
        if (nbr == parent) continue; 

        if (!vis[nbr]) {
            dfs(nbr, adj, timer, node, disc, low, vis, result);

            low[node] = min(low[node], low[nbr]);

            if (low[nbr] > disc[node]) {
                result.push_back({node, nbr});
            }
        } else {
            low[node] = min(low[node], disc[nbr]);
        }
    }
}


vector<vector<int>> bridgesInGraph(int v, vector<vector<int>>& graph){
    unordered_map<int, vector<int>> adj;
    for(auto edge: edges){
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    vector<vector<int>> result;

    vector<int> disc(v, -1);
    vector<int> low(v, -1);
    vector<bool> vis(v, false);

    int timer = 0;
    int parent = -1;

    for(int i = 0; i < v; i++){
        if(!vis[i]){
            dfs(i, adj, timer, parent, disc, low, vis, result);
        }
    }
}

int main(){

    vector<vector<int>> graph;
    int v = 10;

    vector<vector<int>> bridges = bridgesInGraph(v, graph);
    return 0;
}