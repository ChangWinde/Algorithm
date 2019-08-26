//  POJ 2488 A Knight's Journey (DFS)

#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int dr[][2] = {
	-2,-1,
	-2,1,
	-1,-2,
	-1,2,
	1,-2,
	1,2,
	2,-1,
	2,1 };
bool v[27][27];
int path[27][2];
int n, p, q;
int block;
bool dfs(int x, int y) {
	if (block == p * q) {
		return true;
	}
	else {
		for (int i = 0; i < 8; ++i) {
			int nx = x + dr[i][0], ny = y + dr[i][1];
			if (nx>=1&&nx<=q&&ny>=1&&ny<=p&&v[nx][ny]) {
				v[nx][ny] = false;
				block++;
				path[block][0] = nx - 1;
				path[block][1] = ny;
				if (dfs(nx, ny))return true;
				v[nx][ny] = true;
				block--;
			}
		}
	}
	return false;
}
void printAns() {
	int size = q * p;
	for (int i = 1; i <= size; ++i) {
		printf("%c%d", 'A' + path[i][0], path[i][1]);
	}
	printf("\n\n");
}
int main() {
	scanf_s("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf_s("%d%d", &p, &q);
		memset(v, true, sizeof(v));
		block = 1;
		v[1][1] = false;
		path[1][0] = 0;
		path[1][1] = 1;
		printf("Scenario #%d:\n", i);
		if (dfs(1, 1)) {
			printAns();
		}
		else {
			printf("impossible\n\n");
		}
	}
	//system("pause");
}