//  字串的连接最长路径查找
//  给定n个字符串，请对n个字符串按照字典序排列。
//  https://www.nowcoder.com/practice/5af18ba2eb45443aa91a11e848aa6723?tpId=37&tqId=21237&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
int main() {
    int num;
    while(cin>>num){
        vector<string> res(num, "");
        while (num--) {
            string temp;
            cin >> temp;
            res[num] = temp;
        }
        sort(res.begin(), res.end(), less<string>());
        for (auto i : res)
            cout << i << endl;
    }
}