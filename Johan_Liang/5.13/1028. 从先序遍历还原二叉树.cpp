//1028. 从先序遍历还原二叉树
// Created by Administrator on 2020/5/14 0014.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string S) {
        int index = 0;
        return helper(index, 0, S);
    }

    TreeNode* helper(int& index, int depth, string S){
        if(index == S.size()) return nullptr;
        for(int i = 0; i < depth ;i++){
            if(S[index + i] != '-') return nullptr;
        }
        int j = index + depth;
        while(S[j] != '-' && j <S.size()){
            ++j;
        }
        string temp = S.substr(index+depth, j-index-depth);
        int num = stoi(temp);
        TreeNode* node = new TreeNode(num);
        index = j;
        node->left = helper(index, depth+1, S);
        node->right = helper(index, depth+1, S);
        return node;
    }
};