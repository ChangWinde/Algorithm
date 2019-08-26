//  POJ-1985 Cow Marathon
//  http://poj.org/problem?id=1985
#include<iostream>
#include<queue>
using namespace std;
const int maxn = 1e5 + 5;
const int maxint = 0x3f3f3f3f;
int tot,head[maxn];
int dis[maxn];
int n, m;
bool vis[maxn];
struct node {
	int to, w, next;
}nodes[maxn*2];

void addNode(int u, int v, int d) {
	tot++;
	nodes[tot].to = v;
	nodes[tot].w = d;
	nodes[tot].next = head[u];
	head[u] = tot;
}
void bfs(int s) {
	for (int i = 0; i <= n; i++)dis[i] = maxint;
	queue<int> q;
	q.push(s);
	dis[s] = 0;
	while (!q.empty()) {
		int cur = q.front(); q.pop();
		for (int i = head[cur]; i; i = nodes[i].next) {
			int y = nodes[i].to;
			if (dis[y] > dis[cur] + nodes[i].w) {
				dis[y] = dis[cur] + nodes[i].w;
				q.push(y);
			}
		}
	}
}
int sol() {
	bfs(1);
	int ans = 0, e = 0;
	for (int i = 0; i <= n; i++) {
		if (dis[i] == maxint)continue;
		if (dis[i] > ans) {
			ans = dis[i]; e = i;
		}
	}
	bfs(e);
	for (int i = 0; i <= n; i++) {
		if (dis[i] == maxint)continue;
		ans = max(ans, dis[i]);
	}
	return ans;
}
int main() {
	int u, v, d;
	char s;
	while (cin >> n >> m) {
		tot = 0;
		memset(vis, false, sizeof(vis));
		for (int i = 1; i <= m; i++) {
			cin >> u >> v >> d >> s;
			addNode(u, v, d); 
			addNode(v, u, d);
		}
		cout <<sol() <<endl;
	}

}