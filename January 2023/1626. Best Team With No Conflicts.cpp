// 1626. Best Team With No Conflicts
// Problem Link - https://leetcode.com/problems/best-team-with-no-conflicts/

class Solution {
public:
    int maxScore=0;
    
    void findMaxOverallScore(vector<pair<int,int>> &ageScores,int score,int n,pair<int,int> p1){
        if(n==-1){
            maxScore=max(maxScore,score);
            return;
        }
        if(p1.first==-1 && p1.second==-1){
            findMaxOverallScore(ageScores,score,n-1,p1);
            findMaxOverallScore(ageScores,score+ageScores[n].second,n-1,ageScores[n]);
        }else if(ageScores[n].first<p1.first && ageScores[n].second>p1.second){
            findMaxOverallScore(ageScores,score,n-1,p1);
        }else{
            findMaxOverallScore(ageScores,score,n-1,p1);
            findMaxOverallScore(ageScores,score+ageScores[n].second,n-1,ageScores[n]);
        }
    }
        
    int bestTeamScore(vector<int>& scores, vector<int>& ages){
        vector<pair<int,int>> ageScores;
        for(int i=0;i<scores.size();i++){
            ageScores.push_back(make_pair(ages[i],scores[i]));
        }
        sort(ageScores.begin(),ageScores.end());
        findMaxOverallScore(ageScores,0,scores.size()-1,{-1,-1});
        return maxScore;
    }
};
