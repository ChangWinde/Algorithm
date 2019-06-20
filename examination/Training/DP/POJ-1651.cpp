//  最优矩阵链乘
//  http://poj.org/problem?id=1651

#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 0x7fffffff
using namespace std;
/*
f(i,j)表示(M_i*M_(i+1)*...*M_k)*(M_(k+1)*...*M_j)乘法次数
f(i,j) = f(i,k)+f(k+1,j)+P_i*P_(k+1)*P_j {k in [i,j]}
f(i,i) = 0
本题目第一层循环应该按照长度迭代，首先计算长度为1的，然后一直计算到长度为n的
     第二层循环按照各个位置循环，j+len-1为末尾位置
*/
int main() {
	int n;
	while (cin >> n && n) {
		vector<int> A(n, 0);
		for (int i = 0; i < n; ++i) {
			cin >> A[i];
		}
		vector<vector<int>> dp(n - 1, vector<int>(n - 1, MAX));
		for (int i = 1; i <= n - 1; ++i) {
			for (int j = 0; j + i <= n - 1; ++j) {
				if (i == 1)
					dp[j][i + j - 1] = 0;
				else {
					for (int k = j; k + 1 < j + i; ++k) {
						dp[j][i + j - 1] = min(dp[j][i + j - 1], dp[j][k] + dp[k + 1][j + i - 1] + A[j] * A[k + 1] * A[j + i]);
					}
				}
			}
		}
		cout << dp[0][n - 2] << endl;
	}
	//system("pause");
}