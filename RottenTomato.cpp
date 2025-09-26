#include <bits/stdc++.h>
using namespace std;
bool isSafe(int n, int m, int i, int j){
        if(i>=0 && i<n && j>=0 && j<m)
        return true;
        else
        return false;

    }
    void DFS(vector<vector<int>>& grid, int i, int j, int time){
        grid[i][j]=time;
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        for(auto k : dir){
            int i1=i+k[0];
            int j1=j+k[1];
            if(isSafe(n, m, i1,j1)&&(grid[i1][j1]==1 || grid[i1][j1]>1+time)){
                DFS(grid, i1, j1, time+1);
            }
        }
        return;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int time =2;
        for(int i=0;i<n;i++){
            for(int j=0; j<m;j++){
                if(grid[i][j]==2){
                    
                    DFS(grid, i, j, time);
                }
                for(auto i : grid){
                  cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
                  }
                  cout<<"_________________"<<endl;
            }
        }
         time =0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                return -1;
                else{
                    time=max(time, grid[i][j]-2);
                }
            }
        }
        return time;

        
    }
int main() {
    // your code goes here
    vector<vector<int>> grid= {{2,1,1},{1,1,1},{0,1,2}};
    int time = orangesRotting(grid);
    cout<<time<<endl;
    /*for(auto i : grid){
        cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
    }*/

}
