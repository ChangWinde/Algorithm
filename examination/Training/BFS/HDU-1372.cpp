//  Knight Moves
//  http://acm.hdu.edu.cn/showproblem.php?pid=1372

#include<iostream>
#include<queue>
using namespace std;
struct Point
{
	Point() {}
	Point(int x, int y) {
		_x = x; _y = y;
	}
	bool isLegal() {
		return (_x >= 0 && _x < 8 && _y >= 0 && _y < 8);
	}
	bool isEqual(Point& other) {
		return (_x == other._x&&_y == other._y);
	}
	int _x, _y;
};
const int jump[8][2] = { -2,-1,-2,1,-1,-2,-1,2,2,-1,2,1,1,- 2,1,2 };
int map[8][8];
char s1[2];
char s2[2];

int bfs(Point s,Point e) {
	if (s.isEqual(e))
		return 0;
	queue<pair<Point, int> >q;
	q.push(make_pair(s,0));
	map[s._x][s._y] = 0;
	while (!q.empty()) {
		pair<Point, int> curr = q.front();
		q.pop();
		for (int i = 0; i < 8; ++i) {
			Point temp(curr.first._x + jump[i][0], curr.first._y + jump[i][1]);
			if (!map[temp._x][temp._y])
				continue;
			if (temp.isEqual(e))
				return curr.second + 1;
			else {
				if (temp.isLegal()) {
					q.push(make_pair(temp, curr.second + 1));
					map[temp._x][temp._y] = 0;
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
		memset(map, 1, sizeof(map));
		Point p1(s1[0] - 'a', s1[1]-'0');
		Point p2(s2[0] - 'a', s2[1]-'0');
		int res = bfs(p1, p2);
		cout << "To get from " << p << " to " << s2 << " takes " << res << " knight moves." << endl;
	}
}