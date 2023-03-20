// 605. Can Place Flowers
// Problem Link - https://leetcode.com/problems/can-place-flowers/

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n){    
        int count=0;
        for(int i=0;i<flowerbed.size();i++){
            if(flowerbed.size()==1 && flowerbed[0]==0){
                   count=1;
                   break;
            }
            if(i==0){
                if(flowerbed[i]==0 && i!=flowerbed.size()-1 && flowerbed[i+1]!=1){
                    flowerbed[i]=1;  
                    count++;
                }
            }else if(i==flowerbed.size()-1){
                if(flowerbed[i]==0 && flowerbed[i-1]!=1){
                    flowerbed[i]=1;
                    count++;
                }
            }else{
                if(flowerbed[i]==0 && i!=0 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                    flowerbed[i]=1;
                    count++;
                }
            }
        }
        if(count>=n){
            return true;
        }
        return false;
    }
};
