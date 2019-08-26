//  P1141 01迷宫

#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define MAX 1000+5
#define MAXT 100000+5
int dr[][2] = {-1,0,1,0,0,-1,0,1};
int g[MAX][MAX];
int M[MAXT][2];
int n,m;
int cnt = 0;
vector<int> res;

void dfs(int x ,int y,int id){
    if(x<1||x>n||y<1||y>n)return;
    if(g[x][y]<0)return;
    g[x][y] = 0-id;
    res[id-1]++;
    for(int i = 0;i<4;++i){
        dfs(x+dr[i][0],y+dr[i][1],cnt);
    }
}

int main(){
    scanf_s("%d%d",&n,&m);
    for(int i = 1;i<=n;++i)
        for(int j = 1;j<=n;++j)
            cin>>g[i][j];
    for(int i = 1;i<=m;++i)
        cin>>M[i][0]>>M[i][1];
    for(int i = 1;i<=n;++i){
        for(int j = 1;j<=n;++j){
            if(g[i][j]>=0){
                res.push_back(0);
                dfs(i,j,cnt);
            }    
        }
    }
    for(int i =1;i<=m;++i)
        cout<<res[-1-g[m[i][0]][m[i][1]]]<<endl;
    system("pause");
}