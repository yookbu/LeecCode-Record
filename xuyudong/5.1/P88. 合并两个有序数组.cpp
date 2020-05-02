class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int merge_idx = m + n - 1;
        while(i >=0 || j >= 0){
            if(i < 0){
                nums1[merge_idx--] = nums2[j--];
            }
            else if(j < 0){
                nums1[merge_idx--] = nums1[i--];
            }
            else if(nums1[i] >= nums2[j]){
                nums1[merge_idx--] = nums1[i--];
            }
            else{
                nums1[merge_idx--] = nums2[j--];
            }
        }
    }
};