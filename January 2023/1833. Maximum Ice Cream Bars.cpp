// 1833. Maximum Ice Cream Bars
// Problem Link - https://leetcode.com/problems/maximum-ice-cream-bars/

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        priority_queue<int,vector<int>,greater<int>> pq;
        int countIceCreams=0;
        for(int i=0;i<costs.size();i++){
            pq.push(costs[i]);
        }
        while(pq.empty()==false){
            if(coins<pq.top()){
                break;
            }
            coins=coins-pq.top();
            countIceCreams++;
            pq.pop();
        }
        return countIceCreams; 
    }
};