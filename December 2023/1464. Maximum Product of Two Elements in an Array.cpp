// 1464. Maximum Product of Two Elements in an Array
// Problem Link - https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxNum1=-1;
        int maxNum2=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxNum1){
                maxNum2=maxNum1;
                maxNum1=nums[i];
            }else if(nums[i]==maxNum1){
                maxNum2=nums[i];
            }else{
                maxNum2=max(maxNum2,nums[i]);
            }
        }
        return (maxNum1-1)*(maxNum2-1);
    }
};
