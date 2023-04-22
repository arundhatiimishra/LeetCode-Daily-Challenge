// 1312. Minimum Insertion Steps to Make a String Palindrome
// Problem Link - https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

class Solution {
public:
    int lIS(string s1,string s2,int i,int j,vector<vector<int>> &dp){
        for(int i=0;i<s1.size();i++){
            for(int j=0;j<s1.size();j++){
                if(s1[i]==s2[j]){
                    dp[i+1][j+1]=dp[i][j]+1;
                }else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
    
    int minInsertions(string s){
        string temp=s;
        reverse(temp.begin(),temp.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1,0));
        int common=lIS(s,temp,s.size()-1,s.size()-1,dp);
        return (s.size()-common); 
    }
};
