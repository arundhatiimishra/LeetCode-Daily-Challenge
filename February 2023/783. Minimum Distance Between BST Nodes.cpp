// 783. Minimum Distance Between BST Nodes
// Problem Link - https://leetcode.com/problems/minimum-distance-between-bst-nodes/

class Solution {
public:
    int answer=1e6;
    int maxNodeVal=-1e6;
    
    void findMin(TreeNode* root){
        if(root==NULL){
            return;
        }
        findMin(root->left);
        answer=min(answer,abs(maxNodeVal-root->val));
        maxNodeVal=root->val;
        findMin(root->right);      
    }
    
    int minDiffInBST(TreeNode* root){
        findMin(root);
        return answer;
    }
};
