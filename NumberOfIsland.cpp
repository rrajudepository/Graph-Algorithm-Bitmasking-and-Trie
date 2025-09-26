#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x, int y){
        if( x>=0 && (x<grid.size()) && y>=0 && (y<grid[0].size()) && grid[x][y]=='1' && !visited[x][y]){
            return true;
        }else{
            return false;
        }
    }
    
    
    void DFS(vector<vector<char>> &grid, vector<vector<bool>> &visited, int i, int j){
        visited[i][j]=true;
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(auto d : dir){
            int x= i+d[0];
            int y= j+d[1];
            if(isSafe(grid,visited, x,y)){
                cout<<x<<" "<<y<<endl;
                DFS(grid, visited, x, y);
            }
        }
        for(auto d : visited){
                    cout<<d[0]<<d[1]<<d[2]<<d[3]<<d[4]<<endl;
                }
        cout<<"Rajkishor1"<<endl;
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int count=0;
        for(auto d : visited){
                    cout<<d[0]<<d[1]<<d[2]<<d[3]<<d[4]<<endl;
                }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    cout<<"Rajkishor"<<endl;
                    DFS(grid, visited, i ,j);
                    cout<<"Rajkishor"<<endl;
                    count++;

                }
                for(auto d : visited){
                    cout<<d[0]<<d[1]<<d[2]<<d[3]<<d[4]<<endl;
                }
            }
        }
        return count;
    }
    
    
int main() {
    // your code goes here
    vector<vector<char>> grid ={{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
    cout<<numIslands(grid);
    return 0;

}
