// 958. Check Completeness of a Binary Tree
// Problem link - https://leetcode.com/problems/check-completeness-of-a-binary-tree/

class Solution {
public:
    bool isCompleteTree(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        bool gotNullVal=false;
        while(q.empty()==false){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                gotNullVal=true;
                continue;
            }
            if(gotNullVal==true && (temp!=NULL||temp->left!=NULL||temp->right!=NULL)){
                return false;
            }
            q.push(temp->left);
            q.push(temp->right);
        }
        return true;
    }
};
