//  图片整理
//  Lily上课时使用字母数字图片教小朋友们学习英语单词，每次都需要把这些图片按照大小（ASCII码值从小到大）排列收好。请大家给Lily帮忙，通过C语言解决。
//  https://www.nowcoder.com/practice/2de4127fda5e46858aa85d254af43941?tpId=37&tqId=21257&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=2

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    while(cin>>s){
        sort(s.begin(),s.end(),less<int>());
        cout<<s<<endl;
    }
}
// 手撸快排
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void swap(char& a, char& b) {
	char t = a;
	a = b;
	b = t;
}
int partition(string& s, int l, int r) {
	int i = l;
	int j = r + 1;
	char stand = s[i];
	while (1) {
		while (s[++i] < stand) {
			if (i == r)
				break;
		}
		while (s[--j] > stand) {
			if (j == l)
				break;
		}
		if (i >= j)
			break;
		swap(s[i], s[j]);
	}
	swap(s[j], s[l]);
	return j;
}
void quickSort(string& s, int l, int r) {
	if (l>=r)
		return;
	int mid = partition(s, l, r);
	quickSort(s, l, mid - 1);
	quickSort(s, mid + 1, r);
}
int main(){
	string s;
	while (cin >> s) {
		quickSort(s, 0, s.size()-1);
		cout << s << endl;
	}
}