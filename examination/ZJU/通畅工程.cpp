//  通畅工程
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct edge {
	int x, y, s;
	bool operator<(edge p) {
		return s < p.s;
	}
}edges[105];
int n, m;
int t[105];
int sum[105];
int res;
int findRoot(int x) {
	if (t[x] == -1)
		return x;
	else {
		int temp = findRoot(t[x]);
		t[x] = temp;
		return temp;
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
	while (cin >> n >> m) {
		if (!n)break;
		res = 0;
		memset(t, -1, sizeof(t));
		for (int i = 1; i <= m; i++)
			sum[i] = 1;
		for (int i = 1; i <= n; ++i) {
			cin >> edges[i].x >> edges[i].y >> edges[i].s;
		}
		sort(edges + 1, edges + n + 1);
		int cost = 0;
		for (int i = 1; i <= n; i++) {
			if (merge(edges[i].x, edges[i].y)) {
				cost += edges[i].s;
			}
		}
		if (res == m)
			cout << cost << endl;
		else
			cout << "?" << endl;
	}
}