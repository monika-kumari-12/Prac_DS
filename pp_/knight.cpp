#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>>dir={{1,2},{-1,2},{2,1},{2,-1},{-1,-2},{1,-2},{-2,1},{-2,-1}};
bool isValid(int r,int c,vector<vector<int>>&board){
    if(r<0 || c<0 ||r>=board.size()||c>=board[0].size()||board[r][c]!=-1){
        return false;
    }
    return true;
}

bool knightmoves(int sr,int sc,int move, vector<vector<int>>&board){
    if(move==64){
        return true;
    }
    
    for(int i=0;i<dir.size();i++){
        int row=sr+dir[i][0];
        int col=sc+dir[i][1];
        if(isValid(row,col,board)){
            board[row][col]=move;
            knightmoves(row,col,move+1, board);
        }
    }
    return false;
    
}

int main(){
    vector<vector<int>>board(8,vector<int>(8,-1));
    // for(int i=0;i<board.size();i++){
    //     for(int j=0;j<board.size();j++){
    //         cout<<board[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
   cout<<knightmoves(0,0,0,board)<<endl;
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board.size();j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}