//  Oil Deposits
//  http://acm.hdu.edu.cn/showproblem.php?pid=1241
//  使用DFS求连通块

#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int MAX = 100 + 5;
int idx[MAX][MAX];
char oil[MAX][MAX];
int m, n;

void dfs(int x, int y, int id) {
	if (x<0 || x>=m || y<0 || y>=n) 
		return;
	if (oil[x][y] != '@'|| idx[x][y]>0)
		return;
	oil[x][y] = id;
	for (int i = -1; i < 2; ++i) {
		for (int j = -1; j < 2; ++j) {
			if (!(i == 0 && j == 0))
				dfs(x+i, y+j, id);
		}
	}
}

int main() {
	while (cin>>m>>n&&m&&n) {
		for (int i = 0; i < m;++i)
			cin>>oil[i];
		memset(idx, 0, sizeof(idx));
		int cnt = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j) {
				if(idx[i][j]==0&&oil[i][j] =='@')
					dfs(i, j, ++cnt);
			}
		cout << cnt << endl;
	}
	return 0;
}