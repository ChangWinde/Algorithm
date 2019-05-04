//  等差数列
//  功能:等差数列 2，5，8，11，14。。。。
//  输入:正整数N >0
//  输出:求等差数列前N项和
//  返回:转换成功返回 0 ,非法输入与异常返回-1
//  https://www.nowcoder.com/practice/f792cb014ed0474fb8f53389e7d9c07f?tpId=37&tqId=21323&tPage=5&rp=&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking

#include<iostream>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        if(num<1)
            return -1;
        cout<<(1+3*num)*num/2<<endl;
    }
}