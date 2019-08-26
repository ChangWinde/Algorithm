//  最大上升子序列和
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int d[1005];
int dp[1005];
int n;

int cal(){
    //memset(dp,0,sizeof(dp));
    dp[1] = d[1];
    int ans = dp[1];
    for(int i = 2;i<=n;i++){
        dp[i] = d[i];
        for(int j =1;j<i;j++){
            if(d[i]>d[j])
                dp[i] = max(dp[i],d[i]+dp[j]);
        }
        ans = max(ans,dp[i]);
    }
    return ans;
}

int main(){
    while(cin>>n){
        for(int i = 1;i<=n;i++)
            scanf("%d",&d[i]);
        printf("%d\n",cal());
    }
}