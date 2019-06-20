//  P1282 多米诺骨牌

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		vector<int> a(n + 1, 0),b(n + 1, 0), dp(n + 1, 0), s(n + 1, 0);
		int a, b;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i] >> b[i];
		}
		s[1] = a[1]-b[1];
		for (int i = 2; i <= n; ++i) {
			if (abs(s[i]) > abs(s[i - 1] + span[i])) {
				s[i] = s[i - 1] + span[i];
				dp[i] = dp[i - 1] + 1;
			}
		}
		cout << dp[n] << endl;
	}
	system("pause");
}