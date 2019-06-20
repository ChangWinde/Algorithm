//  P1091 合唱队形
//  线性动规

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	while (cin >> N && N) {
		vector<int> h(N + 1, 0);
		for (int i = 1; i <= N; ++i)
			cin >> h[i];
		vector<int> I(N + 1, 1), D(N + 1, 1);
		for (int i = 2; i <= N; ++i) {
			for (int j = 1; j <= i - 1; ++j) {
				if (h[i] > h[j])
					I[i] = max(I[i], I[j] + 1);
			}
			for (int j = N; j >= N + 2 - i; --j) {
				if (h[N + 1 - i] > h[j])
					D[N + 1 - i] = max(D[N + 1 - i], D[j] + 1);
			}
		}
		int ans = -1;
		for (int i = 1; i <= N; ++i) {
			ans = max(ans, D[i] + I[i]-1);
		}
		cout << N - ans << endl;
	}
	system("pause");
}