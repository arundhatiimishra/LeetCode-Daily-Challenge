// 1639. Number of Ways to Form a Target String Given a Dictionary
// Problem Link - https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/

class Solution {
public:
    int MOD=1e9+7;
    
    long long findNumOfWays(vector<string> &words,string &target,int idx,int x,vector<vector<int>> &store,vector<vector<int>> &dp){
        if(dp[idx][x+1]!=-1){
            return dp[idx][x+1];
        }
        if(idx>target.size()-1){
            return dp[idx][x+1]=1;
        }
        int temp=words[0].size()-1;
        if((target.size()-idx)>(temp-x)){
            return dp[idx][x+1]=0;
        }
        if(x>=temp){
            return dp[idx][x+1]=0;
        }
        long long answer=0;
        for(int i=x+1;i<=temp;i++){
            if(store[i][target[idx]-'a']>0){
                answer=answer+(store[i][target[idx]-'a']*findNumOfWays(words,target,idx+1,i,store,dp));
                if(answer>MOD){
                    answer%=MOD;
                }
            }
        }
        return dp[idx][x+1]=answer; 
    }
    
    int numWays(vector<string>& words, string target){
        vector<vector<int>> dp(target.size()+1,vector<int> (words[0].size()+1,-1));
        vector<vector<int>> store(words[0].size(),vector<int> (26,0));
        for(int j=0;j<words[0].size();j++){
            for(int i=0;i<words.size();i++){
                store[j][words[i][j]-'a']++;
            }
        }
        return findNumOfWays(words,target,0,-1,store,dp);
    }
};