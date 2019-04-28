//  蛇形矩阵
//  蛇形矩阵是由1开始的自然数依次排列成的一个矩阵上三角形。
//  https://www.nowcoder.com/practice/649b210ef44446e3b1cd1be6fa4cab5e?tpId=37&tqId=21258&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=2

#include<iostream>

using namespace std;

int main(){
    int num;
    while(cin>>num){
        for(int i = 0;i<num;++i){
            int start = i*(i+1)/2+1;
            int gap = i+2;
            int count = num-i;
            while(count--){
                cout<<start<<" ";
                start += gap++;
            }
            cout<<endl;
        }
    }
}