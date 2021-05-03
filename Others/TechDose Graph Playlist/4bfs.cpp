// GRAPHS PLAYLIST TECHDOSE

// #04 BFS

#include<bits/stdc++.h>

using namespace std;
void dfs(int s, vector<int> g[], bool *vis);

int main(){
    cout<<"===== Program for BFS in Graph =====\n"<<endl;
	int T;
    cout<<"Enter Total test cases: ";
	cin>>T;
	while(T--){
		int N, E;
        cout<<"Enter Total Nodes in graph: ";
		cin>>N;
        cout<<"Enter Total Edges in graph: ";
        cin>>E;
		vector<int> adj[N]; // Array of 5 vectors
		bool vis[N]; // Visited Array
		memset(vis, false, sizeof(vis));
        
        cout<<"\nNote: Please enter node names starting from '0' while giving edges.\n"<<endl;
        // Building Adjacency List of Graph
		for(int i=0;i<E;i++){
            cout<<"Enter two nodes for edge: ";
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);  // undirected Graph so adding both
			g[v].push_back(u);
		}

        cout<<"DFS starting from Node '0' is: ";
		dfs(0,g,vis);
		cout<<endl;
	}
}

/*
	g[]: array of vectors to represent graph
	vis[]: array to keep track of visited vertex
*/

void dfs(int s, vector<int> g[], bool *vis){
	vis[s] = true;
	cout<<s<< " ";
	for(int i=0; i<g[s].size();i++){
		if(vis[g[s][i]] == false){
			dfs(g[s][i], g, vis);
		}
	}
}

