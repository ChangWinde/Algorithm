//  数字颠倒
//  描述：
//  输入一个整数，将这个整数以字符串的形式逆序输出
//  程序不考虑负数的情况，若数字含有0，则逆序形式也含有0，如输入为100，则输出为001
//  https://www.nowcoder.com/practice/ae809795fca34687a48b172186e3dafe?tpId=37&tqId=21234&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
using namespace std;

int main(){
    int num;
    cin>>num;
    string str = to_string(num);
    int i = 0;
    while(num){
        int temp = num%10;
        num /= 10;
        str[i++] = temp + '0';
    }
    cout<<str;
}