// GRAPHS PLAYLIST TECHDOSE

// #16 Disjoint Set - UNION by RANK and Path compression

#include<bits/stdc++.h>

using namespace std;

vector<int> dsuf;

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
    
}