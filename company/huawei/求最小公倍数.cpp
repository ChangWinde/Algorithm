//  求最小公倍数
//  正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。
//  https://www.nowcoder.com/practice/22948c2cad484e0291350abad86136c3?tpId=37&tqId=21331&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=6

#include<iostream>

using namespace std;

int main(){
    int a,b;
    while(cin>>a>>b){
        int pro = a*b;
        int c = a%b;
        while(c != 0){
            a = b;
            b = c;
            c = a%b;
        }
        cout<<pro/b<<endl;
    }
}