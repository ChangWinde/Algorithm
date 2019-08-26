//  
//  
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n && n) {
		vector<int> A(n);
		for (int i = 0; i < n; ++i)
			cin >> A[i];
		vector<int> g(n+1, INT_MAX), dp(n, 1);
		int ans = -1;
		for (int i = 0; i < n; ++i) {
			int k = lower_bound(g.begin()+1, g.end(), A[i]) - g.begin();
			dp[i] = k;
			g[k] = A[i];
			ans = (ans < dp[i])?dp[i]:ans;
		}
		cout << ans<<endl;
	}
	//system("pause");
}