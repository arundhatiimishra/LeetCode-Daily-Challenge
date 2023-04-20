// 662. Maximum Width of Binary Tree
// Problem Link - https://leetcode.com/problems/maximum-width-of-binary-tree/

class Solution{
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push(make_pair(root,1));
        unsigned long long leftMost=1;
        unsigned long long rightMost=1;
        unsigned long long answer=1;
        while(q.empty()==false){
            int size=q.size();
            for(unsigned long long i=1;i<=size;i++){
                TreeNode* temp=q.front().first;
                unsigned long long tempVal=q.front().second;
                q.pop();
                if(i==1){
                    leftMost=tempVal;
                }
                if(i==size){
                    rightMost=tempVal;
                }
                if(temp->left!=NULL){
                    q.push(make_pair(temp->left,tempVal*2-1));
                }
                if(temp->right!=NULL){
                    q.push(make_pair(temp->right,tempVal*2));
                }
            }
            answer=max(answer,1+rightMost-leftMost);
        }
        return answer;  
    }
};