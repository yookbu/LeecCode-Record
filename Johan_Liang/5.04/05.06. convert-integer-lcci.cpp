//面试题 05.06. 整数转换
// Created by Administrator on 2020/5/6 0006.
//

class Solution {
public:
    int convertInteger(int A, int B) {
        int count = 0;
        int diff = A ^ B;
        unsigned int flag = 1;
        int cnt = 0;
        while(cnt < sizeof(int)*8){
            if((flag & diff) != 0){
                count ++;
            }
            cout << cnt << endl;
            flag = flag << 1;
            cnt++;
        }
        return count;
    }
};