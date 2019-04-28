//  坐标移动
//  开发一个坐标计算工具， A表示向左移动，D表示向右移动，W表示向上移动，S表示向下移动。从（0,0）点开始移动，从输入字符串里面读取一些坐标，并将最终输入结果输出到输出文件里面。
//  https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29?tpId=37&tqId=21240&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=1

#include<iostream>
#include<string>
#include<map>
using namespace std;
map<char, int> _map{
	{'A',1},{'D',2},{'S',3},{'W',4}
};
int main() {
	string s;
	while (cin >> s) {
		int x = 0, y = 0;
		int size = s.size();
		for (int i = 0; i < size; ++i) {
			int gap;
			if (_map.find(s[i]) != _map.end())
				gap = _map[s[i++]];
			else {
				while (i < size && s[i] != ';') {
					i++;
				}
				continue;
			}
			int pos = 0;
			while (isdigit(s[i])) {
				pos += s[i] - '0';
				pos *= 10;
				++i;
			}
			pos /= 10;
			if (s[i] != ';') {
				while (i < size && s[i] != ';') {
					i++;
				}
				continue;
			}
			switch (gap) {
			case 1:
				x -= pos;
				break;
			case 2:
				x += pos;
				break;
			case 3:
				y -= pos;
				break;
			case 4:
				y += pos;
				break;
			}
		}
		cout << x << "," << y << endl;
	}
}