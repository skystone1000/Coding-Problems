// GRAPHS PLAYLIST TECHDOSE

// #25 Floyd Warshall - All pairs shortest path
// Time Complexity: O(V^3)

#include<iostream>
using namespace std;

int V,E;

void floyd_warshall(int graph[V][V]){
    int dist[V][V];

    // Assign all values of graph to allPairs_SP
    for(int i=0;i<V;i++)
        for(int j=0;j<V;j++)
            dist[i][j] = graph[i][j];
    
    // Find all pairs Shortest path by trying all possible paths
    for(int k=0;k<V;k++)    // Try all intermediate node
        for(int i=0;i<V;i++)    // Try for all possible starting posi
            for(int j=0;j<V;j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
            }
}




int main(){
    int graph[V][V] = { {0, 1, 4, INT_MAX, INT_MAX, INT_MAX},
                        {INT_MAX, 0, 4, 2, 7, INT_MAX},
                        {INT_MAX, INT_MAX, 0, 3, 4, INT_MAX},
                        {INT_MAX, INT_MAX, INT_MAX, 0, INT_MAX, 4},
                        {INT_MAX, INT_MAX, INT_MAX, 3, 0, INT_MAX},
                        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, 5, 0} };
    
    floyd_warshall(graph);
    return 0;
}