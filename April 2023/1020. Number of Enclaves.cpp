// 1020. Number of Enclaves
// Problem Link - https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    int cells=0;
    
    bool isIsland(vector<vector<int>> &grid,vector<vector<int>> &vis,int i,int j){
        if(i==0||i==grid.size()-1||j==0||j==grid[0].size()-1){
            return false;
        }
        if(vis[i][j]==1){
            return true;
        }
        cells+=1;
        vis[i][j]=1;
        bool left=true;
        bool right=true;
        bool up=true;
        bool down=true;
        if(i!=0 && grid[i-1][j]==1){
            up=isIsland(grid,vis,i-1,j);
        }
        if(i!=grid.size()-1 && grid[i+1][j]==1){
            down=isIsland(grid,vis,i+1,j);
        }
        if(j!=0 && grid[i][j-1]==1){
            left=isIsland(grid,vis,i,j-1);
        }
        if(j!=grid[0].size()-1 && grid[i][j+1]==1){
            right=isIsland(grid,vis,i,j+1);
        }
        return left && right && up && down; 
    }
    
    int numEnclaves(vector<vector<int>>& grid){
        int countCells=0;
        vector<vector<int>> vis(grid.size(),vector<int> (grid[0].size(),0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==0){
                    vis[i][j]=1;
                    continue;
                }else{
                    if(vis[i][j]==1){
                        continue;
                    }else{
                        cells=0;
                        bool island=isIsland(grid,vis,i,j);
                        if(island==true){
                            countCells+=cells;
                        }
                    }
                }
            }
        }
        return countCells;
    }
};