#include<bits/stdc++.h>

using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adj[]){
	vector<int> bfs; 
	vector<int> vis(V+1, 0); 

	// Inital For loop for mutiple components
	// 1 Based indexing
	for(int i=1; i<=V ; i++){
		// 0 Based Indexing 
		// for(int i=0; i<V ; i++){
		if(!vis[i]){
			queue<int> q; 
			q.push(i); 
			vis[i] = 1; 

			// Iterating in Queue
			while(!q.empty()) {
				int node = q.front();
				q.pop(); 
				bfs.push_back(node); 
				
				// Validating connected vertices of node 
				for(auto it : adj[node]) {
					if(!vis[it]) {
						q.push(it); 
						vis[it] = 1; 
					}
				}
			}
		}
	}
	
	return bfs; 
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

	vector<int>ans = bfsOfGraph(V, adj);
	cout<<"BFS of Graph: \n";
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
