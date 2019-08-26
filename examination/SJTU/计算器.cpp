//
#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
#define NP 10
struct bigInt {
	int d[500];
	int s;
	void init() {
		memset(d, 0, sizeof(d));
		s = 0;
	}
	void set(string str) {
		init();
		for (int i = str.size() - 1; i >= 0; --i) {
			d[s++] = str[i] - '0';
		}

	}
	bigInt operator+(const bigInt& x)const {
		bigInt ret;
		ret.init();
		int carry = 0;
		int i = 0;
		while (i < s || i < x.s) {
			int temp = carry + x.d[i] + d[i];
			ret.d[ret.s++] = temp % NP;
			carry = temp / NP;
			i++;
		}
		if (carry != 0) {
			ret.d[ret.s++] = carry;
		}
		return ret;
	}
	int operator<(const bigInt& x)const {
		if (s < x.s)
			return 1;
		else if (s > x.s)
			return -1;
		else {
			for (int i = s - 1; i >= 0; --i)
				if (d[i] > x.d[i])
					return -1;
				else if (d[i] < x.d[i])
					return 1;
		}
		return 0;
	}
	bigInt operator-(const bigInt& x)const {
		bigInt ret;
		ret.init();
		bool flag = true;
		int high = s - 1;
		for (int i = s - 1; i >= 0; --i) {
			int temp = d[i] - x.d[i];
			if (temp<0) {
				flag = false;
				int t = i + 1;
				ret.d[t]--;
				while (ret.d[t]<0) {
					ret.d[t] = NP - ret.d[t];
					t++;
					ret.d[t]--;
				}
				if (0==ret.d[t]&&t == high) {
					--t;
					while (ret.d[t] == 0) {
						t--;
					}
					high = t;
				}
				ret.d[i] = NP + d[i] - x.d[i];
				ret.s++;
			}
			else if(temp>0){
				flag = false;
				ret.d[i] = temp;
				ret.s++;
			}
			else {
				if (!flag) {
					ret.d[i] = 0;
					ret.s++;
				}
			}
		}
		ret.s = high + 1;
		return ret;
	}
	bigInt operator*(int& x)const {
		bigInt ret;
		ret.init();
		int carry = 0;
		int i = 0;
		while (i < s) {
			int temp = d[i] * x + carry;
			ret.d[ret.s++] = temp % NP;
			carry /= NP;
			i++;
		}
		if (carry != 0) {
			ret.d[ret.s++] = carry;
		}
		return ret;
	}
	void printBig() {
		for (int i = s - 1; i >= 0; --i) {
			printf("%d", d[i]);
		}
		printf("\n");
	}
};

bigInt dot(bigInt& x, bigInt& y) {
	bigInt ret;
	ret.set("0");
	int c = 1;
	for (int i = 0; i < x.s; ++i) {
		int t = (x.d[i] * c);
		ret = ret + y * t;
		c *= 10;
	}
	return ret;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		bigInt x, y, c;
		x.set(s1);
		y.set(s2);
		c = x + y;
		c.printBig();
		int l = x < y;
		if (l == 0)
			printf("%d\n", 0);
		else if (l == 1) {
			c = y - x;
			printf("-");
			c.printBig();
		}
		else {
			c = x - y;
			c.printBig();
		}
		c = dot(x, y);
		c.printBig();
	}
}
