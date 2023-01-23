// 997. Find the Town Judge
// Problem Link - https://leetcode.com/problems/find-the-town-judge/

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust){
        vector<int> trust1(n+1,0);
        vector<int> trust2(n+1,0);
        for(int i=0;i<trust.size();i++){
            trust1[trust[i][0]]++;
        }
        int townJudge=-1;
        for(int i=0;i<=n;i++){
            if(townJudge!=-1 && i!=0 && trust1[i]==0){
                return -1;
            }
            if(i!=0 && trust1[i]==0){
                townJudge=i;
            }
        }
        for(int i=0;i<trust.size();i++){
            if(trust[i][1]==townJudge){
                trust2[trust[i][0]]++;
            }
        }
        for(int i=0;i<=n;i++){
            if(i!=0 && i==townJudge && trust2[i]!=0){
                return -1;
            }
            if(i!=0 && i!=townJudge && trust2[i]==0){
                return -1;
            }
        }
        return townJudge; 
    }
};