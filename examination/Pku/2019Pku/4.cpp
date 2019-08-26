//  http://bailian.openjudge.cn/xly2019/D/
#include<iostream>
#include<cstring>
using namespace std;
int n, k;
int death[51] = { 0 };
long long res[51];
void init() {
	death[4] = -1;death[14] = -1;death[24] = -1;death[34] = -1;
	for (int i = 0; i < 10; i++) {
		death[40 + i] = -1;
	}
}
bool check(int x) { return death[x] == 0; }
int leap() {
	memset(res, 0, sizeof(res));
	res[0] = 1; res[1] = 1;
	for (int i = 2; i <= k; i++) {
		for (int j = 0; j < i; j++)
			if(check(i-j))
				res[i] += res[j];
	}
	for (int i = k + 1; i <= n; i++) {
		for(int j = i-k;j<i;j++)
			if (check(i - j))
				res[i] += res[j];
	}
	return res[n];
}
int main() {
	init();
	while (cin >> n >> k && n&&k) {
		cout << leap()<<endl;
	}
}