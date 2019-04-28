//  求小球落地5次后所经历的路程和第5次反弹的高度
//  假设一个球从任意高度自由落下，每次落地后反跳回原高度的一半; 再落下, 求它在第5次落地时，共经历多少米?第5次反弹多高？ 
//  https://www.nowcoder.com/practice/2f6f9339d151410583459847ecc98446?tpId=37&tqId=21261&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=2

#include<iostream>

using namespace std;

int main(){
    double height;
    while(cin>>height){
        int count = 5;
        double res = height;
        while(--count){
            res += height;
            height /= 2;
        }
        cout<<res<<endl<<height/2<<endl;
    }
}