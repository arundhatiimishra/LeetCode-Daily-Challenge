// 452. Minimum Number of Arrows to Burst Balloons
// Problem Link - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points){
        sort(points.begin(),points.end());
        int currIntervalStart=points[0][0];
        int currIntervalEnd=points[0][1];
        int countArrows=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=currIntervalEnd){
                currIntervalStart=points[i][0];
                currIntervalEnd=min(currIntervalEnd,points[i][1]);
                
            }else{
                countArrows++;
                currIntervalStart=points[i][0];
                currIntervalEnd=points[i][1];
            }
        }
        return countArrows;
    }
};