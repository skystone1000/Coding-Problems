// GRAPHS PLAYLIST TECHDOSE

// #08 LC - 886 Possible Bipartition bipartite graph - Graph Coloring
// https://leetcode.com/problems/possible-bipartition/

/*
    Approach (without Graph)
    We can solve this with 2 sets or map with simple conditional checking to see if the pairs can be 
    put in different set

    -----------------     ----------------    -------------------
    Bi-graph / Bi-partite graph ==> A Bigraph is a graph whose vertices can be divided into 2 disjoint
    and independent sets U & V such that every edge connects a vertex in U to a vertex in V.

    ** If the graph formed is Bi Partite then we can divide the elements in 2 sets **

    Facts:
        - A Bipartite graph can only have even edge cycle.
        - Odd cycle will only be possible if there is an edge between 2 vertices in a set
            but then the graph will no longer be BIPARTITE

    Solution 1
    STEP 1)  Make adjacency List
    STEP 2) If there is no oe=dd length cycle then the graph is bipartite
    Therefore it will be possible to separate incompatible persons in 2 diff SET

    Solution 2 - Graph Coloring
    In this we will use just 2 colors to detemine the even odd length cycle.
    Start with one color for a node and all its adjacent nodes should have its complementary color.
    If you are able to color the complete graph without ambiguity then you can say that it is even cycle 
    else if there is an ambiguity then it would be odd cycle.

    We can use BFS or DFS for solving the problem. 


*/

#include<bits/stdc++.h>
using namespace std;

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