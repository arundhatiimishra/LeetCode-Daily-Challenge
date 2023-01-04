// 2244. Minimum Rounds to Complete All Tasks
// Problem Link - https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int countRounds=0;
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i]]++;
        }
        unordered_map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            if(it->second==1){
                return -1;
            }
            if(it->second==2||it->second==3){
                countRounds+=1;
            }else if(it->second%3==0){
                countRounds+=it->second/3;
            }else if(it->second%3==2){
                countRounds+=((it->second-2)/3)+1;
            }else if(it->second%3==1){
                countRounds+=((it->second-4)/3)+2;
            }
        }
        return countRounds;
    }
};
