//  字符串反转
//  写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。例如：
//  https://www.nowcoder.com/practice/e45e078701ab4e4cb49393ae30f1bb04?tpId=37&tqId=21235&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>

using namespace std;
int main(){
    string _old;
    cin>>_old;
    int end = _old.size();
    int start = -1;
    char* _new = new char[end+1];
    _new[end] = '\0';
    while(end){
        _new[++start] = _old[--end];
    }
    cout<<_new;
}