/*
	Kosaraju Algorithm
	Used for finding "Strongly Connected Components" in a graph

	Steps
	1) Do a Topo Sort (Take stack and store elements in stack while exiting recursion)
	2) Invert the Graph edges
	3) Iterate for all elements of stack to do a DFS on inverted graph
*/


#include <bits/stdc++.h>
using namespace std;
void dfs(int node, stack<int> &st, vector<int> &vis, vector<int> adj[]) {
    vis[node] = 1; 
    for(auto it: adj[node]) {
        if(!vis[it]) {
            dfs(it, st, vis, adj); 
        }
    }
    
    st.push(node); 
}
void revDfs(int node, vector<int> &vis, vector<int> transpose[]) {
    cout << node << " "; 
    vis[node] = 1; 
    for(auto it: transpose[node]) {
        if(!vis[it]) {
            revDfs(it, vis, transpose); 
        }
    }
}
int main() {
	// Step 0 - Input the Adjacency List of Graph
    int n, m;
    cin >> n >> m; 
	vector<int> adj[n]; 
	for(int i = 0;i<m;i++) {
	    int u, v;
	    cin >> u >> v; 
	    adj[u].push_back(v);
	}
	
	// Step 1 - Topo Sort
	stack<int> st;
	vector<int> vis(n, 0); 
	for(int i = 0;i<n;i++) {
	    if(!vis[i]) {
	        dfs(i, st, vis, adj); 
	    }
	} 
	
	// Step 2 - Transpose the graph (Invert directions of edges)
	vector<int> transpose[n]; 
	for(int i = 0;i<n;i++) {
	    vis[i] = 0; 
	    for(auto it: adj[i]) {
	        transpose[it].push_back(i); 
	    }
	}
	
	// Step 3 - For each node in stack to a DFS for inverted graph
	while(!st.empty()) {
	    int node = st.top();
	    st.pop(); 
	    if(!vis[node]) {
	        cout << "SCC: "; 
	        revDfs(node, vis, transpose); 
	        cout << endl; 
	    }
	}
	return 0;
}

/*
5 5 
0 1 
1 2 
2 0 
1 3 
3 4 
*/
