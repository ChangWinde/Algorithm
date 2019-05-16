//  字符串分割
//  连续输入字符串(输出次数为N,字符串长度小于100)，请按长度为8拆分每个字符串后输出到新的字符串数组，
//  长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。
//  首先输入一个整数，为要输入的字符串个数。
//  https://www.nowcoder.com/practice/fa2e02625a8541beb2309fcb7ab31e5b?tpId=37&tqId=21327&tPage=6&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking

#include<iostream>
#include<string>
using namespace std;
void printString(string& s){
    int i =0,size=s.size();
    while(i+8<size){
        cout<<s.substr(i,8)<<endl;
        i += 8;
    }
    if(i<size){
        string str = s.substr(i,size);
        str.resize(8,'0');
        cout<<str<<endl;
    }
}
int main(){
    int num;
    while(cin>>num){
        string s;
        while(num--){
            cin>>s;
            printString(s);
        }
    }
}