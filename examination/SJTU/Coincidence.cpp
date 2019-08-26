//  coincidence

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int dp[105][105];
string s1,s2;
int cal(){
    s1 = '0'+s1;
    s2 = '0'+s2;
    int len1 = s1.size();
    int len2 = s2.size();
    for(int i = 0;i<=len1;i++)
        dp[i][0] = 0;
    for(int i = 0;i<=len2;i++)
        dp[0][i] = 0;
    for(int i = 1;i<len1;i++){
        for(int j = 1;j<len2;j++){
            if(s1[i] == s2[j]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[len1-1][len2-1];
}
int main(){
    while(cin>>s1>>s2){
        cout<<cal()<<endl;
    }
}