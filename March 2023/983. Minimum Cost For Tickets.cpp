// 983. Minimum Cost For Tickets
// Problem Link - https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int minCost(vector<int> &days,int idx,vector<int> &costs,vector<int> &dp){
        if(idx>days.size()-1){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int x1=0,x2=0,x3=0;
        x1=minCost(days,idx+1,costs,dp)+costs[0];
        int ptr=idx;
        while(true){
            if(ptr<=days.size()-1 && days[ptr]<days[idx]+7){
                ptr++;
            }else{
                break;
            }
        }
        x2=minCost(days,ptr,costs,dp)+costs[1];
        ptr=idx;
        while(true){
            if(ptr<=days.size()-1 && days[ptr]<days[idx]+30){
                ptr++;
            }else{
                break;
            }
        }
        x3=minCost(days,ptr,costs,dp)+costs[2];
        return dp[idx]=min(x1,min(x2,x3)); 
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs){
        vector<int> dp(days.size(),-1);
        return minCost(days,0,costs,dp);  
    }
};
