//  Who's in the Middle
//  http://poj.org/problem?id=2388
//  线性选择
#include<iostream>
using namespace std;
int n, a[10005];

int partition(int* a,int l,int r) {
	int i = l, j = r + 1;
	int stand = a[l];
	while (1) {
		while (a[++i] < stand) {
			if (i == r)break;
		}
		while (a[--j] > stand) {
			if (j == l)break;
		}
		if (i >= j)break;
		swap(a[i], a[j]);
	}
	swap(a[l], a[j]);
	return j;
}
int search(int*a, int l, int r,int k) {
	if (l >= r)return a[l];
	int mid = partition(a, l, r);
	int q = mid - l + 1;
	if (q == k)return a[mid];
	else if (q > k)return search(a, l, mid-1, k);
	else if (q < k)return search(a, mid + 1, r, k - q);
}
int main() {
	while (cin >> n) {
		for (int i = 0; i < n; i++)cin >> a[i];
		cout <<search(a,0,n-1,n/2+1) << endl;
	}
}