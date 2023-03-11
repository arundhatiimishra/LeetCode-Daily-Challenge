// 109. Convert Sorted List to Binary Search Tree
// Problem Link - https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/

class Solution {
public:
    TreeNode* makeBST(int start,int end,vector<int> &nodes){
        if(start>end){
            return NULL;
        }
        int mid=(start+end)/2;
        TreeNode* root=new TreeNode(nodes[mid]);
        root->left=makeBST(start,mid-1,nodes);
        root->right=makeBST(mid+1,end,nodes);
        return root;
    }
    
    TreeNode* sortedListToBST(ListNode* head){
        if(head==NULL){
            return NULL;
        }
        vector<int> nodes;
        ListNode* temp=head;
        while(temp!=NULL){
            nodes.push_back(temp->val);
            temp=temp->next;
        }
        return makeBST(0,nodes.size()-1,nodes);  
    }
};
