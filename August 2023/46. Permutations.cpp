// 46. Permutations
// Problem Link - https://leetcode.com/problems/permutations/

// TC - O(N!*N)
// SC - O(N)

class Solution {
public:
    vector<vector<int>> answer;
    
    void getPermutation(vector<int> &nums,vector<int> temp){
        if(temp.size()==nums.size()){
            answer.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            bool found=false;
            for(int j=0;j<temp.size();j++){
                if(temp[j]==nums[i]){
                    found=true;
                    break;
                }
            }
            if(found==false){
                temp.push_back(nums[i]);
                getPermutation(nums,temp);
                temp.pop_back();
            }
        }
        return;
    }
    
    vector<vector<int>> permute(vector<int>& nums){
        vector<int> temp;
        getPermutation(nums,temp);
        return answer;
    }
};
