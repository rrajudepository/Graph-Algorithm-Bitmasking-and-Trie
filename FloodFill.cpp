#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int>> &image, int x, int y, int i){
    if(x>=0 && y>=0 && x<image.size() && y<image[0].size() && image[x][y]==i){
        return true;
        }else{
            return false;
        }
  }
    void DFS(vector<vector<int>>& image, int sr, int sc, int color, vector<vector<int>> dir, int i){
        image[sr][sc]=color;
        for(auto k :dir){
            int x=sr+k[0];
            int y=sc+k[1];
            if(isSafe(image, x, y, i)){
                 DFS(image, x, y, color, dir, i);
            }
            for(auto k:image){
	    cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<endl;
     	}
     	cout<<"__________"<<endl;
        }
        
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int i= image[sr][sc];
        if(i==color){
            return image;
        }
        vector<vector<int>> dir={{1,0},{0,1},{-1,0},{0,-1}};
        DFS(image, sr, sc, color,dir,i);
        for(auto k:image){
	    cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<" "<<k[3]<<endl;
     	}
        return image;
    }
int main() {
	// your code goes here
	//vector<vector<int>> image ={{1,1,1},{1,1,0},{1,0,1}};
//vector<vector<int>> image ={{1,1,1,1},{1,1,1,0},{1,1,0,1},{1,0,1,1}};
     vector<vector<int>> image={{0,0,0},{0,0,0}};
	int sr=1, sc=0;
	int color=2;
	floodFill(image, sr, sc, color);
	for(auto k:image){
	    cout<<k[0]<<" "<<k[1]<<" "<<k[2]<<endl;
	}
	
   return 0;
}
