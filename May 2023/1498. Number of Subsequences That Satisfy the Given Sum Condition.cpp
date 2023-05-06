// 1498. Number of Subsequences That Satisfy the Given Sum Condition
// Problem Link - https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

class Solution {
public:
    int numSubseq(vector<int>& nums, int target){
        int MOD=1e9+7;
        int answer=0;
        vector<int> powerOf2(nums.size()+1,1);
        for(int i=1;i<nums.size()+1;i++){
            powerOf2[i]=(powerOf2[i-1]*2)%MOD;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            int find=target-nums[i];
            int idx=upper_bound(nums.begin(),nums.end(),find)-nums.begin()-1;
            if(idx<i){
                break;
            }
            answer=(answer+powerOf2[idx-i])%MOD;
            if(answer>MOD){
                answer%=MOD;
            }
        }
        return answer;
    }
};