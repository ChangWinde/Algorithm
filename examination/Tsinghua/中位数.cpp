//  中位数
#include<stdio.h>
#include<algorithm>
#define MAX 10000+5
using namespace std;

int a[MAX];
int n;
int partition(int*a,int l,int r){
	int i = l,j = r+1;
	int stand = a[l];
	while(1){
		while(a[++i]<stand)if(i==r)break;
		while(a[--j]>stand)if(j==l)break;
		if(i>=j)break;
		swap(a[i],a[j]);
	}
	swap(a[j],a[l]);
	return j;
}
int search(int*a, int l, int r, int k) {
	if (l == r)return a[l];
	int mid = partition(a, l, r);
	int q = mid - l + 1;
	if (q == k)
		return a[mid];
	else if (q > k)
		return search(a, l, mid - 1, k);
	else
		return search(a, mid + 1, r, k - q);
}

int main() {
	while (scanf_s("%d", &n)!=EOF && n) {
		for (int i = 1; i <= n; ++i)
			scanf_s("%d", &a[i]);
		if (n % 2 == 0)
			printf("%d\n", (search(a, 1, n, n / 2) + search(a, 1, n, n / 2 + 1)) / 2);
		else
			printf("%d\n", search(a, 1, n, n / 2 + 1));
	}
}