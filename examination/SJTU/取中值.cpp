//  取中值
#include<iostream>
#include<algorithm>
using namespace std;
#define MAX 1000000+5
int A[MAX], B[MAX];

int main() {
	int a1, a2;
	scanf("%d%d", &a1, &a2);
	for (int i = 1; i <= a1; ++i)
		scanf("%d ", &A[i]);
	for (int i = 1; i <= a2; ++i)
		scanf("%d ", &B[i]);
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	int index = (b - a + d - c + 2);
	index = index / 2 + index % 2;
    int res;
    if(b-a+1<index){
        res = B[c+index-(b-a+1)-1];
    }else if(b-a+1>index){
        res = A[a+index-1];
    }else{
        res = A[b];
    }
	printf("%d\n", res);
}