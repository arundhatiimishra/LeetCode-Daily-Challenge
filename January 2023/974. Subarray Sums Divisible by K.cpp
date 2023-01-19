// 974. Subarray Sums Divisible by K
// Problem Link - https://leetcode.com/problems/subarray-sums-divisible-by-k/

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k){
        int answer=0;
        vector<int> temp(k,0);
        for(int i=0;i<nums.size();i++){
            if(i!=0){
                nums[i]=nums[i-1]+nums[i];
            }
            if(nums[i]%k>=0){
                temp[nums[i]%k]++;
            }else{
                temp[(nums[i]%k)+k]++;
            }
        }
        for(int i=0;i<temp.size();i++){
            answer+=(temp[i]*(temp[i]-1)/2);
        }
        return answer+temp[0]; 
    }
};
