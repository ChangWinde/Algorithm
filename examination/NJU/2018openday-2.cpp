//  Surrounded Regions
class Solution {
public:
    int dr[4][2] = {-1,0,1,0,0,-1,0,1};
    int n,m;
    bool check(int x,int y){
        return x>=0&&x<n&&y>=0&&y<m;
    }
    void dfs(vector<vector<char>>& map,int x,int y){
        map[x][y] = 'A';
        for(int i =0;i<4;i++){
            int nx = dr[i][0]+x,ny=dr[i][1]+y;
            if(check(nx,ny)&&map[nx][ny]=='O'){
                dfs(map,nx,ny);
            }
        }
    }
    void solve(vector<vector<char>>& map) {
        if(map.empty())return;
        n=map.size(),m=map[0].size();
        for(int i = 0;i<n;i++){
            if(map[i][0]=='O')dfs(map,i,0);
            if(map[i][m-1]=='O')dfs(map,i,m-1);
        }
        for(int i = 1;i<m-1;i++){
            if(map[0][i]=='O')dfs(map,0,i);
            if(map[n-1][i]=='O')dfs(map,n-1,i);
        }
        for(int i = 0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]=='A')
                    map[i][j] = 'O';
                else if(map[i][j]=='O')
                   map[i][j]= 'X';
            }
        }
    }    
};