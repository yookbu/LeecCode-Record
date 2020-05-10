//面试题51. 数组中的逆序对
// Created by Administrator on 2020/5/10 0010.
//

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if(nums.empty()) return 0;
        int count = 0;
        helper(0, nums.size()-1, nums, count);
        return count;
    }

    vector<int> helper(int start, int end, vector<int>& nums, int& count){
        if(start >= end) return vector<int>{nums[start]};
        else{
            int mid = (start+end)/2;
            vector<int> left = helper(start, mid, nums, count);
            vector<int> right = helper(mid+1, end, nums, count);
            vector<int> res;
            int i = 0;
            int j = 0;
            while(i < left.size() && j < right.size()){
                if(left[i] > right[j]){
                    res.push_back(right[j]);
                    j++;
                    count += (left.size()-i);
                }else {
                    res.push_back(left[i]);
                    i++;
                }
            }
            while(i < left.size()){
                res.push_back(left[i]);
                ++i;
            }
            while(j < right.size()){
                res.push_back(right[j]);
                j++;
            }
            return res;
        }
    }
};