//  成绩排序

#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int dr;
struct Node {
	string name;
	int id, score;
	Node(string _name, int _score, int _id) {
		name = _name;
		id = _id;
		score = _score;
	}
	Node() {}
};
bool cmp0(Node n1, Node n2) {
	if (n1.score == n2.score)
		return n1.id < n2.id;
	return n1.score > n2.score;
}
bool cmp1(Node n1, Node n2) {
	if (n1.score == n2.score)
		return n1.id < n2.id;
	return n1.score < n2.score;
}
int main() {
	int n, dr;
	while (cin >> n >> dr) {
		Node* p = new Node[n + 1];
		for (int i = 1; i <= n; ++i) {
			cin >> p[i].name >> p[i].score;
			p[i].id = i;
		}
		if (dr == 0) {
			sort(p + 1, p + n + 1, cmp0);
		}
		else {
			sort(p + 1, p + n + 1, cmp1);
		}
		for (int i = 1; i <= n; ++i)
			cout << p[i].name << " " << p[i].score << endl;
	}
	system("pause");
}