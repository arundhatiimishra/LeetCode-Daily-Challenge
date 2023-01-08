// 149. Max Points on a Line
// Problem Link - https://leetcode.com/problems/max-points-on-a-line/


class Solution {
public:
    int maxPoints(vector<vector<int>>& points){
        int maximumPoints=0;
        for(int i=0;i<points.size();i++){
            unordered_map<float,int> mp;
            for(int j=0;j<points.size();j++){  
                if(i==j){
                    continue;
                }
                float currSlope=((float)points[i][1]-(float)points[j][1])/((float)points[i][0]-(float)points[j][0]);
                mp[currSlope]++;
            }
            unordered_map<float,int>::iterator it;
            int maxPointsOfSameSlopePassingFromI=0;
            for(it=mp.begin();it!=mp.end();it++){
                maxPointsOfSameSlopePassingFromI=max(it->second,maxPointsOfSameSlopePassingFromI);
            }
            maximumPoints=max(maximumPoints,maxPointsOfSameSlopePassingFromI+1);
        }
        return maximumPoints;
    }
};
