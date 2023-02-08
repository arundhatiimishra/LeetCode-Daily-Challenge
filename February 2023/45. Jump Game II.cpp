// 45. Jump Game II
// Problem Link - https://leetcode.com/problems/jump-game-ii/submissions/

class Solution {
public:
    int jumpCount(vector<int> &nums,int i,vector<int> &dp){
        if(i>nums.size()-1){
            return 1e8;
        }
        if(i==nums.size()-1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int answer=1e8;
        for(int j=i+1;j<=i+nums[i];j++){
            answer=min(answer,jumpCount(nums,j,dp)+1);  
        }
        return dp[i]=answer;
    }
    
    int jump(vector<int>& nums){
        vector<int> dp(nums.size(),-1);
        return jumpCount(nums,0,dp);
    }
};