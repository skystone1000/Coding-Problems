#include <bits/stdc++.h>
using namespace std;

int main() {
	// n = Number of Nodes
	// m = Number of Edges
	int n, m;
	cin >> n >> m; 
	
	// declare the adjacent matrix 
	vector<int> adj[n+1];
	
	// take edges as input 
	for(int i=0;i<m;i++) {
		// u,v represent nodes in which an edge exists
	    int u, v; 
	    cin >> u >> v;
	    adj[u].push_back(v); 
	    adj[v].push_back(u); 
	}
	return 0;
}
