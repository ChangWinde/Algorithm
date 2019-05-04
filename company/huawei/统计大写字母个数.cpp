//  统计大写字母个数
//  找出给定字符串中大写字符(即'A'-'Z')的个数
//  https://www.nowcoder.com/practice/434414efe5ea48e5b06ebf2b35434a9c?tpId=37&tqId=21307&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=5

#include<iostream>
#include<string>
using namespace std;

bool isUp(char a){
    return a>='A'&&a<='Z';
}
int main(){
    string s;
    while(cin>>s){
        int count = 0;
        for(auto i:s)
            count += isUp(i);
        cout<<count<<endl;
    }
}
