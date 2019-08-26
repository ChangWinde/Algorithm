//  UVA129 困难的串 Krypton Factor
// 不通过 但是找不到问题
#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int res[300];
int n, l;
int cnt;

bool dfs(int cur) {
	if (cnt++ == n) {
		for (int i = 0; i < cur; ++i) {
			if (i&&(i % 64 == 0))
				printf("\n");
			else if(i&&(i % 4 == 0)){
				printf(" ");
			}
			printf("%c", res[i] + 'A');
		}
		printf("\n%d\n",cur);
		return true;
	}
	else for (int i = 0; i < l; ++i) {
		res[cur] = i;
		int ok = 1;
		for (int j = 1; 2 * j <= cur + 1; ++j) {
			int equal = 1;
			for (int k = 0; k < j; ++k)
				if (res[cur - k] != res[cur - j - k]) { equal = 0; break; }
			if (equal) { ok = 0; break; }
		}
		if (ok) {
			if (dfs(cur + 1))return true;
		}
	}
	return 0;
}

int main() {

	while (cin >> n >> l && n&&l) {
		res[0] = 0;
		cnt = 1;
		dfs(1);
	}
	system("pause");
}