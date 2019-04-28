//  超长正整数相加
//  请设计一个算法完成两个超长正整数的加法。
//  https://www.nowcoder.com/practice/5821836e0ec140c1aa29510fd05f45fc?tpId=37&tqId=21301&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=4

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		string res;
		int i = s1.size()-1, j = s2.size()-1;
		int add = 0;
		for (; j >= 0 && i >= 0; --j, --i) {
			add += (s1[i] - '0') + (s2[j] - '0');
			res = to_string(add % 10) + res;
			add /= 10;
		}
		if (i >= 0) {
			while (i >= 0 && add != 0) {
				add += (s1[i] - '0');
				res = to_string(add % 10) + res;
				add /= 10;
				--i;
			}
			if (add != 0)
				res = "1" + res;
			while (i >= 0) {
				res = s1[i] + res;
				--i;
			}
		}
		if (j >= 0) {
			while (j >= 0 && add != 0) {
				add += (s2[j] - '0');
				res = to_string(add % 10) + res;
				add /= 10;
				--j;
			}
			while (j >= 0) {
				res = s2[j] + res;
				--j;
			}
		}
		cout << res << endl;
	}
}