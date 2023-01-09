// 144. Binary Tree Preorder Traversal
// Problem Link - https://leetcode.com/problems/binary-tree-preorder-traversal/

class Solution {
public:
    void preOrder(TreeNode* root,vector<int> &answer){
        if(root==NULL){
            return;
        }
        answer.push_back(root->val);
        preOrder(root->left,answer);
        preOrder(root->right,answer);
    }
    
    vector<int> preorderTraversal(TreeNode* root){
        vector<int> answer;
        preOrder(root,answer);
        return answer;
    }
};
