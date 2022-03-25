// GRAPHS PLAYLIST TECHDOSE

// #28 Find Articulation Points using Tarjans Algorithm Cut vertex
// Time Complexity: O(V+E) 

#include<bits/stdc++.h>
using namespace std;

#define V 5
#define pb push_back;

unordered_map<int, vector<int>> adj;

void DFS(int u, vector<int>& disc, vector<int>& low, vector<int>& parent,
         vector<bool>& articulation_Point){

    static int time = 0;
    disc[u] = low[u] = time;
    time += 1;
    int children = 0;
    
    // Exploring the Sub Graphs
    for (int v : adj[u]){
        // If v is not visited
        if(disc[v] == -1){
            children += 1;
            parent[v] = u;
            DFS(v, disc, low, parent, articulation_Point);
            low[u] = min( low[u], low[v] );

            // Case 1: U is root
            if(parent[u] == -1 && children > 1)
                articulation_Point[u] = true;

            // Case 2: Atlest 1 component will get separated
            if(parent[u] != -1 && low[v] >= disc[u])
                articulation_Point[u] = true;
        } 
        // Ignore child to edge
        else if(v != parent[u]){
            low[u] = min( low[u] , disc[v] );
        }
    }
}

void findAPs_Tarjan(){
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1);
    vector<bool> articulation_Point(V, false);

    for(int i=0;i<V;i++)
        if(disc[i] == -1)
            DFS(i, disc, low, parent, articulation_Point);

    cout<<"Articulation Points are: ";
    for(int i=0;i<V;i++)
        if(articulation_Point[i] == true)
            cout<<i<<" ";
}

int main(){
    adj[0].pb(2);
    adj[2].pb(0);
    adj[0].pb(3);
    adj[3].pb(0);
    adj[1].pb(0);
    adj[0].pb(1);
    adj[2].pb(1);
    adj[1].pb(2);
    adj[3].pb(4);
    adj[4].pb(3);

}