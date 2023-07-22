// 688. Knight Probability in Chessboard
// Problem Link - https://leetcode.com/problems/knight-probability-in-chessboard/

// Time COmplexity - O(N*N*K)
// Space Complexity - O(N*N*K)

class Solution {
public:
    double insideChessBoard(int n,int k,int row,int col,vector<vector<vector<double>>> &dp){
        if(row>n-1||row<0||col>n-1||col<0){
            return 0.0;
        }
        if(k==0){
            return 1.0;
        }
        if(dp[row][col][k]!=-1.0){
            return dp[row][col][k];
        }
        double m1=insideChessBoard(n,k-1,row-1,col-2,dp);
        double m2=insideChessBoard(n,k-1,row-2,col-1,dp);
        double m3=insideChessBoard(n,k-1,row-2,col+1,dp);
        double m4=insideChessBoard(n,k-1,row-1,col+2,dp);
        double m5=insideChessBoard(n,k-1,row+1,col+2,dp);
        double m6=insideChessBoard(n,k-1,row+2,col+1,dp);
        double m7=insideChessBoard(n,k-1,row+2,col-1,dp);
        double m8=insideChessBoard(n,k-1,row+1,col-2,dp);
        return dp[row][col][k]=m1+m2+m3+m4+m5+m6+m7+m8;
    }
    
    double knightProbability(int n,int k,int row,int column){
        vector<vector<vector<double>>> dp(n+1,vector<vector<double>> (n+1,vector<double> (k+1,-1.0)));
        double inside=insideChessBoard(n,k,row,column,dp);
        double total=pow(8,k);
        double probability=inside/total;
        return probability;
    }
};
