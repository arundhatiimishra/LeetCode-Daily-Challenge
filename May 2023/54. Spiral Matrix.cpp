// 54. Spiral Matrix
// Problem Link - https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> answer;
        int rowStart=0;
        int colStart=0;
        int rowEnd=matrix.size()-1;
        int colEnd=matrix[0].size()-1;
        while(true){
            if(colStart>colEnd){
                break;
            }
            for(int i=colStart;i<=colEnd;i++){
                answer.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            if(rowStart>rowEnd){
                break;
            }
            for(int i=rowStart;i<=rowEnd;i++){
                answer.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            if(colStart>colEnd){
                break;
            }
            for(int i=colEnd;i>=colStart;i--){
                answer.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            if(rowStart>rowEnd){
                break;
            }
            for(int i=rowEnd;i>=rowStart;i--){
                answer.push_back(matrix[i][colStart]);
            }
            colStart++;
        }
        return answer;  
    }
};
