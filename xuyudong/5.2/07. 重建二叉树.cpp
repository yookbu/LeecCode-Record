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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.empty()){
            return NULL;
        }
        return _buildTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1);
    }
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int pre_left,int pre_right,int in_left,int in_right){
      if(pre_left > pre_right || in_left > in_right){
          return NULL;
      }
      TreeNode* root = new TreeNode(preorder[pre_left]);
      int root_index = in_left;
      for(;root_index < in_right;++root_index){
          if(inorder[root_index] == root->val){
              break;
          }
      }
      int diff = root_index - in_left;//中序遍历中距离根节点的距离
      root->left = _buildTree(preorder,inorder,pre_left+1,pre_left+diff,in_left,root_index-1);
      root->right = _buildTree(preorder,inorder,pre_left+diff+1,pre_right,root_index+1,in_right);
      return root;
    }
};