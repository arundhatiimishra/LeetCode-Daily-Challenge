// 2444. Count Subarrays With Fixed Bounds
// Problem Link - https://leetcode.com/problems/count-subarrays-with-fixed-bounds/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK){
        long long answer=0;
        int lastInvalidIdx=-1;
        int minNumIdx=-1;
        int maxNumIdx=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<minK||nums[i]>maxK){
                lastInvalidIdx=i;
                minNumIdx=-1;
                maxNumIdx=-1;
            }else{
                if(nums[i]==minK){
                    minNumIdx=i;
                }
                if(nums[i]==maxK){
                    maxNumIdx=i;
                }
                if(minNumIdx!=-1 && maxNumIdx!=-1){
                    answer+=(min(minNumIdx,maxNumIdx)-lastInvalidIdx);
                }
            }
        }
        return answer;
    }
};