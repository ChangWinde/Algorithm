//  按字节截取字符串
//  编写一个截取字符串的函数，输入为一个字符串和字节数，输出为按字节截取的字符串。但是要保证汉字不被截半个，如"我ABC"4，应该截为"我AB"，输入"我ABC汉DEF"6，应该输出为"我ABC"而不是"我ABC+汉的半个"。 
//  https://www.nowcoder.com/practice/a30bbc1a0aca4c27b86dd88868de4a4a?tpId=37&tqId=21269&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    int num;
    while(cin>>s>>num){
        int i = 0;
        int size = s.size();
        while(num-sizeof(s[i])>0&&i<size){num -= sizeof(s[i]);i++;}
        cout<<s.substr(0,i+1)<<endl;
    }
}