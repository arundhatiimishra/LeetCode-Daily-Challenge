// 35. Search Insert Position
// Problem Link - https://leetcode.com/problems/search-insert-position/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target){
        vector<int>::iterator it;
        it=lower_bound(nums.begin(),nums.end(),target);
        return it-nums.begin();
    }
};
