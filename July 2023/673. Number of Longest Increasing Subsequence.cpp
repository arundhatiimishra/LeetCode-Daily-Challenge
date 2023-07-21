// 673. Number of Longest Increasing Subsequence
// Problem Link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/

// Time COmplexity - O(N^2)
// Space Complexity - O(N)


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums){
        vector<pair<int,int>> longest(nums.size(),{0,1});
        int LISLength=0;
        for(int i=0;i<nums.size();i++){
            int maxTillNow=0;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    maxTillNow=max(maxTillNow,longest[j].first);
                } 
            }
            longest[i].first=maxTillNow+1;
            int countWays=0;
            for(int j=0;j<i;j++){
                if(longest[j].first==maxTillNow && nums[j]<nums[i]){
                    countWays+=longest[j].second;
                }  
            }
            LISLength=max(LISLength,longest[i].first);
            longest[i].second=max(1,countWays);
        }
        int numOfWays=0;
        for(int i=0;i<longest.size();i++){
            if(longest[i].first==LISLength){
                numOfWays+=longest[i].second;
            } 
        }
        return numOfWays;
    }
};
