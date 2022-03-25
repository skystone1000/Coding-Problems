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
                //  SKIP if k is unreachable from i or j is unreachable from k
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX)
                    continue;
                // Check if new distance is shorter via vertex k
                else if(dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
    
    // Check for negative edge weight cycle
    for(int i=0;i<V;i++){
        if(dist[i][i] < 0){
            cout<<"Negative edge weight cycle is present";
            return;
        }
    }

    // Print Shortest Path Graph
    // (Values printed as INT_MAX defines there is no path)
    for(int i=1;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<i<<" to "<<j<<" distance is "<<dist[i][j]<<endl;
        }
        cout<<"======================="<<endl;
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