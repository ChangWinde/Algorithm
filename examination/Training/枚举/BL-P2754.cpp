//  百炼2754:八皇后

#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int n = 8;
int c[14];
int res,pos;
bool flag;
void solve(int curr) {
	if (flag)return;
	if (curr == n) {
		++res;
		if (res == pos) {
			for (int i = 0; i < n; ++i)
				printf("%d", c[i]);
			printf("\n");
			flag = true;
		}
	}
	else for (int i = 1; i <= n; ++i) {
		int ok = 1;
		c[curr] = i;
		for (int j = 0; j < curr; ++j)if (c[curr] == c[j] || curr + c[curr] == j + c[j] || curr - c[curr] == j - c[j]) {
			ok = 0;
			break;
		}
		if (ok) { solve(curr + 1); }
	}

}

int main() {
	int test;
	scanf_s("%d", &test);
	while (test--) {
		scanf_s("%d", &pos);
		res = 0; 
		flag = false;
		solve(0);
	}
	system("pause");
}