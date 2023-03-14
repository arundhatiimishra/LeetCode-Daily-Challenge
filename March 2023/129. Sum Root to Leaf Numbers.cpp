// 129. Sum Root to Leaf Numbers
// Problem Link - https://leetcode.com/problems/sum-root-to-leaf-numbers/

class Solution {
public:
    int sum=0;
    
    void takeSum(TreeNode* root,int currNum){
        if(root==NULL){
            return;
        }
        takeSum(root->left,currNum*10+root->val);
        takeSum(root->right,currNum*10+root->val);
        if(root->left==NULL && root->right==NULL){
            sum+=(currNum*10+root->val);
        }
    }
    
    int sumNumbers(TreeNode* root){
        takeSum(root,0);
        return sum;
    }
};
