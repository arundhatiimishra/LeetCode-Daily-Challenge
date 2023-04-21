// 879. Profitable Schemes
// Problem Link - https://leetcode.com/problems/profitable-schemes/

class Solution {
public:
    int MOD=1e9+7;
    
    long long getAns(int n,int minProfit,vector<int> &group,vector<int> &profit,int idx,int currN,int currProfit,vector<vector<vector<int>>> &dp){
        if(currN>n){
            return dp[idx][currN][currProfit]=0;
        }
        if(currProfit>minProfit){
            currProfit=minProfit;
        }
        if(idx==profit.size()){
            if(currN<=n && currProfit>=minProfit){
                return dp[idx][currN][currProfit]=1;
            }
            return dp[idx][currN][currProfit]=0;
        }
        if(dp[idx][currN][currProfit]!=-1){
            return dp[idx][currN][currProfit];
        }
        if(currN+group[idx]<=n){
            return dp[idx][currN][currProfit]=((getAns(n,minProfit,group,profit,idx+1,currN,currProfit,dp)+getAns(n,minProfit,group,profit,idx+1,currN+group[idx],currProfit+profit[idx],dp)))%MOD; 
        }else{
            return dp[idx][currN][currProfit]=getAns(n,minProfit,group,profit,idx+1,currN,currProfit,dp)%MOD;
        }
    }
        
    int profitableSchemes(int n,int minProfit,vector<int>& group,vector<int>& profit){
        vector<vector<vector<int>>> dp(group.size()+1,vector<vector<int>> (n+1,vector<int> (minProfit+1,-1)));
        long long answer=getAns(n,minProfit,group,profit,0,0,0,dp);
        return answer;
    }
};