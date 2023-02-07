// 904. Fruit Into Baskets
// Problem Link - https://leetcode.com/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits){ 
        if(fruits.size()<=2){
            return fruits.size();
        }
        int basket1=fruits[0]; 
        int basket2=-1; 
        int basket1Count=1;
        int basket2Count=0;
        int basket2Consecutive=0;
        int size=2;
        for(int i=1;i<fruits.size();i++){
            if(fruits[i]!=basket1 && basket2==-1){
                basket2=fruits[i];
                basket2Count++;
                basket2Consecutive++;
            }else if(basket2==-1 && fruits[i]==basket1){
                basket1Count++;
            }else if(fruits[i]==basket1||fruits[i]==basket2){
                if(fruits[i]==basket1){
                    int temp=basket1;
                    basket1=basket2;
                    basket2=temp;
                    temp=basket1Count;
                    basket1Count=basket2Count;
                    basket2Count=temp;
                    basket2Consecutive=1;
                    basket2Count++;
                }else{
                    basket2Count++;
                    basket2Consecutive++;
                } 
            }else{
                size=max(size,basket1Count+basket2Count);
                basket1=basket2;
                basket1Count=basket2Consecutive;
                basket2Count=1;
                basket2Consecutive=1;
                basket2=fruits[i];
            }
        }
        size=max(size,basket1Count+basket2Count);
        return size; 
    }
};