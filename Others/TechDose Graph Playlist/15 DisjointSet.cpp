// GRAPHS PLAYLIST TECHDOSE

// #15 Disjoint Set UNION and FIND
// Time Complexity: O(E.V)

#include<iostream>
#include<vector>

using namespace std;

vector<int> dsuf;

// Find Operation
int find(int v){
    if(dsuf[v] == -1)
        return v;
    
    return find(dsuf[v]);
}

void union_op(int fromP, int toP){
    fromP = find(fromP);
    toP = find(toP);
    dsuf[fromP] = toP;
}

bool isCyclic(vector<pair<int,int>>& edge_List){
    for(auto p:edge_List){
        // FIND absolute parent of subset
        int fromP = find(p.first);
        int toP = find(p.second);

        if(fromP == toP)
            return true;

        // UNION Operation
        union_op(fromP, toP); // UNION of 2 sets
    }
    return false;
}


int main(){
    // Total Edges and Vertices(0 to V-1)
    int E, V;
    cin>>E>>V;

    // Mark all vertices as separate subsets with only 1 element
    dsuf.resize(V, -1);

    // Adjacency List
    vector<pair<int,int>> edge_List;
    for(int i=0;i<E;i++){
        int from, to;
        cin>>from>>to;
        edge_List.push_back({from,to});
    }

    if(isCyclic(edge_List))
        cout<<"TRUE"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}