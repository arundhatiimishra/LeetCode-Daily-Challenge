// 938. Range Sum of BST
// Problem Link - https://leetcode.com/problems/range-sum-of-bst/

// Time Complexity -  O(N)
// Space Complexity - O(N)

class Solution {
public:
    int getSum(TreeNode* root,int low,int high){
        if(root==NULL){
            return 0;
        }
        if(root->val<=high && root->val>=low){
            return getSum(root->left,low,high)+getSum(root->right,low,high)+root->val;
        }else if(root->val>high){
            return getSum(root->left,low,high);
            
        }else if(root->val<low){
            return getSum(root->right,low,high);
        }else{
            return getSum(root->left,low,high)+getSum(root->right,low,high);   
        }  
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        return getSum(root,low,high);
    }
};