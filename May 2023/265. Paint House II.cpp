// 265. Paint House II
// Problem Link - https://leetcode.com/problems/paint-house-ii/

class Solution {
public:
    int findMinCost(vector<vector<int>> &costs,int idx,int doNotPaintWith,vector<vector<int>> &dp){
        if(idx>costs.size()-1){
            return 0; 
        }
        if(dp[idx][doNotPaintWith]!=-1){
            return dp[idx][doNotPaintWith];
        }
        int answer=INT_MAX;
        for(int i=0;i<costs[idx].size();i++){
            int take=INT_MAX;
            if(i!=doNotPaintWith){
                answer=min(answer,findMinCost(costs,idx+1,i,dp)+costs[idx][i]);  
            }        
        }
        return dp[idx][doNotPaintWith]=answer;
    }
    
    int minCostII(vector<vector<int>>& costs){
        vector<vector<int>> dp(costs.size(),vector<int> (22,-1));
        return findMinCost(costs,0,21,dp);
    }
};