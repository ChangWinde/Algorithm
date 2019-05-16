//  200. Number of Islands
//  Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//  https://leetcode.com/problems/number-of-islands/

class Solution {
public:
    int m,n;
    void fillABolck(vector<vector<char>>& g,pair<int,int>p){
        stack<pair<int,int>> s;
        s.push(p);
        g[p.first][p.second] = 0;
        while(!s.empty()){
            pair<int,int> curr = s.top();
            s.pop();
            if(curr.second+1<n && g[curr.first][curr.second+1] == '1'){
                s.push(pair<int,int>(curr.first,curr.second+1));
                g[curr.first][curr.second+1] = '0';
            }
            if(curr.second-1>=0 && g[curr.first][curr.second-1] == '1'){
                s.push(pair<int,int>(curr.first,curr.second-1));
                g[curr.first][curr.second-1] = '0';
            }
            if(curr.first+1<m && g[curr.first+1][curr.second] == '1'){
                s.push(pair<int,int>(curr.first+1,curr.second));
                g[curr.first+1][curr.second] = '0';
            }
            if(curr.first-1>=0 && g[curr.first-1][curr.second] == '1'){
                s.push(pair<int,int>(curr.first-1,curr.second));
                g[curr.first-1][curr.second] = '0';
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()||grid[0].empty())
            return 0;
        m = grid.size(),n = grid[0].size();
        int res = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(grid[i][j] == '1'){
                    fillABolck(grid,pair<int,int>(i,j));
                    res++;
                }else{
                    continue;
                }
            }
        }
        return res;
    }
};