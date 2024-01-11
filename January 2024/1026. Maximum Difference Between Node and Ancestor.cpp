// 1026. Maximum Difference Between Node and Ancestor
// Problem Link - https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int getMaxDiff(TreeNode* root,int maxVal,int minVal){
        if(root==NULL){
            return maxVal-minVal;
        }
        return max(getMaxDiff(root->left,max(maxVal,root->val),min(minVal,root->val)),getMaxDiff(root->right,max(maxVal,root->val),min(minVal,root->val)));    
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return getMaxDiff(root,-1,1e5+1);
    }
};