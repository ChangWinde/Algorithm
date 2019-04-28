//  求int型正整数在内存中存储时1的个数
//  输入一个int型的正整数，计算出该int型数据在内存中存储时1的个数。
//  https://www.nowcoder.com/practice/440f16e490a0404786865e99c6ad91c9?tpId=37&tqId=21238&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=1

#include<iostream>
using namespace std;

int main(){
    int num;
    while(cin>>num){
        int count = 0;
        while(num){
            num = num&(num-1);
            count++;
        }
        cout<<count;
    }
}