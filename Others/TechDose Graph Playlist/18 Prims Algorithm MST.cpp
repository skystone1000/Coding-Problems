// GRAPHS PLAYLIST TECHDOSE

// #18 Prims Algorithm MST

/*
    No of vertices = v
    No of Edges in MST = (V-1)

Prims Algo
    - Greedy Algorithm
    - Select min value option at every step (therefore min cost)

Steps in Prims Algo (1:55)
    - All Node weights are infinite except SOURCE
        Because we need to SELECT SOURCE first
    1) Select Node with min weight (or the one which is the source)
    2) Include selected Node in the setMST
    3) Relax/Compute all adjacent edges

    Repeat 1->2->3->1 unless all the vertices are included in MST

        






*/

// TIME Complexity: O(V^2)
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
    int parent[V];  // Stores MST
    vector<int> value(V,INT_MAX);    // Used for edge relaxation
    vector<bool> setMST(V, false);  // TRUE ->Vertex is included in MST

    // Assuming start point as Node - 0
    parent[0] = -1; // Start node has no parent
    value[0] = 0;   // Start node has value = 0 to ge picked first

    // Form MST with (V-1) edges
    for(int i=0;i<V-1;i++){
        // Select best Vertex by applying greedy method
        int U = selectMinVertex(value,setMST);
        setMST[U] = true;   // Include new Vertex in MST
        
        // Relax adjacent vertices (not yet included in MST)
        for(int j=0;j<V;j++){
            /*
                3 Constraints to relax :-
                    1.Edge is present from U to j.
                    2.Vertex j is not included in MST
                    3.Edge weight is smaller that current edge weight
             */
            if(graph[U][j] != 0 && setMST[j]==false && graph[U][j] < value[j]){
                value[j] = graph[U][j];
                parent[j] = U;
            }
        }

        // Print MST
        for(int i=1;i<V;i++){
            cout<< "U->V: "<<parent[i]<<"->"<<i<<" wt = "<<graph[parent[i]][i]<<"\n";
        }
    }
}

int main(){
    int graph[V][V] = { {0, 4, 6, 0, 0, 0},
                        {4,0,6,3,4,0},
                        {6,6,0,1,8,0},
                        {0,3,1,0,2,3},
                        {0,4,8,2,0,7},
                        {0,0,0,3,7,0} };

    findMST(graph);
    return 0;
}