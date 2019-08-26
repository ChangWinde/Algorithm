// LCA
#include<iostream>
using namespace std;
const int maxn = 5e5 + 5;
const int maxm = 1e6 + 5;
int tot,head1[maxn], head2[maxn], res[maxn], t[maxn];
bool vis[maxn];
int n,m, s, u, v;
struct {
	int to, next;
}path1[maxm],path2[maxm];

void addPath1(int u, int v) {
	tot++;
	path1[tot].to = v;
	path1[tot].next = head1[u];
	head1[u] = tot;
}
void addPath2(int u, int v) {
	tot++;
	path2[tot].to = v;
	path2[tot].next = head2[u];
	head2[u] = tot;
}
int findRoot(int k) {
	if (t[k] == k)return k;
	else return t[k] = findRoot(t[k]);
}
void dfs(int k) {
	vis[k] = true;
	int son = head1[k];
	while (son > 0) {
		if (!vis[path1[son].to]) {
			dfs(path1[son].to);
			t[path1[son].to] = k;
		}
		son = path1[son].next;
	}
	son = head2[k];
	while (son > 0) {
		if (vis[path2[son].to]) {
			res[(son + 1) >> 1] = findRoot(path2[son].to);
		}
		son = path2[son].next;
	}
}
//树有n个节点，m次询问，s是根节点
//前n-1个（u，v）表示树上u，v之间有连接
//后m个（u，v）表示树上u，v之间的最近公共祖先
int main() {
	cin >> n >> m >> s;
	tot = 0;
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		addPath1(u, v), addPath1(v, u);
	}
	tot = 0;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v;
		addPath2(u, v), addPath2(v, u);
	}
	for (int i = 0; i < n; i++)t[i] = i;
	dfs(s);
	for (int i = 1; i <= m; i++)cout << res[i] << endl;
}