// GRAPHS PLAYLIST TECHDOSE

// #07 Number of Islands 

class Solution{
    void mark_current_island(vector<vector<char>> &matrix, int x, int y, int r, int c){
        if(x<0 || x>=r || y<0 || y>=c || matrix[x][y]!='1')
            return;

        // Make current cell as visited
        matrix[x][y] = '2';

        // Make current cell as visited
        matrix[x][y] = '2';

        // Make recursive calls in all 4 adjecent directions
        mark_current_island(matrix, x+1, y, r, c);
        mark_current_island(matrix, x, y+1, r, c);
        mark_current_island(matrix, x-1, y, r, c);
        mark_current_island(matrix, x, y-1, r, c);

    }

public:
    int numIslands(vector<vector<char>>& grid){
        int rows = grid.size();
        if(rows == 0)
            return 0;
        int cols = grid[0].size();

        int no_of_islands = 0;
        for(int i=0;j<cols;j++){
            for(int j=0;j<cols;j++){
                if(grid[i][j] == '1'){
                    mark_current_island(grid,i,j,rows,cols);
                    no_of_islands += 1;
                }
            }
        }

        return no_of_islands;
    }
};