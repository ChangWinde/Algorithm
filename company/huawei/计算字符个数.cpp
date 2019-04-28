//  计算字符个数
//  写出一个程序，接受一个由字母和数字组成的字符串，和一个字符，然后输出输入字符串中含有该字符的个数。不区分大小写。
//  https://www.nowcoder.com/practice/a35ce98431874e3a820dbe4b2d0508b1?tpId=37&tqId=21225&tPage=1&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking

#include<iostream>
#include<string>
using namespace std;

int main(){
    string str;
    char target;
    int count = 0;
    cin>>str>>target;
    target = target|32;  //|32转小写，&223转大写
    for(auto i:str){
        if((i|32) == target)
            count++;
    }
    cout<<count;
}