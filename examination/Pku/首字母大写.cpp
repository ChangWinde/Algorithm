//  首字母大写

#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
using namespace std;

string s;
int len;
void toCap(char & c) {
	if(c>='a'&&c<='z')
		c = c & 0xDF;
}
void solve() {
	len = s.size();
	for (int i = 0; i < len; ++i){
		if (!i||isspace(s[i - 1]))toCap(s[i]);
		printf("%c", s[i]);
	}
	printf("\n");
}
int main() {
	while (getline(cin,s)) {
		solve();
	}
}