// 1572. Matrix Diagonal Sum
// Problem Link - https://leetcode.com/problems/matrix-diagonal-sum/

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat){
        int answer=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[i].size();j++){
                if(i==j||i+j==mat.size()-1){
                    answer+=mat[i][j];
                }
            }
        }
        return answer;
    }
};