//  130. Surrounded Regions
//  Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.
//  A region is captured by flipping all 'O's into 'X's in that surrounded region.
//  https://leetcode.com/problems/surrounded-regions/

class Solution {
public:
    int row,col;
    void solve(vector<vector<char>>& board) {
        if(board.empty()||board[0].empty())
            return ;
        row = board.size(),col = board[0].size();
        for(int i = 0;i<row;++i){
            changeO(board,pair<int,int>(i,0));
            changeO(board,pair<int,int>(i,col-1));
        }
        for(int i = 1;i<col-1;++i){
            changeO(board,pair<int,int>(0,i));
            changeO(board,pair<int,int>(row-1,i));
        }
        for(int i = 0;i<row;++i){
            for(int j = 0;j<col;++j){
                if(board[i][j] == 'A')
                    board[i][j] = 'O';
                else if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
    void changeO(vector<vector<char>>& b,pair<int,int>p){
        if(b[p.first][p.second] == 'O'){
            b[p.first][p.second] = 'A';
            if(p.first+1<row)
                changeO(b,pair<int,int>(p.first+1,p.second));
            if(p.first-1>=0)
                changeO(b,pair<int,int>(p.first-1,p.second));
            if(p.second+1<col)
                changeO(b,pair<int,int>(p.first,p.second+1));
            if(p.second-1>=0)
                changeO(b,pair<int,int>(p.first,p.second-1));
        }
    }
};