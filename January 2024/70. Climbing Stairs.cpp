// 70. Climbing Stairs
// Problem Link - https://leetcode.com/problems/climbing-stairs/

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int countDistinctWays(int n,vector<int> &dp){
        if(n<0){
            return 0;
        }
        if(n==0){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=countDistinctWays(n-1,dp)+countDistinctWays(n-2,dp);
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return countDistinctWays(n,dp);
    }
};