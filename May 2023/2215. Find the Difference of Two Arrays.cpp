// 2215. Find the Difference of Two Arrays
// Problem Link - https://leetcode.com/problems/find-the-difference-of-two-arrays/

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,bool> mp1;
        unordered_map<int,bool> mp2;
        for(int i=0;i<nums1.size();i++){
            mp1[nums1[i]]=true;
        }
        for(int i=0;i<nums2.size();i++){
            mp2[nums2[i]]=true;
        }
        vector<int> toPush1;
        vector<int> toPush2;
        for(int i=0;i<nums1.size();i++){
            if(mp2[nums1[i]]==false){
                toPush1.push_back(nums1[i]);
                mp2[nums1[i]]=true;
            }
        }
        for(int i=0;i<nums2.size();i++){
            if(mp1[nums2[i]]==false){
                toPush2.push_back(nums2[i]);
                mp1[nums2[i]]=true;
            }
        }
        vector<vector<int>> answer;
        answer.push_back(toPush1);
        answer.push_back(toPush2);
        return answer;
    }
};
