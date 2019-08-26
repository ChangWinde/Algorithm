// http://bailian.openjudge.cn/xly2019/B/

#include<iostream>
#include<string>
using namespace std;
int date[201][12][31];
int months[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int year, month;
bool isgap(int y) { return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0); }
void init() {
	int cnt = 0;
	for (int y = 0; y < 201; y++) {
		if (isgap(y))months[1] = 29;
		else { months[1] = 28; }
		for (int m = 0; m < 12; m++) {
			int end = months[m];
			for (int d = 0; d < end; d++) {
				date[y][m][d] = cnt++;
			}
		}
	}
}
string week[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
void sol() {
	int offset = 1900;
	for (int i = 0; i < 7; i++) {
		cout << week[i] << " ";
	}
	cout << endl;
	int k = date[2019 - offset][6][6] - date[year - offset][month - 1][0];
	if(k<0)k = (k%7+7) % 7;
	else k = 7- (k % 7 + 7) % 7;
	int ans = 1;
	for (int i = 0; i < k; i++)
		printf("    ");
	for (int i = k; i < 7; i++) {
		printf("%3d ", ans++);
	}
	while (ans <=months[month-1]) {
		cout << endl;
		for (int i = 0; i < 7; i++) {
			printf("%3d ", ans++);
			if (ans > months[month - 1])break;
		}
	}	
	cout << endl;
}
int main() {
	init();
	while (cin >> year >> month) {
		sol();
	}
}
