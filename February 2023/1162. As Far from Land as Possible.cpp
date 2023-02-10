// 1162. As Far from Land as Possible
// Problem Link - https://leetcode.com/problems/as-far-from-land-as-possible/

class Solution {
public:
    int findMinDist(vector<vector<int>> &grid,int i1,int j1){
        int minDist=INT_MAX;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    minDist=min(minDist,abs(i-i1)+abs(j-j1));
                }
            }
        }
        if(minDist==INT_MAX){
            return -1;
        }
        return minDist;
    }
    
    int maxDistance(vector<vector<int>>& grid){
        int answer=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==0){
                    answer=max(answer,findMinDist(grid,i,j));
                    if(answer==-1){
                        return -1;
                    }
                }
            }
        }
        return answer;
    }
};
