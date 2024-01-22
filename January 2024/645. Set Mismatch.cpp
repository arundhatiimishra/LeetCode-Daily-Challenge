// 645. Set Mismatch
// Problem Link - https://leetcode.com/problems/set-mismatch/

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int sum=0;
        vector<int> answer;
        for(int i=0;i<nums.size();i++){
            sum+=abs(nums[i]);
            if(nums[abs(nums[i])-1]<0){
                answer.push_back(abs(nums[i]));
            }else{
                nums[abs(nums[i])-1]*=(-1);
            }
        }
        int actualSum=((nums.size()*(nums.size()+1))/2);
        answer.push_back(actualSum-(sum-answer[0]));
        return answer;
    }
};