// 1150. Check If a Number Is Majority Element in a Sorted Array
// Problem Link - https://leetcode.com/problems/check-if-a-number-is-majority-element-in-a-sorted-array/

class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target){
        int countTarget=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                countTarget++;
            }
        }
        if(countTarget>nums.size()/2){
            return true;
        }
        return false;
    }
};