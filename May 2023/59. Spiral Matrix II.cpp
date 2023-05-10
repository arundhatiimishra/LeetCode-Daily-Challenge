// 59. Spiral Matrix II
// Problem Link - https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        vector<vector<int>> answer(n,vector<int>(n,0));
        int currNum=1;
        int rowStart=0;
        int colStart=0;
        int rowEnd=n-1;
        int colEnd=n-1;
        while(true){
            if(colStart>colEnd||rowStart>rowEnd){
                break;
            }
            for(int i=colStart;i<=colEnd;i++){
                answer[rowStart][i]=currNum;
                currNum++;
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd;i++){
                answer[i][colEnd]=currNum;
                currNum++;
            }
            colEnd--;
            for(int i=colEnd;i>=colStart;i--){
                answer[rowEnd][i]=currNum;
                currNum++;
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart;i--){
                answer[i][colStart]=currNum;
                currNum++;
            }
            colStart++;
        }
        return answer;
    }
};
