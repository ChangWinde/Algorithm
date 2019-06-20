//  P1060 开心的金明
// 01背包问题

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int m, n;
	while (cin >> m >> n && m&&n) {
		vector<int> v(n+1, 0), w(n+1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> v[i] >> w[i];
			w[i] *= v[i];
		}
		vector<vector<int> > dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= m; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (j >= v[i]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i]] + w[i]);
				}
			}
		}
		cout << dp[n][m] << endl;
	}
	system("pause");
}
