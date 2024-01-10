// 2385. Amount of Time for Binary Tree to Be Infected
// Problem Link - https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/

// Time Complexity - O(8*N)
// Space Complexity - O(7*N)

class Solution {
public:
    unordered_map<int,int> mp;
    vector<vector<int>> adjList;
    int currMappingVal=0;
    vector<int> vis;
    
    void mapping(TreeNode* root){
        if(root==NULL){
            return;
        }
        mp[root->val]=currMappingVal;
        currMappingVal++;
        mapping(root->left);
        mapping(root->right);
    }
    
    void fillAdjList(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->left!=NULL){
            adjList[mp[root->val]].push_back(mp[root->left->val]);
            adjList[mp[root->left->val]].push_back(mp[root->val]);
        }
        if(root->right!=NULL){
            adjList[mp[root->val]].push_back(mp[root->right->val]);
            adjList[mp[root->right->val]].push_back(mp[root->val]);
        }
        fillAdjList(root->left);
        fillAdjList(root->right); 
    }
    
    int dfs(int node){
        vis[node]=1;
        int len=0;
        for(int i=0;i<adjList[node].size();i++){
            if(vis[adjList[node][i]]==0){
                len=max(len,1+dfs(adjList[node][i]));
            }
        }
        return len;
    }
        
    int sizeOfTree(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        return sizeOfTree(root->left)+sizeOfTree(root->right)+1;
    }
    
    int amountOfTime(TreeNode* root, int start) {
        int size=sizeOfTree(root);
        adjList.resize(size);
        mapping(root);
        fillAdjList(root);
        vis.resize(size,0);
        return dfs(mp[start]); 
    }
};