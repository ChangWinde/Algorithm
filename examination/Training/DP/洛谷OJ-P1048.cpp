//  P1048 采药

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int T, n;
	while (cin >> T >> n && T&&n) {
		vector<int> t(n + 1, 0), w(n + 1, 0);
		for (int i = 1; i <= n; ++i)
			cin >> t[i] >> w[i];
		vector<int> dp(T + 1, 0);
		for (int i = 1; i <= n; ++i) {
			for (int j = T; j >= 0; --j) {
				if (j >= t[i])
					dp[j] = max(dp[j], dp[j - t[i]] + w[i]);
			}
		}
		cout << dp[T] << endl;
	}
	//system("pause");
}