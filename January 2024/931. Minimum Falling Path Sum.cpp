// 931. Minimum Falling Path Sum
// Problem Link - https://leetcode.com/problems/minimum-falling-path-sum/

// Time Complexity - O(N*M)
// Space Complexity - O(N*M)

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int answer=1e9;
        vector<vector<int>> dp=matrix;
        if(matrix.size()==1){
            for(int i=0;i<matrix[0].size();i++){
                answer=min(answer,matrix[0][i]);
            }
            return answer;
        }
        for(int i=1;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                int minVal=1e9;
                if(j-1>=0){
                    minVal=min(minVal,dp[i-1][j-1]);
                }
                if(j+1<matrix[0].size()){
                    minVal=min(minVal,dp[i-1][j+1]);
                }
                minVal=min(minVal,dp[i-1][j]);
                dp[i][j]=minVal+dp[i][j];
                if(i==matrix.size()-1){
                    answer=min(answer,dp[i][j]);
                }
            }
        }
        return answer;
    }
};