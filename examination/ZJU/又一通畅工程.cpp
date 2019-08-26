//  又一通畅工程
// 最小生成树

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int res;
int sum[105];
int t[105];
struct e {
	int x, y, s, id;
	bool operator<(e& y) {
		if (id == y.id) {
			return s < y.s;
		}
		else if (id < y.id) {
			return false;
		}
		else {
			return true;
		}
	}
}es[5050];
int findRoot(int x) {
	if (t[x] == -1)
		return x;
	else {
		int te = findRoot(t[x]);
		t[x] = te;
		return te;
	}
}
bool merge(int x, int y) {
	int a = findRoot(x);
	int b = findRoot(y);
	if (a != b) {
		t[a] = b;
		sum[b] += sum[a];
		res = sum[b];
		return true;
	}
	return false;
}

int main() {
	while (cin >> n) {
		if (!n)break;
		memset(t, -1, sizeof(t));
		int m = n * (n - 1) / 2;
		for (int i = 0; i <= n; i++) {
			sum[i] = 1;
		}
		for (int i = 1; i <= m; ++i) {
			cin >> es[i].x >> es[i].y >> es[i].s >> es[i].id;
		}
		sort(es + 1, es + m + 1);
		int cost = 0;
		for (int i = 1; i <= m; i++) {
			if (merge(es[i].x, es[i].y) && !es[i].id) {
				cost += es[i].s;
			}
			if (res == n)
				break;
		}
		cout << cost << endl;
	}
}