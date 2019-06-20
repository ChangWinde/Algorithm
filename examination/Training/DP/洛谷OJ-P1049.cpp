//  P1049 装箱问题

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int V,n;
    while(cin>>V>>n){
        vector<int> c(n+1,0);
        for(int i = 1;i<=n;++i)
            cin>>c[i];
        vector<vector<int> > dp(n+1,vector<int>(V+1,0));
        for(int i = 1;i<=n;++i){
            for(int j = 0;j<=V;++j){
                dp[i][j] = dp[i-1][j];
                if(j>=c[i])
                    dp[i][j] = max(dp[i][j],dp[i-1][j-c[i]]+c[i]);
            }
        }
        cout<<V-dp[n][V]<<endl;
    }
}