//  17. Letter Combinations of a Phone Number
//  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
//  A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//  https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> index = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv","wxyz",};
        vector<string> res;
        int size = digits.size();
        if(size == 0)
            return res;
        res.push_back("");
        for(int i = 0;i<size;++i){
            int num = digits[i]-'2';
            if(num>9||num<0)
                continue;
            string curr = index[num];
            int currLen = curr.size();
            vector<string> temp;
            int resLen = res.size();
            for(int j = 0;j<resLen;++j)
                for(int k = 0;k<currLen;++k)
                    temp.push_back(res[j]+curr[k]);
            res.swap(temp);
        }
        return res;
    }
};