// 2610. Convert an Array Into a 2D Array With Conditions
// Problem Link - https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/

// Time Complexity -  O(N)
// Space Complexity - O(N)

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int maxSize=0;
        vector<int> freq(201,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            maxSize=max(maxSize,freq[nums[i]]);
        }
        vector<vector<int>> answer(maxSize);
        for(int i=0;i<nums.size();i++){
            answer[freq[nums[i]]-1].push_back(nums[i]);
            freq[nums[i]]--;
        }
        return answer;
    }
};