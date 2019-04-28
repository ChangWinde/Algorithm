//  字符串分隔
//  •连续输入字符串，请按长度为8拆分每个字符串后输出到新的字符串数组； •长度不是8整数倍的字符串请在后面补数字0，空字符串不处理。 
//  https://www.nowcoder.com/practice/d9162298cb5a437aad722fccccaae8a7?tpId=37&tqId=21227&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

//notice: 
//void resize(int len,char c) p.resize()=>p变成长度为len的字符串，不足的用c补齐

#include<iostream>
#include<string>
using namespace std;

int main() {
	string tar;
	while (cin >> tar) {
		int size = tar.size();
		int start = 0;
		while ((start + 8) <= size) {
			cout << tar.substr(start, 8) << endl;
			start += 8;
		}
		if (start < size) {
			string p = tar.substr(start, size - start);
			p.resize(8, '0');
			cout << p<< endl;
		}
	}
}