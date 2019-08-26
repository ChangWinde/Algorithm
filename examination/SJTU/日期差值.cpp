#include<stdio.h>
#include<iostream>
using namespace std;

int date[5000][12][31];
int month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
bool isgap(int y) {
	return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) ? true : false;
}
void init() {
	int ans = 0;
	for (int i = 0; i < 5000; i++) {
		if (isgap(i))
			month[2] = 29;
		else
			month[2] = 28;
		for (int j = 0; j < 12; j++) {
			int end = month[j + 1];
			for (int k = 0; k < end; k++)
				date[i][j][k] = ans++;
		}
	}
}
int y, m, d;
int main() {
	init();
	while (scanf("%4d%2d%2d", &y, &m, &d) != EOF) {
		int temp = date[y][m - 1][d-1];
		scanf("%4d%2d%2d", &y, &m, &d);
		printf("%d\n", date[y][m - 1][d-1] - temp + 1);
	}
}