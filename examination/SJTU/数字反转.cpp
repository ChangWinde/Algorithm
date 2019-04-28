//  12翻一下是21,34翻一下是43,12+34是46,46翻一下是64，现在又任意两个正整数，问他们两个数反转的和是否等于两个数的和的反转。
//  https://www.nowcoder.com/practice/2687c5c174cb4f938bdae01f0a19490c?tpId=40&tqId=21428&tPage=1&rp=1&ru=/ta/kaoyan&qru=/ta/kaoyan/question-ranking

#include<iostream>
using namespace std;

int reverse(int a){
    int b = 0;
    while(a){
        b += a%10;
        a = a/10;
        b = b*10;
    }
    return b;
}
int main(){
    int a,b;
    while(cin>>a>>b){
        if(reverse(a)+reverse(b) == reverse(a+b))
            cout<<a+b<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}