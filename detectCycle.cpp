#include <bits/stdc++.h>
using namespace std;

 void conversion(vector<vector<int>> &edges,vector<vector<int>> &adj ){
        
        
            for(auto k : edges){
                adj[k[0]].push_back(k[1]);
                adj[k[1]].push_back(k[0]);
            }
        return;
    }
    bool detectCycle(vector<vector<int>> &adj, int parent, int v, vector<bool> &visited){
        visited[v]=true;
        
        for(int i : adj[v]){
            if(!visited[i]){
                if(detectCycle(adj,v,i,visited))
                  return true;
            }else if(i!=parent){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adj(v);
        conversion(edges, adj);
        vector<bool> visited (v, false);
        
        for(int i=0;i<v;i++){
            if(!visited[i]){
             if(detectCycle(adj, -1, i, visited)){
                 return true;
             }    
            }
        }
        return false;
        
        
    }
int main()
{
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {3, 4}};

    if (isCycle(V, edges))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}