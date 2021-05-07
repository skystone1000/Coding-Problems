// GRAPHS PLAYLIST TECHDOSE

// #06 Detect a cycle in the graph (UnDirected Graph)

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isCyclic_util(vector<int> adj[], vector<int> visited, int curr){
    if(visited[curr] == 2)
        return true;

    visited[curr] = 1;
    bool FLAG = false;
    for(int i=0;i<adj[curr].size();i++){
        if(visited[adj[curr][i]] == 1)
            visited[adj[curr][i]] = 2;
        else{
            FLAG = isCyclic_util(adj,visited, adj[curr][i]);
            if(FLAG == true)
                return true;
        }
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    vector<int> visited(V,0);
    bool FLAG = false;
    for(int i=0;i<V;i++){
        visited[i] = 1;
        for(int j=0;j<adj[i].size();j++){
            FLAG = isCyclic_util(adj,visited,adj[i][j]);
            if(FLAG == true)
                return false;
        }
        visited[i] = 0;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int V,E;
        cin>>V>>E;

        vector<int> adj[V];

        for(int i=0 ; i<E ; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(V, adj) << endl;
    }
    return 0;
}