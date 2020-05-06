//42. 接雨水
// Created by Administrator on 2020/5/6 0006.
//

class Solution {
public:
    int trap(vector<int> &height) {
        if (height.empty() || height.size() <= 2) return 0;
        vector<int> leftMax(height.size()), rightMax(height.size());
        int res = 0;

        leftMax[0] = height[0];

        for (int i = 1; i < height.size(); ++i) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[height.size() - 1] = height[height.size() - 1];
        for (int i = height.size() - 2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }
        for (int i = 1; i < height.size() - 1; i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
}