// 704. Binary Search
// Problem Link - https://leetcode.com/problems/binary-search/

class Solution {
public:
    int findEle(vector<int> &nums,int target,int start,int end){
        if(start>end){
            return -1;
        }
        int mid=(start+end)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(nums[mid]>target){
            return findEle(nums,target,start,mid-1);
        }
        return findEle(nums,target,mid+1,end);
    }
    
    int search(vector<int>& nums,int target){
        return findEle(nums,target,0,nums.size()-1);
    }
};
