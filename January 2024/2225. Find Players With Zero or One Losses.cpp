// 2225. Find Players With Zero or One Losses
// Problem Link - https://leetcode.com/problems/find-players-with-zero-or-one-losses/

// Time Complexity - O(N*log N)
// Space Complexity - O(N)

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> mapping;
        unordered_map<int,int> reverse_mapping;
        int counter=0;
        for(int i=0;i<matches.size();i++){
            int first=matches[i][0];
            int second=matches[i][1];
            if(mapping.find(first)==mapping.end()){
                mapping[first]=counter;
                reverse_mapping[counter]=first;
                counter++;
            }
            if(mapping.find(second)==mapping.end()){
                mapping[second]=counter;
                reverse_mapping[counter]=second;
                counter++;
            }
        }
        vector<int> lostCount(mapping.size(),0);
        for(int i=0;i<matches.size();i++){
            int won=mapping[matches[i][0]];
            int lost=mapping[matches[i][1]];
            lostCount[lost]++;
        }
        vector<vector<int>> answer(2);
        for(int i=0;i<lostCount.size();i++){
            if(lostCount[i]==0){
                answer[0].push_back(reverse_mapping[i]);
            }
            if(lostCount[i]==1){
                answer[1].push_back(reverse_mapping[i]);
            }
        }
        sort(answer[0].begin(),answer[0].end());
        sort(answer[1].begin(),answer[1].end());
        return answer;  
    }
};