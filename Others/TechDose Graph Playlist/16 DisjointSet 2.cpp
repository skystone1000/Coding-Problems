// GRAPHS PLAYLIST TECHDOSE

// #16 Disjoint Set - UNION by RANK and Path compression

#include<bits/stdc++.h>
using namespace std;


struct node{
    int parent;
    int rank;
};
vector<node> dsuf;

int find(int v){
    if(dsuf[v].parent == -1)
        return v;
    
    // Path Compression
    return dsuf[v].parent = find(dsuf[v].parent);
}

void union_op(int fromP, int toP){
    // fromP = find(fromP);
    // toP = find(toP);

    // UNION by RANK
    
    // fromP has higher rank
    if(dsuf[fromP].rank > dsuf[toP].rank)
        dsuf[toP].parent = fromP;
    // toP has higher rank
    else if (dsuf[fromP].rank < dsuf[toP].rank)
        dsuf[fromP].parent = toP;
    // Both have same rank and so anyone can be made as parent
    else{
        dsuf[fromP].parent = toP;
        // Increase rank of parent
        dsuf[toP].rank += 1; 
    }
}

bool isCyclic(vector<pair<int,int>>& edge_List){
    for(auto p:edge_List){
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP)
            return true;

        // UNION operation
        union_op(fromP, toP); // UNION of 2 Sets
    }
    return false;
}

int main(){
    int E; // Number of Edges
    int V; // NUmber of Vertices (0 to V-1)
    cin>>E>>V;

    dsuf.resize(V); // Mark all vertices as separate susets with only 1 element

    // Mark all Nodes as independent set
    for(int i=0;i<V;i++){
        dsuf[i].parent = -1;
        dsuf[i].rank = 0;
    }

    // Adjacency List
    vector<pair<int,int>> edge_List;
    for(int i=0;i<E;i++){
        int from,to;
        cin>>from>>to;
        edge_List.push_back({from,to});
    }

    if(isCyclic(edge_List))
        cout<<"TRUE\n";
    else
        cout<<"FALSE\n";
}