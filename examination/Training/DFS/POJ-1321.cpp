//  POJ - 1321
//  https://vjudge.net/problem/POJ-1321
#include<iostream>
using namespace std;
int n, k;
int tot,head[9],cnt;
struct node {
	int x,y,next;
	bool vis;
}nodes[65];
void addNode(int x, int y) {
	tot++;
	nodes[tot].x = x;
	nodes[tot].y = y;
	nodes[tot].vis = false;
	nodes[tot].next = head[x];
	head[x] = tot;
}
int res[10], row[10];
bool check(int k,int cur) {
	for (int i = 0; i < cur; i++)
		if (nodes[k].x<= nodes[res[i]].x||nodes[k].y == nodes[res[i]].y)return false;
	return true;
}
void dfs(int cur,int row) {
	if (cur == k) {
		cnt++;
	}
	else {
		for (int i = row; i <= n; i++) {
			for (int k = head[i]; k; k = nodes[k].next) {
				if (!nodes[k].vis&&check(k, cur)) {
					nodes[k].vis = true;
					res[cur] = k;
					dfs(cur + 1,row+1);
					nodes[k].vis = false;
				}
			}
		}
	}
}
int main() {
	while (cin >> n >> k) {
		if (n == -1 && k == -1)break;
		memset(head, 0, sizeof(head));
		tot = 0;
		cnt = 0;
		char q;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> q;
				if (q == '#')addNode(i, j);
			}
		}
		dfs(0,1);
		cout << cnt <<endl;
	}
}