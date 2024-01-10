// 872. Leaf-Similar Trees
// Problem Link - https://leetcode.com/problems/leaf-similar-trees/

// Time Complexity - O(N+M)
// Space Complexity - O(N+M)

class Solution {
public:
    void getLeafNodes(TreeNode* root,vector<int> &temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
        }
        getLeafNodes(root->left,temp);
        getLeafNodes(root->right,temp);
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> store1;
        vector<int> store2;
        getLeafNodes(root1,store1);
        getLeafNodes(root2,store2);
        if(store1==store2){
            return true;
        }
        return false;
    }
};