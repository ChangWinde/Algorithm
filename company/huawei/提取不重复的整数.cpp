//  提取不重复的整数
//  输入一个int型整数，按照从右向左的阅读顺序，返回一个不含重复数字的新的整数。
//  https://www.nowcoder.com/practice/253986e66d114d378ae8de2e6c4577c1?tpId=37&tqId=21232&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>

using namespace std;

int main(){
    int bitmap = 0;
    int num;
    cin>>num;
    int res = 0;
    while(num){
        int pos = num%10;
        num /= 10;
        if((bitmap&(1<<pos)) == 0){
            bitmap = bitmap|(1<<pos);
            res += pos;
            res *= 10;
        }
    }
    cout<<res/10;
}