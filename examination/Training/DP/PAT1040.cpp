//  https://pintia.cn/problem-sets/994805342720868352/problems/994805446102073344
//  1040 Longest Symmetric Strings
// 寻找一个字符串中最长的回文串
#include<iostream>
#include<string>
using namespace std;
string s;
bool dp[1005][1005];
int sol() {
	int ans = 1;
	int len = s.size();
	for (int i = 0; i < len; i++) {
		dp[i][i]= true; 
		if (i&&s[i] == s[i - 1]) {
			dp[i - 1][i] = true;
			ans = 2;
		}
	}
	for (int i = 3; i <= len; i++) {
		for (int j = 0; j + i-1 < len; j++) {
			if (s[j] == s[i + j - 1] && dp[j + 1][i + j - 2]) { 
				dp[j][i + j - 1] = true; 
				ans = i;
			}
		}
	}
	return ans;
}

int main() {
	while (getline(cin,s)) {
		cout<<sol() << endl;
	}
}