// 1402. Reducing Dishes
// Problem Link - https://leetcode.com/problems/reducing-dishes/ 

class Solution {
public:
    int findMaxSatisfaction(vector<int> &satisfaction,int idx,int num,vector<vector<int>> &dp){  
        if(idx>satisfaction.size()-1){
            return 0;
        } 
        if(dp[idx][num]!=-1){
            return dp[idx][num];
        }
        return dp[idx][num]=max(findMaxSatisfaction(satisfaction,idx+1,num+1,dp)+satisfaction[idx]*num,findMaxSatisfaction(satisfaction,idx+1,num,dp));
    }
    
    int maxSatisfaction(vector<int>& satisfaction){
        sort(satisfaction.begin(),satisfaction.end());
        vector<vector<int>> dp(satisfaction.size(),vector<int>(satisfaction.size()+1,-1));
        return findMaxSatisfaction(satisfaction,0,1,dp);
    }
};
