// GRAPHS PLAYLIST TECHDOSE

// #07 Number of Islands 
// https://leetcode.com/problems/number-of-islands/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0){
            return 0;
        }     
        
        int islandCount = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == '1'){
                    islandCount++;
                    dfs(i,j,grid);
                }
            }
        }
        return islandCount;
    }
    
    void dfs(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[i].size()-1 || grid[i][j] != '1'){
            return;
        }
        grid[i][j] = '2';
        
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
        
    }
}; 