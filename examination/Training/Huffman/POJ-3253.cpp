//  Fence Repair
//  http://poj.org/problem?id=3253

#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;

int n;
ll sol() {
	ll a;
	priority_queue<ll,vector<ll>,greater<ll>>q;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		q.push(a);
	}
	ll ans = 0;
	while (q.size() > 1) {
		ll b = q.top(); q.pop();
		ll c = q.top(); q.pop();
		ans += (b+c);
		q.push(b + c);
	}
	return ans;
}
int main() {
	while (cin >> n) {
		cout << sol() << endl;;
	}
}