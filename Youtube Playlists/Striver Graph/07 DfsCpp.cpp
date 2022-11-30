#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs) {
	storeDfs.push_back(node); 
	vis[node] = 1; 
	for(auto it : adj[node]) {
		if(!vis[it]) {
			dfs(it, vis, adj, storeDfs); 
		}
	}
}

vector<int> dfsOfGraph(int V, vector<int> adj[]){
	vector<int> storeDfs; 
	vector<int> vis(V+1, 0); 
	// Multi component for loop
	for(int i = 1;i<=V;i++) {
		if(!vis[i]) 
			dfs(i, vis, adj, storeDfs); 
	}
	return storeDfs; 
}


int main(){
	int V, E;
	cout<<"Enter number of Vertices and Edges:";
	cin >> V >> E;

	vector<int> adj[V+1];
	cout<<"Enter edges u->v\n";
	for(int i = 0; i < E; i++)
	{
		int u, v;
		cout<<"Enter edge "<<i<<" : ";
		cin >> u >> v;
		adj[u].push_back(v);
 		adj[v].push_back(u); // for undirected graoh 
	}

	vector<int>ans = dfsOfGraph(V, adj);
	cout<<"DFS of Graph: \n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 