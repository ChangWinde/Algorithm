//  明明的随机数
//  明明想在学校中请一些同学一起做一项问卷调查，为了实验的客观性，他先用计算机生成了N个1到1000之间的随机整数（N≤1000），对于其中重复的数字，只保留一个，把其余相同的数去掉，不同的数对应着不同的学生的学号。然后再把这些数从小到大排序，按照排好的顺序去找同学做调查。请你协助明明完成“去重”与“排序”的工作(同一个测试用例里可能会有多组数据，希望大家能正确处理)。
//  https://www.nowcoder.com/practice/3245215fffb84b7b81285493eae92ff0?tpId=37&tqId=21226&rp=0&ru=/ta/huawei&qru=/ta/huawei/question-ranking

#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main() {
	int num;
	cin >> num;
	vector<int> res;
	set<int> s;
	int temp;
	for (int i = 0; i < num; ++i) {
		cin >> temp;
		if (!s.count(temp)) {
			s.insert(temp);
			res.push_back(temp);
		}
	}
	sort(res.begin(), res.end(), less<int>());
	for (auto i : res)
		cout << i << endl;
}