//  hdu2191
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int test;
int C,m;
int v[105],w[105],num[105];
int dp[105];
int main(){
    cin>>test;
    while(test--){
        cin>>C>>m;
        memset(dp,0,sizeof(dp));
        for(int i = 0;i<m;i++)
            cin>>v[i]>>w[i]>>num[i];
        for(int i = 0;i<m;i++){
            for(int j = 0;j<num[i];j++){
                for(int k =C;k>=v[i];k--){
                    dp[k] = max(dp[k-v[i]]+w[i],dp[k]);
                }
            }
        }
        cout<<dp[C]<<endl;
    }
}
