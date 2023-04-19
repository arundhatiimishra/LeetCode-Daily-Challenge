// 1372. Longest ZigZag Path in a Binary Tree
// Problem Link - https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

class Solution {
public: 
    int answer=0;
    
    void getLength(TreeNode* root,bool left,int currLen){
        answer=max(answer,currLen);
        if(root==NULL){
            return;
        }
        if(left==true){
            getLength(root->left,false,currLen+1);
            getLength(root->right,true,1);
        }else{
            getLength(root->right,true,currLen+1);
            getLength(root->left,false,1);
        }   
    }
    
    int longestZigZag(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        getLength(root,false,0);
        getLength(root,true,0);
        return answer-1;
    }
};