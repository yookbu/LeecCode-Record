//8. 字符串转换整数 (atoi)
// Created by Administrator on 2020/5/11 0011.
//

class Solution {
public:
    // map<char, int> m = {{'0', 0}, {'1', 1}, {'2', 2}}
    int myAtoi(string str) {
        if(str.empty()) return 0;
        int i = 0;
        while(i < str.size() && str[i] ==' '){
            i++;
        }
        if(i == str.size()) return 0;
        bool sign = true;
        if(str[i] == '-'){
            sign = false;
            ++i;
        }
        else if(str[i] == '+'){
            sign = true;
            ++i;
        }
        else if(str[i] > '9' || str[i] < '0') return 0;
        int res = 0;
        while(i < str.size() && str[i] <= '9' && str[i] >= '0'){
            int temp = str[i] - '0';
            if(!sign) temp = -temp;
            if(sign && (res > INT_MAX/10 || (res == INT_MAX/10 && temp > 7))) return INT_MAX;
            if(!sign && (res < INT_MIN/10 || (res == INT_MIN/10 && temp < -8))) return INT_MIN;
            res = 10*res + temp;
            i++;
        }
        return res;
    }
};