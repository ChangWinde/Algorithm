//  Powerful Calculator
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
void init(string& x, string& y) {
	int l1 = x.size(), l2 = y.size();
	while (l1 < l2) { x = '0' + x; l1++; }
	while (l2 < l1) { y = '0' + y; l2++; }
	x = '0' + x;
	y = '0' + y;
}
void delZero(string& x) {
	while (x[0] == '0') {
		x.erase(0, 1);
	}
}
int compare(string x, string y) {
	int l1 = x.size(), l2 = y.size();
	for (int i = 0; i < l1; i++) {
		if (x[i] > y[i])return 1;
		else if (x[i] < y[i])return-1;
		else {}
	}
	return 0;
}
string add(string x, string y) {
	init(x, y);
	string ret(x);
	int l1 = x.size(), l2 = y.size();
	int temp = 0, carry = 0;
	for (int i = l2 - 1; i >= 0; i--) {
		temp = x[i] + y[i] - '0' - '0' + carry;
		carry = temp / 10;
		ret[i] = temp % 10 + '0';
	}
	delZero(ret);
	return ret;
}
string minuss(string x, string y) {
	init(x,y);
	string ret(x);
	int l1 = x.size(), l2 = y.size();
	int temp = compare(x, y);
	if (temp == 0)
		return "0";
	if (temp < 0)
		swap(x, y);
	int tep, carry = 0;
	for (int i = l1; i >= 0; i--) {
		tep = x[i] - y[i] + carry;
		if (tep < 0) {
			tep += 10;
			carry = -1;
		}
		else {
			carry = 0;
		}
		ret[i] = tep % 10 + '0';
	}
	delZero(ret);
	if (temp < 0) {
		ret = '-' + ret;
	}
	return ret;
}
string dot(string x, int d) {
	x = '0' + x;
	int len = x.size();
	int temp, carry = 0;
	for (int i = len - 1; i >= 0; i--) {
		temp = (x[i] - '0')*d + carry;
		carry = temp / 10;
		x[i] = temp % 10 + '0';
	}
	if (carry != 0) {
		char a = carry + '0';
		x = a + x;
	}
	delZero(x);
	return x;
}
string dot(string x, string y) {
	int l1 = x.size(), l2 = y.size();
	string ans;
	ans.resize(l1, '0');
	for (int i = l2 - 1; i >= 0; i--) {
		string temp(x);
		ans = add(ans, dot(temp, y[i] - '0'));
		x = x + '0';
	}
	return ans;
}
int main() {
	string x, y;
	while (cin >> x >> y) {
		cout << add(x, y) << endl;
		cout << minuss(x, y) << endl;
		cout << dot(x, y) << endl;
	}
}