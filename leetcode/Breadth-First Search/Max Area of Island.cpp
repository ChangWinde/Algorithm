//  695. Max Area of Island
//  Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.
//  Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)
//  https://leetcode.com/problems/max-area-of-island/

class Solution {
public:
    int m,n;
    int getArea(vector<vector<int>>& g,pair<int,int>&p){
        stack<pair<int,int>> s;
        s.push(p);
        int res = 0;
        g[p.first][p.second] = 0;
        while(!s.empty()){
            pair<int,int> curr = s.top();
            s.pop();
            res++;
            if(curr.second+1<n && g[curr.first][curr.second+1]){
                s.push(pair<int,int>(curr.first,curr.second+1));
                g[curr.first][curr.second+1] = 0;
            }  
            if(curr.first+1<m && g[curr.first+1][curr.second]){
                s.push(pair<int,int>(curr.first+1,curr.second));
                g[curr.first+1][curr.second] = 0;
            }
            if(curr.second-1>=0 && g[curr.first][curr.second-1]){
                s.push(pair<int,int>(curr.first,curr.second-1));
                g[curr.first][curr.second-1] = 0;
            }  
            if(curr.first-1>=0 && g[curr.first-1][curr.second]){
                s.push(pair<int,int>(curr.first-1,curr.second));
                g[curr.first-1][curr.second] = 0;
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if(grid.empty()||grid[0].empty())
            return 0;
        m = grid.size(), n = grid[0].size();
        int maxArea = 0;
        for(int i = 0;i<m;++i){
            for(int j = 0;j<n;++j){
                if(grid[i][j]){
                    pair<int,int>p(i,j);
                    int area = getArea(grid,p);
                    maxArea = maxArea>area?maxArea:area;
                }else{
                    continue;
                }
            }
        }
        return maxArea;
    }
};