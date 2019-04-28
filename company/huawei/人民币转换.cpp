//  人民币转换
//  考试题目和要点：
//  1、中文大写金额数字前应标明“人民币”字样。中文大写金额数字应用壹、贰、叁、肆、伍、陆、柒、捌、玖、拾、佰、仟、万、亿、元、角、分、零、整等字样填写。（30分） 
//  2、中文大写金额数字到“元”为止的，在“元”之后，应写“整字，如￥ 532.00应写成“人民币伍佰叁拾贰元整”。在”角“和”分“后面不写”整字。（30分） 
//  3、阿拉伯数字中间有“0”时，中文大写要写“零”字，阿拉伯数字中间连续有几个“0”时，中文大写金额中间只写一个“零”字，如￥6007.14，应写成“人民币陆仟零柒元壹角肆分“。
//  https://www.nowcoder.com/practice/00ffd656b9604d1998e966d555005a4b?tpId=37&tqId=21318&rp=0&ru=%2Fta%2Fhuawei&qru=%2Fta%2Fhuawei%2Fquestion-ranking&tPage=5

// 这个题目就是一个鬼鬼哟
// test case:1200,1010,10010,0.29,0.12,0.1,0.01
#include<iostream>
#include<string>
using namespace std;
string num[] = { "零","壹","贰","叁","肆","伍","陆","柒","捌","玖" };
string label[] = { "角","分","","拾","佰","仟" };
string grade[] = { "","万","亿" };
string getWord(int money,int g) {
	string res;
	int index = 2;
	if (money % 1000 == 0) {
		return num[money / 1000] + "仟"+grade[g];
	}
	else if(money % 100 == 0){
		money /= 100;
		index = 4;
	}
	else if (money % 10 == 0) {
		money /= 10;
		index = 3;
	}
	while (money) {
		int temp = money % 10;
		money /= 10;
		if (temp == 0) {
			res = "零" + res;
			while (temp == 0&&money!=0) {
				temp = money % 10;
				money /= 10;
				index++;
			}
		}
        if(temp == 1 && index == 3)
            res = label[index++] + res;
        else
            res = num[temp] + label[index++] + res;
	}
	return res+grade[g];
}

int main() {
	double money;
	while (cin >> money) {
		string res;
		int integer = money;
		float mzero = money - integer;
		int index = 2;
		int grad = 0;
		while (integer) {
			int temp = integer % 10000;
			res = getWord(temp,grad++)+res;
			integer /= 10000;
			if (temp < 1000 && integer != 0)
				res = "零" + res;
		}
		index = 0;
		if((int)money  != 0)
			res = res + "元";
		if (((int)(mzero * 100) == 0)) {
			res = res + "整";
		}
		else {
            mzero += 0.0005;
			while (index != 2) {
				int temp = ((int)(mzero * 10)) % 10;
                if (temp == 0){
                    index++;
                    mzero *= 10;
                    continue;
                }
				res = res + num[temp] + label[index++];
				mzero *= 10;
			}
		}
		cout << "人民币"+res<<endl;
	}
}