//  表达式

#include<stdio.h>
#include<iostream>
#include<string>
#include<stack>
using namespace std;
string str;
int len;
stack<int> op;
stack<double> in;
int prior[5][5] = {
	1,0,0,0,0,
	1,0,0,0,0,
	1,0,0,0,0,
	1,1,1,0,0,
	1,1,1,0,0
};
void cal(bool& f, int& retn, int& i) {
	if (i == 0 && op.empty()) {
		f = true;
		retn = 0;
		return;
	}
	if (i == len) {
		f = true;
		retn = 0;
		return;
	}
	if (isdigit(str[i])) {
		f = false;
	}
	else {
		f = true;
		if (str[i] == '+') retn = 1;
		else if (str[i] == '-') retn = 2;
		else if (str[i] == '*') retn = 3;
		else if (str[i] == '/') retn = 4;
		return;
	}
	retn = 0;
	while (i < len&&isdigit(str[i])) {
		retn *= 10;
		retn += str[i] - '0';
		i++;
	}
	return;
}
int main() {
	while (cin>>str) {
		len = str.size();
		if (str[0] == '0'&&str[1] == 0)
			printf("%d\n", 0);
		while (!op.empty())op.pop();
		while (!in.empty())in.pop();
		bool flag;
		int retn, id = 0;
		while (1) {
			cal(flag, retn, id);
			//数字
			if (!flag) {
				in.push(retn);
				continue;
			}
			else {
				int p = -1;
				if(!op.empty())
					p = op.top();
				while (!op.empty()&&prior[retn][op.top()] == 0) {
					int cur = op.top(); op.pop();
					double b = in.top(); in.pop();
					double a = in.top(); in.pop();
					if (cur == 1) {
						in.push(a + b);
					}
					else if (cur == 2) {
						in.push(a - b);
					}
					else if (cur == 3) {
						in.push(a*b);
					}
					else if (cur == 4) {
						in.push(a / b);
					}
				}
				op.push(retn);
				if(id)
					id++;
				if (op.size() == 2 && op.top() == 0)break;
			}
		}
		printf("%d\n", (int)in.top());
	}
}
