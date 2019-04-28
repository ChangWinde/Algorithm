//  计算日期到天数转换
//  根据输入的日期，计算是这一年的第几天。。
//  https://www.nowcoder.com/practice/769d45d455fe40b385ba32f97e7bcded?tpId=37&tqId=21296&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=4

#include<iostream>
using namespace std;
bool isRun(int y){
    if((((y%4)==0)&&((y%100)!=0))||((y % 400)==0))
        return true;
    return false;
}
int days[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int y,m,d;
    while(cin>>y>>m>>d){
        int count = 0;
        if(isRun(y)){
            days[2] = 29;
        }else{
            days[2] = 28;
        }
        for(int i = 1;i<m;++i){
            count += days[i];
        }
        cout<<count+d<<endl;
    }
}