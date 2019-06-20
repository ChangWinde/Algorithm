//  数塔
//  http://acm.hdu.edu.cn/showproblem.php?pid=2084

#include<iostream>
#include<algorithm>

using namespace std;
int* a;
int s;
int const MAXN = 100 + 5;
int note[MAXN][MAXN];

int tower(int i, int j) {
	int index = i * (i + 1) / 2 + j;
	if (index > s)
		return a[index - i-1];
	else {
		if (note[i + 1][j] < 0)
			note[i + 1][j] = tower(i + 1, j);
		if (note[i + 1][j + 1]<0)
			note[i + 1][j + 1] = tower(i + 1, j + 1);
		return a[index - i - 1] + max(note[i + 1][j], note[i + 1][j + 1]);
	}	
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		int line;
		cin>>line;
		s = (line + 1)*line / 2;
		a = new int[s];
		memset(note, -1, sizeof(note));
		for (int i = 0; i < s; ++i)
			cin>>a[i];
		cout << tower(1,1) << endl;
	}
}