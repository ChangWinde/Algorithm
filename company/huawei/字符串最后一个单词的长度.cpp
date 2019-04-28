//  字符串最后一个单词的长度
//  计算字符串最后一个单词的长度，单词以空格隔开。 
//  https://www.nowcoder.com/practice/8c949ea5f36f422594b306a2300315da?tpId=37&tqId=21224&tPage=1&rp=&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<ctype.h>
using namespace std;

int main(){
    char a;
    int count = 0;
    while(cin.get(a)){
        if(a == ' '){
            count = 0;
            continue;
        }
        count++;
    }
    cout<<count-1;
}


#include<iostream>
#include<string>
#include<vector>
 
using namespace std;
 
int main(){
    string input;
    vector<string>arr;
    while(cin>>input){
        arr.push_back(input);
    }
    cout<<arr[arr.size()-1].length()<<endl;    
    return 0;
}