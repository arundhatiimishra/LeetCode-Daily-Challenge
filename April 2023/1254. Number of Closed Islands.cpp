// 1254. Number of Closed Islands
// Problem Link - https://leetcode.com/problems/number-of-closed-islands/

class Solution {
public:
    int countIslands=0;
    
    bool toCheckIsland(vector<vector<int>> &grid,vector<vector<int>> &vis,int i,int j){
        if(i==0||i==grid.size()-1||j==0||j==grid[0].size()-1){
            return false;
        }
        if(vis[i][j]==1){
            return true;
        }
        vis[i][j]=1;
        bool left=true;
        bool right=true;
        bool up=true;
        bool down=true;
        if(i!=0 && grid[i-1][j]==0){
            up=toCheckIsland(grid,vis,i-1,j);
        }
        if(i!=grid.size()-1 && grid[i+1][j]==0){
            down=toCheckIsland(grid,vis,i+1,j);
        }
        if(j!=0 && grid[i][j-1]==0){
            left=toCheckIsland(grid,vis,i,j-1);
        }
        if(j!=grid[0].size()-1 && grid[i][j+1]==0){
            right=toCheckIsland(grid,vis,i,j+1);
        }
        return left && right && up && down; 
    }
    
    int closedIsland(vector<vector<int>>& grid){
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    vis[i][j]=1;
                    continue;
                }else{
                    if(vis[i][j]==0){
                        if(toCheckIsland(grid,vis,i,j)==true){
                            countIslands++;
                        }
                    }else{
                        continue;
                    }
                }
            }
        }
        return countIslands; 
    }
};
