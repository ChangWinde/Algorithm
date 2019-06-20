//  划分字符串

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
string s;
int len;
void findParlind(int l,int r,vector<vector<bool> >& sp){
    while((l>=0 && r<len)&&(s[r]==s[l])){
        sp[l--][r++] = true;
    }
}
int main(){
    int test;
    cin>>test;
    while(test--){
        cin>>s;
        len = s.size();
        vector<vector<bool> > sp(len,vector<bool>(len,false));
        for(int i = 0;i<len;++i){
            //偶数串
            findParlind(i,i+1,sp);
            //奇数串
            findParlind(i,i,sp);
        }
        vector<int> dp(len,INT_MAX);
        dp[0] = 1;
        for(int i = 1;i<len;++i){
            for(int j = i;j>=0;--j){
                if(sp[j][i]){
                    dp[i] = (j==0)?1:min(dp[i],dp[j-1]+1);
                }
            }
        }
        cout<<dp[len-1]<<endl;
    }
    //system("pause");
}