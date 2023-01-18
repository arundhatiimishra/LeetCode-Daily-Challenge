// 918. Maximum Sum Circular Subarray
// Problem Link - https://leetcode.com/problems/maximum-sum-circular-subarray/submissions/

class Solution {
public:
    int minSum=0;
    int maxSum=0;
    int greatestNum=INT_MIN;
    bool containsPositiveNums=false;
    int sum=0;
    
    void minmaxSubarraySum(vector<int> &nums){
        int mincurrSum=0;
        int maxcurrSum=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                containsPositiveNums=true;
            }
            sum+=nums[i];
            greatestNum=max(greatestNum,nums[i]);
            mincurrSum+=nums[i];
            maxcurrSum+=nums[i];
            if(mincurrSum<minSum){
                minSum=mincurrSum;
            }
            if(maxcurrSum>maxSum){
                maxSum=maxcurrSum;
            }
            if(mincurrSum>0){
                mincurrSum=0;
            }
            if(maxcurrSum<0){
                maxcurrSum=0;
            }
        }
    }
    
    int maxSubarraySumCircular(vector<int>& nums){
        minmaxSubarraySum(nums);
        if(minSum==sum && containsPositiveNums==false){
            return greatestNum;
        }
        return max(maxSum,sum-minSum);
    }
};