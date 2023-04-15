// 2218. Maximum Value of K Coins From Piles
// Problem Link - https://leetcode.com/problems/maximum-value-of-k-coins-from-piles/

class Solution {
public:
    int getMaxProfit(vector<vector<int>> &piles,int k,int idx,vector<vector<int>> &dp){
        if(k<0){
            return INT_MIN;
        }
        if(k==0){
            return 0;
        }
        if(idx>piles.size()-1){
            return 0;
        }
        if(dp[idx][k]!=-1){
            return dp[idx][k];
        }
        int answer=0;
        answer=max(answer,getMaxProfit(piles,k,idx+1,dp));
        int sum=0;
        for(int i=0;i<piles[idx].size();i++){
            sum+=piles[idx][i];
            answer=max(answer,getMaxProfit(piles,k-i-1,idx+1,dp)+sum);
        }
        return dp[idx][k]=answer;
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k){
        vector<vector<int>> dp(piles.size(),vector<int>(k+1,-1));
        return getMaxProfit(piles,k,0,dp);
    }
};
