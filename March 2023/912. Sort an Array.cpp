// 912. Sort an Array
// Problem Link - https://leetcode.com/problems/sort-an-array/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int ptr=nums.size()-1;
        while(pq.empty()==false){
            nums[ptr]=pq.top();
            pq.pop();
            ptr--;
        }
        return nums;
    }
};
