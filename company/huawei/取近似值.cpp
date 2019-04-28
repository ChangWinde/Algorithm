//  取近似值
//  写出一个程序，接受一个正浮点数值，输出该数值的近似整数值。如果小数点后数值大于等于5,向上取整；小于5，则向下取整。
//  https://www.nowcoder.com/practice/3ab09737afb645cc82c35d56a5ce802a?tpId=37&tqId=21230&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
using namespace std;

int main(){
    double tar;
    cin>>tar;
    int res = tar;
    if((int)((tar-res)*10)>=5)
        res++;
    cout<<res;
}