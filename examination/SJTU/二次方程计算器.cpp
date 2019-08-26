//  二次方程计算器

#include<stdio.h>
#include<string>
#include<cmath>
#include<iostream>
using namespace std;
string s;
double res;
bool equal(double x, double y) {
	return (x - y) > -0.0000001 && (x - y) < 0.0000001;
}
bool solve(double&a, double&b, double&c) {
	int i = -1;
	int slen = s.size();
	int temp = 0;
	int ret = 1;
	while (++i < slen) {
		if (s[i] == '=') {
			ret = -1;
			continue;
		}
		bool neg = false;
		if (s[i] == '-') {
			neg = true;
			i++;
		}
		else if (s[i] == '+') {
			i++;
		}
		while (i < slen&&isdigit(s[i])) {
			temp *= 10;
			temp += s[i] - '0';
			i++;
		}
		temp = (neg) ? 0 - temp : temp;
		if (s[i] != 'x') {
			c += temp * ret;
			temp = 0;
			--i;
			continue;
		}
		//1 2处理
		if (s[i] == 'x') {
			temp = (temp == 0) ? 1 : temp;
			//二次
			if (i + 1 < slen&&s[i+1] == '^') {
				a += temp * ret;
				i += 2;
			}
			else {
				b += temp * ret;
			}
			temp = 0;
		}
	}
	res = b * b - 4 * a*c;
	if (res >= 0) {
		res = sqrt(res);
		c = (res - b) / a / 2;
		b = (-res-b) / a / 2;
		if (c > b)
			swap(c, b);
		return true;
	}
	else {
		return false;
	}
}

int main() {
	while (getline(cin, s)) {
		double a, b, c;
		a = b = c = 0.0;
		if (solve(a, b, c)) {
			if (equal(res,0))
				printf("%.2f", c);
			else {
				printf("%.2f %.2f", c, b);
			}
		}
		else {
			printf("No Solution");
		}
	}
}