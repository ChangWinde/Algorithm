//  最大子序列

#include<iostream>
#include<algorithm>
#define M 1000000+5
using namespace std;
typedef long long ll;
int s[M];
int dp[M];
int n;
ll mymax(ll x,int y){
    return x>y?x:y;
}
ll cal(){
    ll res;
    dp[1] = s[1];
    for(int i = 2;i<=n;i++){
        dp[i] = max(dp[i-1]+s[i],s[i]);
        res = mymax(res,dp[i]);
    }
    return res;
}

int main(){
    while(cin>>n){
        for(int i = 1;i<=n;i++){
            cin>>s[i];
        }
        cout<<cal()<<endl;
    }
}