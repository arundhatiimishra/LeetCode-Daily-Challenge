// 1235. Maximum Profit in Job Scheduling
// Problem Link - https://leetcode.com/problems/maximum-profit-in-job-scheduling/

// Time Complexity -  O(N*log N)
// Space Complexity - O(N)

class Solution {
public:
    int getMaxProfit(vector<int> &startTime,vector<vector<int>> &store,int currIdx,vector<int> &dp){
        if(currIdx==startTime.size()){
            return 0;
        }
        if(dp[currIdx]!=-1){
            return dp[currIdx];
        }
        int nextIdx=lower_bound(startTime.begin()+currIdx,startTime.end(),store[currIdx][1])-startTime.begin();
        return dp[currIdx]=max(getMaxProfit(startTime,store,currIdx+1,dp),getMaxProfit(startTime,store,nextIdx,dp)+store[currIdx][2]);  
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> store;
        for(int i=0;i<startTime.size();i++){
            store.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(store.begin(),store.end());
        sort(startTime.begin(),startTime.end());
        vector<int> dp(startTime.size()+2,-1);
        return getMaxProfit(startTime,store,0,dp);
    }
};