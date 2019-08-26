//  后缀子串排序
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s;
void sol(){
    int len = s.size();
    vector<string> p;
    for(int i =0;i<len;i++){
        p.push_back(s.substr(i,len));
    }
    sort(p.begin(),p.end());
    for(int i = 0;i<len;i++)
        cout<<p[i]<<endl;
}
int main(){
    while(cin>>s){
        sol();
    }
}