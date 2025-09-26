#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<char>>& grid, int r, int c, 
                vector<vector<bool>>& visited) {
    int row = grid.size();
    int col = grid[0].size();
  
    // r is in range, c is in range, value 
    // is 'L' (land) and not yet visited
    return (r >= 0) && (r < row) && (c >= 0) && 
           (c < col) && (grid[r][c] == '1' && !visited[r][c]);
}

// A utility function to do DFS for a
// 2D boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void dfs(vector<vector<char>>& grid, int r, int c,
           vector<vector<bool>>& visited) {
  
    // These arrays are used to get
    // r and c numbers of 8
    // neighbours of a given cell
    vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
    visited[r][c]=true;
    for(auto k : dir){
        int x= r+k[0];
        int y= c+k[1];
        if(isSafe(grid, x,y,visited)){
         dfs(grid, x, y, visited);   
        }
    }
   /* vector<int> rNbr = { -1, 0, 0, 1 };
    vector<int> cNbr = { 0, -1, 1, 0 };

    // Mark this cell as visited
    visited[r][c] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 4; ++k) {
        int newR = r + rNbr[k];
        int newC = c + cNbr[k];
        if (isSafe(grid, newR, newC, visited)) {
            dfs(grid, newR, newC, visited);
        }
    }*/
}

// The main function that returns
// count of islands in a given boolean
// 2D matrix
int countIslands(vector<vector<char>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
  
    // Make a bool array to mark visited cells.
    // Initially all cells are unvisited
    vector<vector<bool>> visited(row, vector<bool>(col, false));

    // Initialize count as 0 and traverse through
    // all cells of the given matrix
    int count = 0;
    for (int r = 0; r < row; ++r) {
        for (int c = 0; c < col; ++c) {
          
            // If a cell with value 'L' (land) is not visited yet,
            // then a new island is found
            if (grid[r][c] == '1' && !visited[r][c]) {
               
                // Visit all cells in this island.
                dfs(grid, r, c, visited);
                
                // Increment the island count
                ++count;
            }
        }
    }
    return count;
}
int main() {
    // your code goes here
    vector<vector<char>> grid = { { '1', '1', '0', '0', '0' },
                                  { '1', '1', '0', '0', '0' },
                                  { '0', '0', '1', '0', '0' },
                                  { '0', '0', '0', '1', '1' } };

    cout << countIslands(grid) << endl;

    return 0;

}
