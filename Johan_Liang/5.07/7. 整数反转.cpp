//
// Created by Administrator on 2020/5/9 0009.
//

class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x){
            int a = x%10;
            if(res > INT_MAX/10 || (res == INT_MAX/10 && a > 7)) return 0;
            if(res < INT_MIN/10 || (res == INT_MIN/10 && a < -8)) return 0;
            res = res*10 + a;
            x = x/10;
        }

        return res;
    }
};