// GRAPHS PLAYLIST TECHDOSE

// #08 LC - 886 Possible Bipartition bipartite graph - Graph Coloring

class Solution{
    bool isBipartite(vector<vector<int>>& adj, int N, int node, vector<int>& color){
        queue<int> q;
        q.push(node);
        color[node] = 1;

        // Process current graph component using BFS
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int ele:adj[curr]){
                if(color[ele] == color[curr])
                    return false;
                if(color[ele] == -1){
                    color[ele] =  1 - color[curr];
                    q.push(ele);
                }
            }
        }

        return true;
    }

public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {

        vector<vector<int>> adj(N+1);
        for(int i=0;i<dislikes.size();i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
            adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        vector<int> color(N+1,-1);
        for(int i=1;i<=N;i++){
            if(color[i] == -1){
                if(!isBipartite(adj,N,i,color)){
                    return false;
                }
            }
        }

        return true;
    }

};