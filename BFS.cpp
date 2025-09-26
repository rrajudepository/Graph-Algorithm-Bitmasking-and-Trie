#include <bits/stdc++.h>
using namespace std;
void bfs(vector<vector<int>> &adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> res;
        queue<int> q;
        //int node=0;
        q.push(0);
        visited[0]=true;
        while(!q.empty()){
          int node=q.front();
          q.pop();
          res.push_back(node);
          //cout<<"Node :"<<node<<endl;
          for(int i : adj[node]){
            //  cout<<i<<" ";
              if(!visited[i]){
              //    cout<<i<<endl;
                q.push(i);
              visited[i]=true;  
              }
              
          }
        }
        cout<<"Rajkishor"<<endl;
       // return res;
       
       for(int node : res){
           cout<<node<<" ";
       }
       cout<<endl;
    }

int main() {
	// your code goes here
	vector<vector<int>> adj={{2,3,1},{0},{0,4},{0},{2}};
	bfs(adj);

}
