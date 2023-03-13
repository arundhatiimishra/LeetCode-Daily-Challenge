// 101. Symmetric Tree
// Problem Link - https://leetcode.com/problems/symmetric-tree/

class Solution {
public:
    bool isSym(TreeNode* root1,TreeNode* root2){
        if(root1->left==NULL && root2->right==NULL && root1->right==NULL && root2->left==NULL){
            return true;
        }
        if(root1->left!=NULL && root2->right==NULL){
            return false;
        }
        if(root1->left==NULL && root2->right!=NULL){
            return false;
        }
        if(root1->right==NULL && root2->left!=NULL){
            return false;
        }
        if(root1->right!=NULL && root2->left==NULL){
            return false;
        }
        if(root1->right==NULL && root2->left==NULL){
            if(root1->left->val!=root2->right->val){
                return false;
            }
            return isSym(root1->left,root2->right);
        }
        if(root1->left==NULL && root2->right==NULL){
            if(root1->right->val!=root2->left->val){
                return false;
            }
            return isSym(root1->right,root2->left);
        }
        if(root1->left->val!=root2->right->val||root1->right->val!=root2->left->val){
            return false;
        }
        if(root1==root2){
            return isSym(root1->left,root2->right);
        }else{
            return isSym(root1->left,root2->right) && isSym(root1->right,root2->left); 
        }
    }
    
    bool isSymmetric(TreeNode* root){
        return isSym(root,root); 
    }
};
