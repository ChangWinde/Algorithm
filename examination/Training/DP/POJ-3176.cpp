//  Cow Bowling
//  http://poj.org/problem?id=3176

#include<iostream>
#include<algorithm>
using namespace std;
int n, dp[355][355];
int sol() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)cin >> dp[i][j];
	for (int i = n-1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
		}
	}
	return dp[1][1];
}
int main() {
	while (cin >> n) {
		cout << sol() << endl;
	}
}