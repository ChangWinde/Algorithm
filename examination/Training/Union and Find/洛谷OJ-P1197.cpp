//  P1197 [JSOI2008]星球大战

#include<iostream>
#include<vector>
using namespace std;

int n, m, k,block;
vector<int> t, u, v,att;

int findRoot(int x) { return t[x] == x ? x : findRoot(t[x]); }
int findKill(int x) { 
	int len = att.size();
	for (int i = 1; i < len;++i) {
		if (att[i] == x)
			return true;
	}
	return false;
}
void init() { for (int i = 1; i <= n; ++i)t[i] =  i; }

int solve(int p) {
	block++;
	for (int i = 1; i <= m; ++i) {
		if (u[i] == p || v[i] == p) {
			if (v[i] == p)
				swap(u[i], v[i]);
			bool y = findKill(v[i]);
			if (!y) {
				int x = findRoot(u[i]), z = findRoot(v[i]);
				if (x != z) {
					t[x] = z;
					block--;
				}
			}
		}
	}
	att.erase(att.end() - 1, att.end());
	return block;
}
void attackSet() {
	for (int i = 1; i<= m; ++i) {
		bool x = findKill(u[i]), y = findKill(v[i]);
		if (!x && !y ) {
			x = findRoot(u[i]), y = findRoot(v[i]);
			if (x != y) {
				t[x] = y;
				block--;
			}
		}
	}
}

int main() {
	while (cin >> n >> m) {
		t = vector<int>(n + 1);
		u = v = vector<int>(m + 1);
		for (int i = 1; i <= m; ++i) {
			cin >> u[i] >> v[i];
			u[i]++, v[i]++;
		}
		cin >> k;
		block = n-k;
		att = vector<int>(k + 1);
		for (int i = 1; i <= k; ++i) {
			cin >> att[i];
			att[i]++;
		}
		init();
		attackSet();//合并了所有没有被攻击的城市
		vector<int> out(k + 1);
		out[k] = block;
		for (int i = k; i >=1; --i) {
			out[i-1] = solve(att[i]);
		}
		for (int i = 0; i <= k; ++i) {
			cout << out[i] << endl;
		}
	}
    //system("pause");
}