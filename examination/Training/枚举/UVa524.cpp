//  UVA524 素数环 Prime Ring Problem

#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int prime[] = { 2,3,5,7,11,13,17,19,23,29,31 };
bool v[17];
int a[17];
int n;
bool isp(int x) {
	for (int i = 0; i < 11; ++i)if (prime[i] == x)return true;
	return false;
}
void solve(int curr) {
	if (curr == n && isp(a[0] + a[n - 1])) {
		for (int i = 0; i < n - 1; ++i)
			printf("%d ", a[i]);
		printf("%d\n", a[n - 1]);
	}
	else for (int i = 2; i <= n; ++i) {
		if (v[i] && isp(i + a[curr - 1])) {
			a[curr] = i;
			v[i] = false;
			solve(curr + 1);
			v[i] = true;
		}
	}
}
int main() {
	int cas = 0;
	while (cin>>n) {
		memset(v, true, sizeof(v));
		if (cas)
			printf("\n");
		printf("Case %d:\n", ++cas);
		a[0] = 1;
		solve(1);
	}
}