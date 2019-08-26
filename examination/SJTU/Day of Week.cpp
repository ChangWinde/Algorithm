//  Day of Week
#include<iostream>
#include<string>
using namespace std;
int ye, mo, da;
string s;
int date[5000][12][31];
string months[13] = {
	"","January", "February", "March","April", "May", "June",
	"July", "August", "September", "October", "November", "December"
};
string days[7] = {
	"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};
int ms[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
bool isgap(int y) { return ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)); }

void init() {
	int s = 0;
	for (int y = 0; y < 5000; y++) {
		if (isgap(y)) { ms[1] = 29; }
		else { ms[1] = 28; }
		for (int m = 0; m < 12; m++) {
			int end = ms[m];
			for (int d = 0; d < end; d++)
				date[y][m][d] = s++;
		}
	}
}

int main() {
	init();
	while (cin >> da >> s >> ye) {
		for (int i = 1; i <= 12; i++) {
			if (s == months[i]) { mo = i; break; }
		}
		int temp = date[ye][mo - 1][da - 1] - date[2019][6 - 1][30 - 1];
		temp = (temp % 7 + 7) % 7;
		cout << days[temp] << endl;
	}
}