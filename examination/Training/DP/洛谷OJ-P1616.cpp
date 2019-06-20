//  P1616 疯狂的采药
//  完全背包

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T, n;
	while (cin >> T >> n && T&& n) {
		vector<int> t(n + 1, 0), v(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			cin >> t[i] >> v[i];
		}
		vector<int> dp(T + 1, 0);
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j <= T; ++j) {
				if (j >= t[i])
					dp[j] = max(dp[j], dp[j - t[i]] + v[i]);
			}
		}
		cout << dp[T] << endl;
	}
	system("pasue");
}