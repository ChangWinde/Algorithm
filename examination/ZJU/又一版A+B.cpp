//  又一版A+B
#include<stdio.h>
using namespace std;
typedef long long ll;
int m;
ll a, b;
void cal(ll a, ll b) {
	ll temp = a + b;
	char p[12];
	int size = 0;
	do {
		p[size++] = (int)(temp % m)+'0';
		temp /= m;
	} while (temp != 0);
	for (int i = size - 1; i >= 0; --i)
		printf("%c", p[i]);
	printf("\n");
}
int main() {
	while (scanf_s("%d%lld%lld", &m, &a, &b) && m) {
		cal(a, b);
	}
}