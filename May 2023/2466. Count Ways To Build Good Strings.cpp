// 2466. Count Ways To Build Good Strings
// Problem Link - https://leetcode.com/problems/count-ways-to-build-good-strings/

class Solution {
public:
    int MOD=1e9+7;
    
    int countNumberOfGoodStrings(int low,int high,int zero,int one,int currStringSize,vector<int> &dp){
        if(currStringSize>high){
            return 0;
        }     
        if(dp[currStringSize]!=-1){
            return dp[currStringSize];
        }
        if(currStringSize<=high && currStringSize>=low){
            return dp[currStringSize]=(countNumberOfGoodStrings(low,high,zero,one,currStringSize+zero,dp)+countNumberOfGoodStrings(low,high,zero,one,currStringSize+one,dp)+1)%MOD;
        }
        return dp[currStringSize]=(countNumberOfGoodStrings(low,high,zero,one,currStringSize+zero,dp)+countNumberOfGoodStrings(low,high,zero,one,currStringSize+one,dp))%MOD;
    }
    
    int countGoodStrings(int low, int high, int zero, int one){
        vector<int> dp(high+1,-1);
        return countNumberOfGoodStrings(low,high,zero,one,0,dp);
    }
};
