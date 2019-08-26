//  质因数的个数

#include<stdio.h>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define MAXN 40000
int prime[MAXN];
bool mark[MAXN];
int sizeP;
void init() {
	sizeP = 0;
	memset(mark, false, sizeof(mark));
	for (int i = 2; i < MAXN; ++i) {
		if (mark[i])
			continue;
		prime[sizeP++] = i;
		for (int j = i * i; j < MAXN; j+=i)
			mark[j] = true;
	}
}
int n;
int main() {
	init();
	while (scanf_s("%d", &n) != EOF) {
		int ans = 0;
		int size = sqrt(n)+5;
		for (int i = 0; i < sizeP && prime[i]<size; i++) {
			while (n%prime[i] == 0) {
				n /= prime[i];
				ans++;
			}
		}
		if (n != 1)
			ans++;
		printf("%d\n", ans);
	}
	system("pause");
}