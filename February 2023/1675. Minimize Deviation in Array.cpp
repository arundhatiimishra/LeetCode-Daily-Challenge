// 1675. Minimize Deviation in Array
// Problem Link - https://leetcode.com/problems/minimize-deviation-in-array/

class Solution {
public:
    int minimumDeviation(vector<int>& nums){
        int minValInNums=INT_MAX;
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2!=0){
                minValInNums=min(minValInNums,nums[i]*2);
                pq.push(nums[i]*2);
            }else{
                minValInNums=min(minValInNums,nums[i]);
                pq.push(nums[i]);
            }
        }
        int answer=INT_MAX;
        while(true){
            if(pq.top()%2==0){
                answer=min(answer,pq.top()-minValInNums);
                minValInNums=min(minValInNums,pq.top()/2);
                pq.push(pq.top()/2);
                pq.pop();
            }else{
                answer=min(answer,pq.top()-minValInNums);
                break;
            }
        }
        return answer;
    }
};
