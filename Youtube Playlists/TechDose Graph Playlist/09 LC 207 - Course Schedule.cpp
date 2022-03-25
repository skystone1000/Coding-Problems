// GRAPHS PLAYLIST TECHDOSE

// #09 LC 207 - Course Schedule - Deadlock Detection, Graph Coloring

/*
    - Deadlock Detection (Single resource instance distributed system)
    If we have cycle in a graph then we will have deadlock
    - Why Directed graph?
    In order to give meaning to directionality
    - Cycle Detection (Graph coloring)
    Time - O(V+E)

    0 - Unvisited
    1 - Processed
    2 - processing 
*/

class Solution{

    bool isCyclic(vector<vector<int>& adj, vector<int>& visited, int curr){
        if(visited[curr] == 2)
            return true;

        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();i++){
            // Skipping already processed Nodes
            if(visited[adj[curr][i]] != 1)
                if(isCyclic(adj,visited, adj[curr][i]))
                    return true;
        }

        visited[curr] = 1;
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites){

        vector<vector<int>> adj(numCourses);
        // Make adjacency matrix(Directed Graph)
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i] == 0){
                if(isCyclic(adj, visited, i)){
                    return false;
                }
            }
        }

        return true;
    }

};