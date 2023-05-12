// 2140. Solving Questions With Brainpower
// Problem Link - https://leetcode.com/problems/solving-questions-with-brainpower/

class Solution {
public:
    long long findMaxPoints(vector<vector<int>> &questions,int idx,vector<long long> &dp){
        if(idx>questions.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        return dp[idx]=max(findMaxPoints(questions,idx+1,dp),findMaxPoints(questions,idx+questions[idx][1]+1,dp)+questions[idx][0]); 
    }
    
    long long mostPoints(vector<vector<int>>& questions){
        vector<long long> dp(questions.size(),-1);
        return findMaxPoints(questions,0,dp);
    }
};
