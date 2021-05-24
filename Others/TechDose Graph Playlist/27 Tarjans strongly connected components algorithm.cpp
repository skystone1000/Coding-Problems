// GRAPHS PLAYLIST TECHDOSE

// #27 Tarjans strongly connected components algorithm
// Time Complexity: O(V+E)

#include<bits/stdc++.h>
using namespace std;

// Check V (number of vertices)
#define V 7
#define pb push_back

void findSCCs_Tarjan(){
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<bool> presentInStack(V, false); // Avoid Cross-edge
    stack<int> mystack;

    for(int i=0;i<V;i++)
        if(disc[i] == -1)
            DFS()
}

int main(){
    adj[0].pb(1);
    adj[1].pb(2);
    adj[1].pb(3);
    adj[3].pb(4);
    adj[4].pb(0);
    adj[4].pb(5);
    adj[4].pb(6);
    adj[5].pb(6);
    adj[6].pb(5);

    findSCCs_Tarjan();
    return 0;
}