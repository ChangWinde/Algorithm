//  http://bailian.openjudge.cn/xly2019/A/
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int q[6] = { 9,99,999,9999,99999,999999 };
int cal() {
	int k = lower_bound(q, q + 6, n)-q;
	if (k == 0)
		return n;
	else
		return q[k - 1];
}

int main() {
	while (cin >> n && n) {
		cout << cal() << endl;
	}
}