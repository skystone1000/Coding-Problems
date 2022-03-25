// GRAPHS PLAYLIST TECHDOSE

// #13 LC 210 - Course Schedule 2 - Topological sort

class Solution{
    void dfs(vector<vector<int>>& adj, int v, vector<bool>& visited,stack<int>& mystack){
        // cout<<"Node: "<<v<<endl;
        visited[v] = true;
        for(int i=0;i<adj[v].size();i++){
            if(!visited[ adj[v][i] ]){
                // cout<<"V: "<<v<<" size(): "<<adj[v].size()<<endl;
                dfs(adj, adj[v][i], visited, mystack);
            }
        }

        mystack.push(V);        
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        int n = prerequisites.size();
        vector<vector<int>> adj(numCourses);

        // Make adjacency list
        for(int i=0;i<n;i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        
        // Detect Cycle - If present the return empty array
        vector<int> ans;
        if(detectCycle(adj,numCourses))
            return ans;

        // Find toposort and store it in stack
        stack<int mystack;
        vector<bool> visited(numCOurses, false);

        // Apply DFS and find topological sort
        for(int i=0;i<numCourses; i++)
            if(!visited[i])
                dfs(adj, i, visited, mystack);

        while(!mystack.empty()){
            ans.push_back(mystack.top());
            mystack.pop();
        }

        return ans;
    }
};