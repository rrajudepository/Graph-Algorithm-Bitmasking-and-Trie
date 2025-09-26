#include <iostream>
#include <vector>
using namespace std;
void setZero(vector<vector<int>>& matrix, int i, int j){
        for(int k=0;k<matrix[i].size();k++){
            matrix[i][k]=0;
        }
        for(int k=0;k<matrix.size();k++){
            matrix[k][j]=0;
        }
        return;
    }
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j =0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    cout<<i<<" "<<j<<endl;
                    setZero(matrix, i, j);

                }
            }
        }
        
    }
int main(){
    vector<vector<int>> matrix ={{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(matrix);
    for(auto k : matrix){
        cout<<k[0]<<k[1]<<k[2]<<endl;
    }

}