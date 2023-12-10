// 867. Transpose Matrix
// Problem Link - https://leetcode.com/problems/transpose-matrix/

// Time Complexity - O(N*M)
// Space Complexity - O(N*M)

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> transpose(matrix[0].size(),vector<int>(matrix.size(),-1));
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[i].size();j++){
                transpose[j][i]=matrix[i][j];
            }
        }
        return transpose;
    }
};
