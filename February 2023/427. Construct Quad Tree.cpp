// 427. Construct Quad Tree
// Problem Link - https://leetcode.com/problems/construct-quad-tree/

class Solution {
public:
    Node* cons(vector<vector<int>> &grid,int startrow,int endrow,int startcol,int endcol){
        Node* temp=new Node(false,false);
        bool hasSame=true;
        int num=grid[startrow][startcol];
        for(int i=startrow;i<=endrow;i++){
            for(int j=startcol;j<=endcol;j++){
                if(grid[i][j]!=num){
                    hasSame=false;
                    break;
                } 
            }
        }
        if(hasSame==true){
            temp->isLeaf=1;
            temp->val=num;
            temp->topLeft=NULL;
            temp->topRight=NULL;
            temp->bottomLeft=NULL;
            temp->bottomRight=NULL;
        }else{
            temp->isLeaf=false;
            temp->val=num;
            temp->topLeft=cons(grid,startrow,(startrow+endrow-1)/2,startcol,(startcol+endcol-1)/2);
            temp->topRight=cons(grid,startrow,(startrow+endrow-1)/2,(startcol+endcol+1)/2,endcol);
            temp->bottomLeft=cons(grid,(startrow+endrow+1)/2,endrow,startcol,(startcol+endcol-1)/2);
            temp->bottomRight=cons(grid,(startrow+endrow+1)/2,endrow,(startcol+endcol+1)/2,endcol);
        }
        return temp;
    }
    
    Node* construct(vector<vector<int>>& grid){
        return cons(grid,0,grid.size()-1,0,grid[0].size()-1); 
    }
};