//  01背包

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int T,m;
int t[105],v[105];
int dp[10005];
int sol(){
    memset(dp,0,sizeof(dp));
    for(int i = 1;i<=m;i++){
        for(int j = T;j>=t[i];j--){
            dp[j] = max(dp[j-t[i]]+v[i],dp[j]);
        }
    }
    return dp[T];
}

int main(){
    while(cin>>T>>m){
        for(int i = 1;i<=m;i++){
            cin>>t[i]>>v[i];
        }
        cout<<sol()<<endl;
    }
}
