//  P1605 迷宫
#include<stdio.h>
#include<cstring>
using namespace std;
bool g[6][6];
int n, m, t;
int sx, sy, dx, dy;
int dr[][2] = { -1,0,1,0,0,-1,0,1 };
int ans = 0;
void dfs(int x, int y) {
	if (x == dx && y == dy) {
		++ans;
		return;
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int nx = x + dr[i][0], ny = y + dr[i][1];
			if (nx >= 1 && x <= n && y >= 1 && y <= m && g[nx][ny]) {
				g[x][y] = 0;
				dfs(nx, ny);
				g[x][y] = 1;
			}
		}
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d%d", &sx, &sy, &dx, &dy);
	memset(g, 1, sizeof(g));
	for (int i = 0; i < t; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a][b] = 0;
	}
	g[sx][sy] = 0;
	dfs(sx,sy);
	printf("%d\n",ans);
}