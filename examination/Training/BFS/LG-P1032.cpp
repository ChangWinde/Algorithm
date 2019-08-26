//  P1032 字串变换

#include<iostream>
#include<string>
#include<map>
#include<queue>
#define MAXN 20
using namespace std;

string a, b;
string pre[MAXN], post[MAXN];
map<string, int> lb;
int as, cs = 0;
struct strq
{
	string s;
	int count;
	strq() {}
	strq(string _s, int _c) { s = _s; count = _c; }
};
string change(string& tep, int i, int j) {
	string res = "";
	int size = pre[j].size();
	if (i + size > as)return res;
	for (int k = 0; k < size; ++k)
		if (tep[i + k] != pre[j][k])
			return res;
	//构造修改串
	res += tep.substr(0, i);//0~i-1
	res += post[j];
	res += tep.substr(i + size);
	return res;
}
int bfs() {
	if (a == b)
		return 100;
	//进入初始状态
	queue<strq> q;
	strq temp(a, 0);
	q.push(temp);
	lb[a] = 1;
	while (!q.empty()) {
		strq now = q.front(); q.pop();
		as = now.s.size();
		for (int i = 0; i < as; ++i) {
			for (int j = 0; j <= cs; ++j) {
				string cstr = change(now.s, i, j);
				if (cstr != "" && lb.count(cstr) != 1) {
					if (now.count >= 10)
						return 100;
					if (cstr == b)
						return now.count + 1;
					strq temp(cstr, now.count + 1);
					q.push(temp);
					lb[cstr] = 1;
				}
			}
		}
	}
	return 100;
}

int main() {
	cin >> a >> b;
	while (cin >> pre[cs] >> post[cs])
		cs++;
	int ans = bfs();
	if (ans > 10)
		cout << "NO ANSWER!" << endl;
	else
		cout << ans << endl;
	system("pause");
}