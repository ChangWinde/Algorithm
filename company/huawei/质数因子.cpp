//  质数因子
//  功能:输入一个正整数，按照从小到大的顺序输出它的所有质数的因子（如180的质数因子为2 2 3 3 5 ）
//  最后一个数后面也要有空格
//  详细描述：
//  函数接口说明：
//  public String getResult(long ulDataInput)
//  输入参数：
//  long ulDataInput：输入的正整数
//  返回值：
//  String
//  https://www.nowcoder.com/practice/196534628ca6490ebce2e336b47b3607?tpId=37&tqId=21229&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>

using namespace std;

int main(){
    long int num;
    cin>>num;
    int factor = 2;
    while(num != 1){
        while((num%factor) == 0){
            num /= factor;
            cout<<factor<<" ";
        }
        factor++;
    }
}