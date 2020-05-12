//
// Created by Administrator on 2020/5/9 0009.
//

class Solution {
public:
    bool isValidBST(TreeNode* root){
        stack<TreeNode*> stack;
        long MIN = LONG_MIN;
        while(!stack.empty() || root){
            while(root){
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            if(root->val <= MIN) return false;
            MIN = root->val;
            root = root->right;
        }
        return true;
    }
};