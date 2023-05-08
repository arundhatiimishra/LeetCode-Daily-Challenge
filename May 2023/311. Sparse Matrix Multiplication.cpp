// 311. Sparse Matrix Multiplication
// Problem Link - https://leetcode.com/problems/sparse-matrix-multiplication/

class Solution {
public:
    int multiply(vector<vector<int>>& mat1,vector<vector<int>>& mat2,int row,int col){
        int curr=0;
        for(int i=0;i<mat1[0].size();i++){
            curr+=(mat1[row][i]*mat2[i][col]);    
        }
        return curr; 
    }
    
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2){
        vector<vector<int>> answer(mat1.size(),vector<int> (mat2[0].size(),0));
        for(int i=0;i<answer.size();i++){
            for(int j=0;j<answer[i].size();j++){
                answer[i][j]=multiply(mat1,mat2,i,j);
            }
        }
        return answer;
    }
};
