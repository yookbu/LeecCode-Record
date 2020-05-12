//面试题42. 连续子数组的最大和
// Created by Administrator on 2020/5/10 0010.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int cur = 0;
        for(auto a : nums){
            if(cur < 0 ){
                cur = 0;
            }
            cur += a;
            res = max(cur, res);
        }
        return res;
    }
};