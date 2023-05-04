// 649. Dota2 Senate
// Problem Link - https://leetcode.com/problems/dota2-senate/

class Solution {
public:
    string predictPartyVictory(string senate){
        queue<char> q;
        for(int i=0;i<senate.size();i++){
            q.push(senate[i]);
        }
        int banRCount=0;
        int banDCount=0;
        int count=0;
        while(q.size()!=1){
            count++;
            if(q.front()=='R'){
                if(banRCount==0){
                    banDCount++;
                    q.pop();
                    q.push('R');
                }else{
                    q.pop();
                    banRCount--;
                }
            }else{
                if(banDCount==0){
                    banRCount++;
                    q.pop();
                    q.push('D');
                }else{
                    q.pop();
                    banDCount--;
                }
            }
            if(count>1e5){
                break;
            }
        }
        if(q.front()=='R'){
            return "Radiant";
        }
        return "Dire"; 
    }
};