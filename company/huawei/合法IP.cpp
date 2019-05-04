//  合法IP
//  现在IPV4下用一个32位无符号整数来表示，一般用点分方式来显示，点将IP地址分成4个部分，每个部分为8位，表示成一个无符号整数（因此不需要用正号出现），如10.137.17.1，是我们非常熟悉的IP地址，一个IP地址串中没有空格出现（因为要表示成一个32数字）。现在需要你用程序来判断IP是否合法。
//  https://www.nowcoder.com/practice/995b8a548827494699dc38c3e2a54ee9?tpId=37&tqId=21313&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=5

#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	while (getline(cin,s)) {
		bool flag = true;
		int size = s.size(),count = 0;
		for (int i = 0; i < size; i++) {
			int temp = 0;
			while (isdigit(s[i])) {
				temp += s[i++] - '0';
				temp *= 10;
			}
			if (i == size && count == 3)
				break;
			if (s[i] != '.' || (temp / 10) > 255||count>3) {
				flag = false;
				break;
			}
			else {
				count++;
			}
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}