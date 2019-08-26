//  八皇后
#include<iostream>
#include<cstring>
using namespace std;
int n;
int path[100][8];
int tot = 0;
int c[8];
void search(int cur) {
	if (cur == 8) {
		++tot;
		for (int i = 0; i < 8; i++) {
			path[tot][i] = c[i];
		}	
	}
	else for (int i = 1; i <= 8; i++) {
		int ok = 1;
		c[cur] = i;
		for (int j = 0; j < cur; j++) {
			if (c[cur] == c[j] || cur + c[cur] == j + c[j] || cur - c[cur] == j - c[j]) { ok = 0; break; }
		}
		if (ok)
			search(cur + 1);
	}
}
int main() {
	memset(c, 0, sizeof(c));
	search(0);
	while (cin >> n) {
		for (int i = 0; i < 8; i++)
			cout << path[n][i];
		cout << endl;
		
	}
}