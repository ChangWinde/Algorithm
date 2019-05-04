//  名字的漂亮度
//  给出一个名字，该名字有26个字符串组成，定义这个字符串的“漂亮度”是其所有字母“漂亮度”的总和。 
//  每个字母都有一个“漂亮度”，范围在1到26之间。没有任何两个字母拥有相同的“漂亮度”。字母忽略大小写。 
//  给出多个名字，计算每个名字最大可能的“漂亮度”。 
//  https://www.nowcoder.com/practice/02cb8d3597cf416d9f6ae1b9ddc4fde3?tpId=37&tqId=21268&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int num;
	while (cin >> num) {
		while (num--) {
			string s;
			cin >> s;
			vector<int> temp(26, 0);
			for (auto i : s)
				temp[(i - 'a')]++;
			sort(temp.begin(), temp.end(), greater<int>());
			int res = 0;
			int start = 26;
			for (auto i : temp) {
				if (i == 0)
					break;
				res += i * start--;
			}
			cout << res << endl;
		}
	}
}