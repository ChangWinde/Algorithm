//  P1443 马的遍历

#include <stdio.h>
#include<cstring>
#include<queue>
using namespace std;
#define MAXN 400+5

struct pos
{
	int x, y, step;
	pos(int _x, int _y, int _s) { x = _x, y = _y, step = _s; }
	pos() {}
};
bool mark[MAXN][MAXN];
int res[MAXN][MAXN];
int n, m, a, b;
int gap[][2] = {
	-2,-1,
	-2,1,
	-1,-2,
	-1,2,
	2,-1,
	2,1,
	1,-2,
	1,2
};
queue<pos> q;

void bfs() {
	while (!q.empty()) {
		pos now = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i) {
			int tx = now.x + gap[i][0], ty = now.y + gap[i][1];
			if ((tx < 1 || tx > n) || (ty < 1 || ty > m))continue;
			if (!mark[tx][ty]) {
				q.push(pos(tx, ty, now.step + 1));
				res[tx][ty] = now.step + 1;
				mark[tx][ty] = true;
			}
		}
	}
}

int main() {
	scanf_s("%d%d%d%d", &n, &m, &a, &b);
	memset(mark, false, sizeof(mark));
	memset(res, -1, sizeof(res));
	pos temp(a, b, 0);
	q.push(temp);
	res[a][b] = 0;
	mark[a][b] = true;//初始状态一定要更新他
	bfs();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			printf("%-5d", res[i][j]);
		}
		printf("\n");
	}
	system("pause");
}