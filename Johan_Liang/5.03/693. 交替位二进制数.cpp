//693. 交替位二进制数
// Created by Administrator on 2020/5/6 0006.
//

class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool pre;
        (n & 1) != 0 ? pre = false : pre = true;
        while(n){
            bool cur;
            if ((n & 1) != 0) {
                cur = true;
            } else {
                cur = false;
            }
            if(cur == pre) return false;
            pre = cur;
            n = n >> 1;
        }
        return true;
    }
};