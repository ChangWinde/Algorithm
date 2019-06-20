//  P1164 小A点菜

#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n,m;
    while(cin>>n>>m&&n&&m){
        vector<int> p(n+1,0);
        for(int i = 1;i<=n;++i){
            cin>>p[i];
        }
        vector<vector<int> >dp(n+1,vector<int>(m+1,0));
        for(int i = 1;i<=n;++i){
            for(int j = 0;j<=m;++j){
                dp[i][j] = dp[i-1][j];
                if(j == p[i])
                    dp[i][j] = dp[i-1][j]+1;
                if(j>p[i])
                    dp[i][j] += dp[i-1][j-p[i]];
            }
        }
    }
}