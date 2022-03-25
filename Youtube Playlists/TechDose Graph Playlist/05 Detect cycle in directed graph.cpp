// GRAPHS PLAYLIST TECHDOSE

// #05 Detect a cycle in the graph (Directed Graph)

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isCyclic_util(vector<int> adj[], vector<bool> visited, int curr){
    if(visited[curr] == true)
        return true;

    visited[curr] = true;
    bool FLAG = false;
    for(int i=0;i<adj[curr].size();i++){
        FLAG = isCyclic_util(adj,visited, adj[curr][i]);
        if(FLAG == true)
            return true;
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    vector<bool> visited(V,false);
    bool FLAG = false;
    for(int i=0;i<V;i++){
        visited[i] = true;
        for(int j=0;j<adj[i].size();j++){
            FLAG = isCyclic_util(adj,visited,adj[i][j]);
            if(FLAG == true)
                return false;
        }
        visited[i] = false;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int v,e;
        cin>>v>>e;

        vector<int> adj[v];

        for(int i=0 ; i<e ; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        cout << isCyclic(v, adj) << endl;
    }
    return 0;
}