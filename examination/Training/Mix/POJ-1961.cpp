//  POJ-1961 Period
//  http://poj.org/problem?id=1961
//  考察KMP的next数组的含义
//  next数组的含义是 字符串中以i结尾的子串与该字符串的前缀能匹配的最长长度
//  当i-next[i]能整除i时，S[1~i-next[i]]就是S[1~i]的最小循环元。它的最大循环次数就是i/(i - next[i])
#include<iostream>
#include<string>
using namespace std;
const int maxn = 1000000 + 5;
int nextt[maxn];
string s;
int len;

void make() {
	int i = 0, j = -1;
	nextt[i] = -1;
	while (i < len) {
		while (j != -1 && s[i] != s[j])j = nextt[j];
		nextt[++i] = ++j;
	}
}
void sol() {
	for (int i = 1; i <= len; i++) if(nextt[i]>0&&i%(i-nextt[i])==0){
		cout << i << " " << i / (i - nextt[i]) << endl;
	}
	cout << endl;
}
int main() {
	int cnt = 0;
	while (cin >>len>>s) {
		cout <<"Test case #"<< ++cnt << endl;
		make();
		sol();
	}
}