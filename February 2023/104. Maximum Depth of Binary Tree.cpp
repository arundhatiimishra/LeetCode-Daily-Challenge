// 104. Maximum Depth of Binary Tree
// Problem Link - https://leetcode.com/problems/maximum-depth-of-binary-tree/

class Solution {
public:
    int maxDepth(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return max(maxDepth(root->left)+1,maxDepth(root->right)+1); 
    }
};
