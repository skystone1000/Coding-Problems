// GRAPHS PLAYLIST TECHDOSE

// #04 BFS

#include<bits/stdc++.h>

using namespace std;
void bfs(int s, vector<int> adj[], bool vis[],int N);

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
		vector<int> adj[N]; // Array of N vectors
		bool vis[N] = {false}; // Visited Array
		// memset(vis, false, sizeof(vis));
        
        cout<<"\nNote: Please enter node names starting from '0' while giving edges.\n"<<endl;
        // Building Adjacency List of Graph
		for(int i=0;i<E;i++){
            cout<<"Enter two nodes for edge: ";
			int u,v;
			cin>>u>>v;
			adj[u].push_back(v);  // directed Graph so adding just in one
			// adj[v].push_back(u);
		}

		// Assuming that we have only one component - 
		// else we need a for loop for all vertices
        cout<<"BFS starting from Node '0' is: ";
		bfs(0,adj,vis,N);
		// TODO - Check why N is passed (i think it would work without it)
		cout<<endl;
	}
}

/*
	g[]: array of vectors to represent graph
	vis[]: array to keep track of visited vertex
	s: starting position of bfs
*/

void bfs(int s, vector<int> adj[], bool vis[],int N){
	queue<int> q;
	q.push(s);
	vis[s] = true;

	while(!q.empty()){
		int curr = q.front();
		q.pop();
		cout<<curr<<" ";
		for(int i=0; i<adj[curr].size();i++){
			if(vis[adj[curr][i]] == false){
				q.push(adj[curr][i]);
				vis[adj[curr][i]] = true;
			}
		}
	}
}

