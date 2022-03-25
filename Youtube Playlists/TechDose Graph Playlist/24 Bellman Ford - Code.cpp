// GRAPHS PLAYLIST TECHDOSE

// #24 Bellman Ford - Code
// Time Complexity: O(V.E)

#include<iostream>
using namespace std;

int V,E;

void bellmanFord(vector<edge>& Edges){
    int parent[V];      // Stores Shortest Path Structure
    int cost_parent[V]; // Cost of the node to parent edges weight
    vector<int> value(V, INT_MAX);  // Keeps shortest path values to each vertex from source

    // Assuming start point as Node-0
    parent[0] = -1;     // Start node has no parent
    value[0] = 0;       // Start node has value=0 to get picked 1st

    // Include (V-1) edges to cover all V-vertices
    bool updated;
    for(int i=0;i<V-1;i++){
        updates = false;
        for(int j=0;j<E;j++){
            int U = Edges[j].src;
            int V = Edges[j].dst;
            int wt = Edges[j].wt;
            if(value[U] != INT_MAX && value[U] + wt < value[V]){
                value[V] = value[U] + wt;
                parent[V] = U;
                cost_parent[V] = value[V];
                updated = true;
            }
        }
        if(updates == false)
            break;
    }

    // Now check by relaxing once more if we have negative edge cycle
    for(int j=0; j<E && updated == true ; j++){
        int U = Edges[j].src;
        int V = Edges[j].dst;
        int wt = Edges[j].wt;
        if(value[U] != INT_MAX && value[U] + wt < value[V]){
            cout<<"Graph has -ve Edge cycle"<<endl;
            return;
        }
    }
    // Print Shortest Path Graph
    for(int i=1;i<V;i++)
        cout<<"U->V : "<< parent[i]<< "->"<<i<<" Cost to reach" << parent[i] << "from  source 0 = "<<value[i]<<endl;
}


int main(){
    // Enter number of vertices and edges
    cin>>V>>E;
    vector<edge> Edges(E);

    // Now input all E edges
    int src, dst, wt;
    for(int i=0;i<E;i++){
        cin>>src>>dst>>wt;
        Edges[i].src = src;
        Edges[i].dst = dst;
        Edges[i].wt = wt;
    }

    bellmanFord(Edges);
    return 0;
}