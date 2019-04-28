//  字符个数统计
//  编写一个函数，计算字符串中含有的不同字符的个数。字符在ACSII码范围内(0~127)。不在范围内的不作统计。
//  https://www.nowcoder.com/practice/eb94f6a5b2ba49c6ac72d40b5ce95f50?tpId=37&tqId=21233&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    int count = 0;
    string str;
    cin>>str;
    vector<bool> bitmap(128,false);
    int size = str.size();
    while(size--){
        int index = (int)str[size];
        if(!bitmap[index]){
            count++;
            bitmap[index] = true;
        }
    }
    cout<<count;
}