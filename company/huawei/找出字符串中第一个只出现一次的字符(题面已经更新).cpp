//  找出字符串中第一个只出现一次的字符(题面已经更新)
//  找出字符串中第一个只出现一次的字符
//  https://www.nowcoder.com/practice/e896d0f82f1246a3aa7b232ce38029d4?tpId=37&tqId=21282&tPage=3&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        int label = 0;
        char res;
        for(auto i:s){
            if(label&(1<(i-'a')) == 0){
                label = label|(1<(i-'a'));
                res = i;
            }
        }
        cout<<res<<endl;
    }
}