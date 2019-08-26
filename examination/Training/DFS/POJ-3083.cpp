//  POJ-3083 Children of the Candy Corn
//  超时
#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std;
char maze[45][45];
int test, w, h;
int sx, sy, dx, dy;
int dl[][2] = { 0,-1,-1,0,0,1,1,0 };
int dr[][2] = { 0,1,-1,0,0,-1,1,0 };
int ans;
bool flag = true;
struct pos
{
	int x, y, s;
};
queue<pos> q;
//dfs找到第一个解的时候，如何更高效的直接返回？？
void dfs(int x, int y, int mode) {
	if (flag)return;
	if (maze[x][y] == 'E') {
		flag = true;
		printf("%d ", ans);
		return;
	}
	else {
		for (int i = 0; i < 4; ++i) {
			int nx, ny;
			if (mode == 0) {
				nx = x + dl[i][0], ny = y + dl[i][1];
			}
			else {
				nx = x + dr[i][0], ny = y + dr[i][1];
			}
			if (nx >= 1 && nx <= h && ny >= 1 && ny <= w && maze[nx][ny] == '.') {
				maze[nx][ny] = '#';
				ans++;
				dfs(nx, ny, mode);
				maze[nx][ny] = '.';
				ans++;
			}
		}
	}
}

void bfs(int x, int y) {
	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dl[i][0], ny = y + dl[i][1];
			if (nx >= 1 && nx <= h && ny >= 1 && ny <= w) {
				if (maze[nx][ny] == 'E') {
					printf("%d\n", now.s + 1);
					return;
				}
				if (maze[nx][ny] == '.') {
					maze[nx][ny] = '#';
					q.push(pos{ nx,ny,now.s + 1 });
				}
			}
		}
	}
}

int main() {
	scanf_s("%d", &test);
	while (test--) {
		scanf_s("%d%d", &w, &h);
		for (int i = 1; i <= h; ++i) {
			for (int j = 1; j <= w; ++j) {
				scanf_s("%c", maze[i][j]);
				if (maze[i][j] == 'S') {
					sx = i; sy = j;
				}
				if (maze[i][j] == 'E') {
					dx = i; dy = j;
				}
			}
		}
		ans = 1;
		dfs(sx, sy, 0);
		ans = 1;
		dfs(sx, sy, 1);
		ans = 1;
		q.push(pos{ sx, sy, 1 });
		maze[sx][sy] = '#';
		bfs(sx, sy);
	}
}