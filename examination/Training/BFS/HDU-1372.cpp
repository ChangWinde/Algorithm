//  Knight Moves
//  http://acm.hdu.edu.cn/showproblem.php?pid=1372

#include<iostream>
#include<queue>
using namespace std;
struct Point
{
	Point() {}
	Point(int x, int y, int s) {
		_x = x; _y = y; _s = s;
	}
	bool isLegal() {
		return (_x >= 0 && _x < 8 && _y >= 1 && _y <= 8);//注意题目的要求，这里x，y的合法范围不同
	}
	bool isEqual(Point& other) {
		return (_x == other._x&&_y == other._y);
	}
	int _x, _y, _s;
};
const int jump[8][2] = { -2,-1,-2,1,-1,-2,-1,2,2,-1,2,1,1,-2,1,2 };
bool map[8][8];
char s1[2];
char s2[2];

int bfs(Point s, Point e) {
	if (s.isEqual(e))
		return 0;
	queue<Point>q;
	q.push(s);
	map[s._x][s._y] = false;
	while (!q.empty()) {
		Point curr = q.front(); q.pop();
		for (int i = 0; i < 8; ++i) {
			Point temp(curr._x + jump[i][0], curr._y + jump[i][1], curr._s + 1);
			if (!map[temp._x][temp._y])
				continue;
			if (temp.isEqual(e))
				return curr._s + 1;
			else {
				if (temp.isLegal()) {
					q.push(temp);
					map[temp._x][temp._y] = false;
					//cout << "(" << temp._x << "," << temp._y << ")" << endl;
				}
			}
		}
	}
}

int main() {
	while (cin >> s1 >> s2) {
		char p[3];
		p[0] = s1[0];
		p[1] = s1[1];
		p[2] = '\0';
		memset(map, true, sizeof(map));
		Point p1(s1[0] - 'a', s1[1] - '0', 0);
		Point p2(s2[0] - 'a', s2[1] - '0', 0);
		int res = bfs(p1, p2);
		cout << "To get from " << p << " to " << s2 << " takes " << res << " knight moves." << endl;
	}
	system("pause");
}