// 2300. Successful Pairs of Spells and Potions
// Problem Link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success){
        sort(potions.begin(),potions.end());
        vector<int> answer;
        for(int i=0;i<spells.size();i++){
            long long curr=spells[i];
            long long search=0;
            if(success%curr==0){
                search=success/curr;
            }else{
                search=(success/curr)+1;
            } 
            int idx=lower_bound(potions.begin(),potions.end(),search)-potions.begin();
            answer.push_back(potions.size()-idx);
        }
        return answer;   
    }
};
