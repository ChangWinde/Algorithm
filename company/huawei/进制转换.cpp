//  进制转换
//  写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串。（多组同时输入 
//  https://www.nowcoder.com/practice/8f3df50d2b9043208c5eed283d1d4da6?tpId=37&tqId=21228&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char, int> m{
	{'A',10},{'B',11},{'C',12},{'D',13},{'E',14},{'F',15}
};
long long int toDec(string &s) {
	long long int num = 0;
	int size = s.size();
	for (int i = 0; i < size; ++i) {
		int gap = s[i] - '0';
		if (gap < 10) {
			num += gap;
		}
		else {
			num += m[s[i]];
		}
		num *= 16;
	}
	num /= 16;
	return num;
}

int main() {
	string tar;
	while (cin >> tar) {
		string temp = tar.substr(2, tar.size() - 2);
		cout << toDec(temp) << endl;
	}
}