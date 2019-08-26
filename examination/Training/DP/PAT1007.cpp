// https://pintia.cn/problem-sets/994805342720868352/problems/994805514284679168
// 1007 Maximum Subsequence Sum
#include <iostream>
#include <vector>
using namespace std;
int n;
int v[10005];
int sum, r, l;
void sol() {
	l = 0, r = n - 1, sum = -1;
	int temp = 0, tempindex = 0;
	for (int i = 0; i < n; i++) {
		cin>>v[i];
		temp = temp + v[i];
		if (temp < 0) {
			temp = 0;
			tempindex = i + 1;
		}
		else if (temp > sum) {
			sum = temp;
			l = tempindex;
			r = i;
		}
	}
	if (sum < 0) sum = 0;
}
int main() {
	cin >> n;
	sol();
	printf("%d %d %d", sum, v[l], v[r]);
}