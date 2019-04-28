//  合并表记录
//  数据表记录包含表索引和数值，请对表索引相同的记录进行合并，即将相同索引的数值进行求和运算，输出按照key值升序进行输出。
//  https://www.nowcoder.com/practice/de044e89123f4a7482bd2b214a685201?tpId=37&tqId=21231&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<map>
using namespace std;

int main() {
	map<int, int> _map;
	long int num;
	cin >> num;
	while (num--) {
		int index, value;
		cin >> index >> value;
		if (_map.find(index) == _map.end()) {
			_map[index] = value;
		}
		else {
			_map[index] += value;
		}
	}
	map<int, int>::iterator it = _map.begin();
	while (it != _map.end()) {
		cout << it->first << " " << it->second <<endl;
		it++;
	}
}