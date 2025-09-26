#include <iostream>
#include <vector>
using namespace std;

bool valid(int i, int j, int n, int m){
         if(i>=0 && j>=0 && i<n && j<m) return true;
         else return false;
    }

bool findWord(vector<vector<char>>& board, string word, int i, int j, int k){
        if(k==word.length()){
            return true;
        }
        if(!valid(i,j, board.size(), board[0].size())){
            return false;
        }
        if(board[i][j]==word[k]){
            return (findWord(board, word, i+1, j,k+1)||findWord(board, word, i-1, j,k+1)||findWord(board, word, i, j+1,k+1)||findWord(board, word, i, j-1,k+1));
        }else{
            return false;
        }
        
}
    bool exist(vector<vector<char>>& board, string word) {
        return findWord(board, word, 0,0,0);
        
}

int main(){
    vector<vector<char>> board = {{'A','B','C','E'}, {'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    if(exist(board, word)){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }

}