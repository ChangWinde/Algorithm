//  输入n个整数，输出其中最小的k个
//  输入n个整数，输出其中最小的k个。
//  https://www.nowcoder.com/practice/69ef2267aafd4d52b250a272fd27052c?tpId=37&tqId=21281&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=3

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void swap(int&a, int&b) {
	int t = a;
	a = b;
	b = t;
}
int partition(vector<int>& v, int l, int r) {
	int stand = v[l];
	int i = l, j = r + 1;
	while (1) {
		while (v[++i] < stand)
			if (i == r)
				break;
		while (v[--j] > stand)
			if (j == l)
				break;
		if (i >= j)
			break;
		swap(v[i], v[j]);
	}
	swap(v[j], v[l]);
	return j;
}
void qS(vector<int>& v, int l, int r) {
	if (l >= r)
		return;
	int mid = partition(v, l, r);
	qS(v, l, mid - 1);
	qS(v, mid + 1, r);
}
int main() {
	int num1, num2;
	while (cin >> num1 >> num2) {
		vector<int> res(num1, 0);
		int i = 0;
		while (num1--) {
			cin >> res[i++];
		}
		qS(res,0,res.size()-1);
		for (i = 0; i < num2; ++i)
			cout << res[i] << " ";
		cout << endl;
	}
}