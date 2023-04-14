// 516. Longest Palindromic Subsequence
// Problem Link - https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:
    int lengthOfLPS(string &s,string &t,int i,int j,vector<vector<int>> &dp){
        if(i<0||j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return dp[i][j]=lengthOfLPS(s,t,i-1,j-1,dp)+1;
        }
        return dp[i][j]=max(lengthOfLPS(s,t,i-1,j,dp),lengthOfLPS(s,t,i,j-1,dp));
    }
    
    int longestPalindromeSubseq(string s){
        string t=s;
        reverse(t.begin(),t.end());
        vector<vector<int>> dp(s.size(),vector<int> (t.size(),-1));
        return lengthOfLPS(s,t,s.size()-1,s.size()-1,dp);        
    }
};
