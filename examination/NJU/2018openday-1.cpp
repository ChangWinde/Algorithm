// 最大子矩阵
#include<iostream>
#include<cstring>
#include<algorithm>
#define MIN 0xbf3f3f3f
using namespace std;
int n;
int g[105][105];

int main() {
	while (cin >>n) {
		memset(g, 0, sizeof(g));
		int t;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; j++) {
				cin >> t;
				g[i][j] = t + g[i - 1][j] + g[i][j - 1] - g[i - 1][j - 1];
			}
		}
		int ans = MIN;
		for (int x = 1; x <= n; x++) {
			for (int y = 1; y <= n; y++) {
				for (int i = x; i <= n; i++) {
					for (int j = y; j <= n; j++) {
						ans =  max(ans,g[i][j]-g[x-1][j]-g[i][y-1]+g[x-1][y-1]);
					}
				}
			}
		}
		cout << ans << endl;
	}
}