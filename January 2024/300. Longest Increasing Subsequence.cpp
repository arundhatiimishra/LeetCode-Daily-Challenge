// 300. Longest Increasing Subsequence
// Problem Link - https://leetcode.com/problems/longest-increasing-subsequence/

// Time Complexity -  O(N*log N)
// Space Complexity - O(N)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> store;
        for(int i=0;i<nums.size();i++){
            if(store.size()==0){
                store.push_back(nums[i]);
            }else{
                if(store[store.size()-1]<nums[i]){
                    store.push_back(nums[i]);
                }else{
                    int pos=-1;
                    pos=lower_bound(store.begin(),store.end(),nums[i])-store.begin();
                    store[pos]=nums[i];
                }
            } 
        }
        return store.size();
    }
};