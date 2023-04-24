// 1046. Last Stone Weight
// Problem Link - https://leetcode.com/problems/last-stone-weight/

class Solution{
public:
    int lastStoneWeight(vector<int>& stones){
        priority_queue<int> pq;
        for(int i=0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(true){
            if(pq.size()==1){
                return pq.top();
            }
            if(pq.empty()==true){
                break;
            }
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();
            if(top1!=top2){
                pq.push(abs(top1-top2));
            }
        }  
        return 0;
    }
};
