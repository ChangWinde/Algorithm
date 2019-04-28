//  句子逆序
//  将一个英文语句以单词为单位逆序排放。例如“I am a boy”，逆序排放后为“boy a am I” 有单词之间用一个空格隔开，语句中除了英文字母外，不再包含其他字符
//  https://www.nowcoder.com/practice/48b3cb4e3c694d9da5526e6255bb73c3?tpId=37&tqId=21236&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
using namespace std;
void swap(int& a, int& b) {
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
void reverse(string& s, int start, int end) {
	while (start < end) {
		swap(s[start++], s[end--]);
	}
}
int main() {
	string s;
	getline(cin, s);
	int size = s.size();
	reverse(s, 0, size - 1);
	int start = 0,j = 0;
	while (start < size) {
		while (j < size && s[j] != ' ') {
			j++;
		}
		reverse(s, start, j - 1);
		start = ++j;
	}
	cout << s;
}
