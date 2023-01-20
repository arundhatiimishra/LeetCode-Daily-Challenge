// 491. Non-decreasing Subsequences
// Problem Link - https://leetcode.com/problems/non-decreasing-subsequences/submissions/

class Solution {
public:
    map<vector<int>,int> mp;
    vector<vector<int>> answer;
    
    void findAllSubsequence(vector<int> &nums,int currIndex,vector<int> temp){
        if(temp.size()>=2){
            mp[temp]++;
        }
        if(currIndex==nums.size()){
            return;
        }
        if(temp.size()==0){
            findAllSubsequence(nums,currIndex+1,temp);
            temp.push_back(nums[currIndex]);
            findAllSubsequence(nums,currIndex+1,temp);
        }else{
            if(temp[temp.size()-1]<=nums[currIndex]){
                findAllSubsequence(nums,currIndex+1,temp);
                temp.push_back(nums[currIndex]);
                findAllSubsequence(nums,currIndex+1,temp);
            }else{
                findAllSubsequence(nums,currIndex+1,temp);
            }
        }
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums){
        vector<int> temp;
        findAllSubsequence(nums,0,temp);
        map<vector<int>,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            answer.push_back(it->first);
        }
        return answer;
    }
};
