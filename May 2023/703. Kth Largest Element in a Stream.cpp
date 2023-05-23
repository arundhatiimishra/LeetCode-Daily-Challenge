// 703. Kth Largest Element in a Stream
// Problem Link - https://leetcode.com/problems/kth-largest-element-in-a-stream/

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int ourK=0;
    
    KthLargest(int k,vector<int>& nums){
        ourK=k; 
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        while(true){
            if(pq.size()>ourK){
                pq.pop();
            }else{
                break;
            }
        }
    }
    
    int add(int val){
        pq.push(val);
        if(pq.size()>ourK){
            pq.pop();
        }
        return pq.top();
    }
};
