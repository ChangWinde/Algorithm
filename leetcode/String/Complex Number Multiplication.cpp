//  537. Complex Number Multiplication
//  Given two strings representing two complex numbers.
//  You need to return a string representing their multiplication. Note i2 = -1 according to the definition.
//  https://leetcode.com/problems/complex-number-multiplication/

class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int mid = a.find('+');
        string a1 = a.substr(0,mid);
        string a2 = a.substr(mid+1,a.find('i')-1);
        mid = b.find('+');
        string b1 = b.substr(0,mid);
        string b2 = b.substr(mid+1,b.find('i')-1);
        int num1 = stoi(a1)*stoi(b1)-stoi(a2)*stoi(b2);
        int num2 = stoi(a1)*stoi(b2)+stoi(a2)*stoi(b1);
        return to_string(num1)+"+"+to_string(num2)+"i";
    }
};

//  a simple solution from discuss which uses stringstream
class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int ra, ia, rb, ib;
        char buff;
        stringstream aa(a), bb(b), ans;
        aa >> ra >> buff >> ia >> buff;
        bb >> rb >> buff >> ib >> buff;
        ans << ra*rb - ia*ib << "+" << ra*ib + rb*ia << "i";
        return ans.str();
    }
};