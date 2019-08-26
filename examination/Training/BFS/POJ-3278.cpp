//  Catch That Cow
//  http://poj.org/problem?id=3278
//  注意要先判断有没有抓住牛，因为n,k有可能相等

#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define Bp 100000
int n, k;
int dr[3] = { 1,-1,0 };
bool vis[100005];
struct node {
	int pos, count;
	node() {}
	node(int p, int c) { pos = p; count = c; }
};
int bfs() {
	memset(vis, false, sizeof(vis));
	queue<node> q;
	node temp(n, 0);
	q.push(temp);
	vis[n] = true;
	while (!q.empty()) {
		node cur = q.front(); q.pop();
		if (cur.pos == k) {
			return cur.count;
		}
		dr[2] = cur.pos;
		for (int i = 0; i < 3; i++) {
			int nx = dr[i] + cur.pos;
			if (nx >= 0 && nx <= Bp&&!vis[nx]) {
				vis[nx] = true;
				node tep(nx, cur.count + 1);
				q.push(tep);
			}
		}
	}
	return -1;
}

int main() {
	while (cin >> n >> k) {
		cout << bfs() << endl;
	}
}