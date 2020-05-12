//
// Created by Administrator on 2020/5/9 0009.
//

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty()) return 1;
        int n = nums.size();
        for(int i = 0; i < n; ++i){
            if(nums[i] < 1 || nums[i] > n) nums[i] = n+1;
        }
        for(int i = 0; i < n; ++i){
            int a = abs(nums[i]);
            if(a < n+1) nums[a-1] = - abs(nums[a-1]);
        }
        for(int i = 0; i < n; ++i){
            if(nums[i] > 0 ) return i+1;
        }
        return n+1;
    }
};