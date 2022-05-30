/*
	Bellman Ford Algorithm
	Another "Single Source Shortest Path" => Works for -ve edges also (Dijkstra does not work for -ve Edge)

    - If there is -ve cycle then "Bellman ford would not work" => Can detect -ve edges
    - We can apply Bellman ford only if it is directed graph

	Steps
	1) Initialization -> Adjacency List, Distance array(set all elements to infinity)
	2) Relax all Edges N-1 times
	3) Relax Nth time => 
        if it gets relaxed then there is -ve edge weight cycle
        else you have single source shortest path to all other nodes

    TC - O(N-1) x O(E)
    SC - O(N)
*/

#include<bits/stdc++.h>
using namespace std;
struct node {
    int u;
    int v;
    int wt; 
    node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main(){
    // Step 1 - Adjacency List
    int N,m;
    cin >> N >> m;
    vector<node> edges; 
    for(int i = 0;i<m;i++) {
        int u, v, wt;
        cin >> u >> v >> wt; 
        edges.push_back(node(u, v, wt)); 
    }

    // Step 1 - Distance array
    int src; cin >> src; 
    int inf = 10000000; 
    vector<int> dist(N, inf); 

    // Step 2 - Relax all edges N-1 times
    dist[src] = 0; 
    for(int i = 1;i<=N-1;i++) {
        for(auto it: edges) {
            if(dist[it.u] + it.wt < dist[it.v]) {
                dist[it.v] = dist[it.u] + it.wt; 
            }
        }
    }

    // Step 3 - Check if one more relaxation is possible
    int fl = 0; 
    for(auto it: edges) {
        if(dist[it.u] + it.wt < dist[it.v]) {
            cout << "Negative Cycle"; 
            fl = 1; 
            break; 
        }
    }

    if(!fl) {
        for(int i = 0;i<N;i++) {
            cout << i << " " << dist[i] << endl;
        }
    }


    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/
