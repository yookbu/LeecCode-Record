//
// Created by Administrator on 2020/5/12 0012.
//

class Solution {
public:
    vector<int> store = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> RomanChars = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        string res;
        for(auto i = 0; i < store.size(); ++i){
            while(num >= store[i]){
                res += RomanChars[i];
                num -= store[i];
            }
            if(num == 0) break;
        }
        return res;
    }
};