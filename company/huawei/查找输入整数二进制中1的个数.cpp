//  查找输入整数二进制中1的个数
//  https://www.nowcoder.com/practice/1b46eb4cf3fa49b9965ac3c2c1caf5ad?tpId=37&tqId=21285&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=4

#include<iostream>

using namespace std;

int main(){
    int num;
    while(cin>>num){
        int count =0;
        while(num){
            num = num&(num-1);
            count++;
        }
        cout<<count<<endl;
    }
}