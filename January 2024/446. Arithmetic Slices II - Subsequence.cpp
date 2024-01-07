// 446. Arithmetic Slices II - Subsequence
// Problem Link - https://leetcode.com/problems/arithmetic-slices-ii-subsequence/

// Time Complexity -  O(N^2)
// Space Complexity - O(N^2)

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) { 
        long long count=0;
        vector<unordered_map<long long,long long>> dp(nums.size());
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                long long diff=(long long)nums[i]-(long long)nums[j];
                if(dp[j].find(diff)==dp[j].end()){
                    count+=0;
                    dp[i][diff]+=1;
                }else{
                    count+=dp[j][diff];
                    dp[i][diff]+=(dp[j][diff]+1);
                }
            }
        }
        return count;
    }
};