//  全排列
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
char str[7];
char a[7];
int s;
int q[100];
void printAll(int cur) {
	if (cur == s) {
		for (int i = 0; i < s; ++i)
			printf("%c", a[i]);
		printf("\n");
	}
	else for (int i = 0; i < s; ++i) {
		int ok = 1;
		for (int j = 0; j < cur; j++)if (str[i] == a[j]) {
			ok = 0;
			break;
		}
		if (ok) {
			a[cur] = str[i];
			printAll(cur + 1);
		}
	}
}

int main() {
	cin>>str;
	s = strlen(str);
	sort(str, str + s);
	printAll(0);
    printf("\n");
}