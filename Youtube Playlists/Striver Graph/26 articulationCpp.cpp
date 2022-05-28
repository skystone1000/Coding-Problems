/*
	Articulation point: It is a node on whose removal the graph is broken into two or more components
	
	Articulation point Algorithm
	In this we use two arrays  tin[] (Time of inserstion), low[] (Lowest time of insertion)

	Steps
	1) Initialization -> Adjacency List, isArticulate array(set all elements to infinity)
	2) 
	3) 

    TC - 
    SC - 
*/

#include <bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, 
		int &timer, vector<int> adj[], vector<int> &isArticulation) {
    vis[node] = 1; 
    tin[node] = low[node] = timer++;
    int child = 0; 
    for(auto it: adj[node]) {
        if(it == parent) continue;
        
        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation); 
            low[node] = min(low[node], low[it]); 
	    	child++; 
            if(low[it] >= tin[node] && parent != -1) {
                isArticulation[node] = 1; 
            }
        } else {
            low[node] = min(low[node], tin[it]); 
        }
    }
    
    if(parent == -1 && child > 1) {
        isArticulation[node] = 1; 
    }
}
int main() {
	// Initialization - Adjacency list
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	    adj[v].push_back(u); 
	}
	
	// Initialization of variables
	vector<int> tin(n, -1);
	vector<int> low(n, -1); 
	vector<int> vis(n, 0);
	vector<int> isArticulation(n, 0); 

	// DFS
	int timer = 0; 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, -1, vis, tin, low, timer, adj, isArticulation); 
	    }
	}
	
	// Output
	for(int i = 0;i<n;i++) {
	    if(isArticulation[i] == 1) cout << i << endl;
	}
	
	return 0;
}
