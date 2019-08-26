//  Highways POJ - 2485
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int n,t[505];
struct node{
	int x, y, cost;
	node() {}
	node(int a, int b, int c) { x = a; y = b; cost = c; }
	bool operator<(const node& x)const { return x.cost < cost; }
};
int findRoot(int x) {
	if (t[x] == x)return x;
	else return t[x] = findRoot(t[x]);
}
bool merge(int x, int y) {
	int a = findRoot(x), b = findRoot(y);
	if (a != b) {
		t[a] = b;
		return true;
	}
	return false;
}
int sol() {
	priority_queue<node> q;
	int d;
	for (int i = 0; i <= n; i++) {t[i] = i; }
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> d;
			if (j>=(i+1)) {
				node temp(i, j, d);
				q.push(temp);
			}
		}
	}
	int ans = 0;
	while (q.size()) {
		node cur = q.top(); q.pop();
		if (merge(cur.x, cur.y)) {
			ans = max(ans,cur.cost);
		}
	}
	return ans;
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		cin >> n;
		cout << sol() << endl;
	}
}
