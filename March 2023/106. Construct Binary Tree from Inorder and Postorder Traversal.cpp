// 106. Construct Binary Tree from Inorder and Postorder Traversal
// Problem Link - https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

class Solution {
public:
    int curridx=0;

    TreeNode* buildTreee(vector<int>& inorder,vector<int>& postorder,int start,int end){
        if(start>end){
            return NULL;
        }
        int curr=postorder[curridx];
        curridx++;
        TreeNode* temp=new TreeNode(curr);
        if(start==end){
            return temp;
        }
        int idx;
        for(int i=start;i<=end;i++){
            if(curr==inorder[i]){
                idx=i;
            }
        }
        temp->right=buildTreee(inorder,postorder,idx+1,end);
        temp->left=buildTreee(inorder,postorder,start,idx-1);
        return temp;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        reverse(postorder.begin(),postorder.end());
        return buildTreee(inorder,postorder,0,postorder.size()-1);
    }
};