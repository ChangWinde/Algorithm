//  公共字串计算
//  计算两个字符串的最大公共字串的长度，字符不区分大小写
//  https://www.nowcoder.com/practice/98dc82c094e043ccb7e0570e5342dd1b?tpId=37&tqId=21298&tPage=4&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    string s1,s2;
    while(cin>>s1>>s2){
        int l1 = s1.size(),l2 = s2.size();
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        int max = -1;
        for(int i=1;i<l1+1;++i){
            for(int j=1;j<l2+1;++j){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = 0;
                }
                if(dp[i][j]>max){
                    max = dp[i][j];
                }
            }
        }
        cout<<max<<endl;
    }
}