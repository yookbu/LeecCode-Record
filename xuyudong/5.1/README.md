## 题目描述

给你两个有序整数数组 nums1 和 nums2，请你将 *nums2* 合并到 *nums1* 中*，*使 *nums1* 成为一个有序数组。

说明：

1.初始化 nums1 和 nums2 的元素数量分别为 m 和 n 。
2.你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

示例:

![image-20200501203755864](\image\image-20200501203755864.png)

## 思路

从数组结尾开始填充排序后的元素，即从nums1结尾处开始降序排序。

## 代码

```cpp
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
```

## 复杂度分析

时间复杂度：O(m + n)

空间复杂度：O(1)