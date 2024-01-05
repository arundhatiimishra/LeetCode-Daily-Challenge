// 2870. Minimum Number of Operations to Make Array Empty
// Problem Link - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

// Time Complexity -  O(N)
// Space Complexity - O(N)

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int countOp=0;
        unordered_map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==1){
                return -1;
            }
            if(it->second%3==0){
                countOp+=(it->second/3);
            }else if(it->second%3==1){
                countOp+=(it->second/3)+1;
            }else{
                countOp+=(it->second/3)+1;
            }
        }
        return countOp;
    }
};