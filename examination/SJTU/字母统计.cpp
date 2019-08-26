//  字母统计
#include<iostream>
#include<string>
using namespace std;
string s;
int num[26];
int main(){
    while(cin>>s){
        int len = s.size();
        while(len--){
            if(isalpha(s[len])){
                num[s[len]-'A']++;
            }
        }
        char p = 'A';
        for(int i =0;i<26;i++){
            cout<<p<<":"<<num[i]<<endl;
            p++;
        }
    }
}