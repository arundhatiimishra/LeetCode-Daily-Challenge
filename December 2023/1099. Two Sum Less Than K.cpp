// 1099. Two Sum Less Than K
// Problem Link - https://leetcode.com/problems/two-sum-less-than-k/

// Time Complexity - O(N Log N)
// Space Complexity - O(1)

class Solution {
public:
    int twoSumLessThanK(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int maxSum=-1;
        int ptr1=0;
        int ptr2=nums.size()-1;
        while(ptr1<ptr2){
            if(nums[ptr1]+nums[ptr2]<k){
                maxSum=max(maxSum,nums[ptr1]+nums[ptr2]);
                ptr1++;
            }else{
                ptr2--;
            }
        }
        return maxSum;
    }
};
