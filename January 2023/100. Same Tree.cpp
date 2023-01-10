// 100. Same Tree
// Problem Link - https://leetcode.com/problems/same-tree/

class Solution{
public:
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p==NULL && q==NULL){
            return true;
        }
        if((p==NULL && q!=NULL)|| p!=NULL && q==NULL){
            return false;
        }
        if(p->val!=q->val){
            return false;
        }
        if(isSameTree(p->left,q->left)==true && isSameTree(p->right,q->right)==true){
            return true;
        }
        return false;
    }
};
