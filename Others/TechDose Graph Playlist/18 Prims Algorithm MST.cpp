// GRAPHS PLAYLIST TECHDOSE

// #18 Prims Algorithm MST

#include<bits/stdc++.h>
using namespace std;

// Number of vertices
#define V 6

int selectMinVertex(vector<int>& value, vector<bool>& setMST){
    int minimum = INT_MAX;
    int vertex;
    for(int i=0;i<V;i++){
        if(setMST[i] == false && value[i] < minimum){
            vertex = i;
            minimum = value[i];
        }
    }
    return vertex;
}

void findMST(int graph[V][V]){
    
}