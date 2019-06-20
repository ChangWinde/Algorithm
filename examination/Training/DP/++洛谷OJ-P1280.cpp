//  P1280 尼克的任务

#include<iostream>
#include<vector>

using namespace std;
int main(){
    int T,K;
    while(cin>>T>>K&&T&&K){
        vector<int> t(K+1,0),p(K+1,0);
        for(int i = 1;i<=K;++i){
            cout<<p[i]<<t[i];//p+t-1
        }
        
    }
}