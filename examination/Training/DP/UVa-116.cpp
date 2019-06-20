//  Unidirectional TSP
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=52

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

int col, row;

void solve(int row, int col) {
	//输入数据
	vector<vector<int> > a(row, vector<int>(col, 0));
	for (int i = 0; i < row; ++i)
		for (int j = 0; j < col; ++j)
			cin >> a[i][j];
	//处理数据
	vector<vector<int> > dp(row, vector<int>(col, 0)), next(row, vector<int>(col, 0));
	int ans = INT_MAX, first;
	for (int j = col - 1; j >= 0; --j) {
		for (int i = 0; i < row; ++i) {
			if (j == col - 1) dp[i][j] = a[i][j];
			else {
				int dr[3] = { i - 1,i,i + 1 };//下一个状态的三个方向
				if (i == 0) dr[0] = row - 1;
				if (i == row - 1) dr[2] = 0;
				sort(dr, dr + 3);
				dp[i][j] = INT_MAX;
				for (int k = 0; k < 3; ++k) {
					int v = a[i][j] + dp[dr[k]][j + 1];
					if (v < dp[i][j]) {
						dp[i][j] = v;
						next[i][j] = dr[k];
					}
				}
			}
			if (j == 0 && ans > dp[i][j]) {
				ans = dp[i][j];
				first = i;
			}
		}
	}
	cout << first + 1 << " ";
	for (int i = next[first][0],j = 1; j < col; i = next[i][j], ++j)
		cout << i + 1 << " ";
	cout << "\n" << ans << endl;
}
int main() {
	while (cin >> row >> col) {
		solve(row, col);
	}
}
