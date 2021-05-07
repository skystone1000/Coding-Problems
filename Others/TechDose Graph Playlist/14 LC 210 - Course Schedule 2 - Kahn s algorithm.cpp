// GRAPHS PLAYLIST TECHDOSE

// #14 LC 210 - Course Schedule 2 - Kahn s algorithm Topological sort

class Solution{
    // Topological sort
    void kahnsAlgo(vector<vector<int>>& adj, int n, vector<int>& indegree,vector<int>& ans){
        // Step-2: Take a queue and push all vertices with indegree = 0
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0)
                q.push(i);
        }

        /*
        Step 3 Process all nodes with indegree = 0 ans keep decrementing other
        node's indegree while preocessing
        */
        // Keep a count of no of processed nodes (for cucle detection in graph)
        int count = 0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            // Decrement the indegree of all the adjacent vertices
            for(auto a:adj[curr]){
                indegree[a] -= 1;
                if(indegree[a] == 0)
                    q.push(a);
            }

            // Push current node(forms topological ordering)
            ans.push_back(curr);
            // keeps count of no of processed vertices
            count += 1;
        }

        // No of processed nodes != No of nodes
        if(count != n)
            return false; // Graph is not a DAG

        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);

        // Store indegree of each node
        vector<int> indegree(numCourses, 0);

        // Make adjacency list
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[ prerequisites[i][0] ] += 1;
        }
        
        // Kahn's algorithm
        vector<int> ans;
        if(kahnsAlgo(adj,numCourses,indegree,ans))
            return ans;

        vector<int> empty;
        return empty;
    }
};