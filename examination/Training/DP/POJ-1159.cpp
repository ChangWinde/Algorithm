//  Palindrome POJ - 1159
//  http://poj.org/problem?id=1159
// 求解一个串最少可以插入多少个字符就可以变成回文串
// ans = s.size()-lcs(s,reverse(s))
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s, sr;
int len;
string reverse(string str) {
	int i = -1, j = str.size();
	while (++i < --j) {swap(str[i], str[j]);}
	return str;
}
int dp[3][5001];
const int mod = 3;
int lcs() {
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (s[i] == sr[j])dp[(i + 1) % mod][j + 1] = dp[i%mod][j] + 1;
			else {
				dp[(i+1) % mod][j + 1] = max(dp[i%mod][j + 1], dp[(i + 1) % mod][j]);
			}
		}
	}
	return dp[len%mod][len];
}
int main() {
	while (cin >> len >> s) {
		sr = reverse(s);
		cout << len-lcs() << endl;
	}
}