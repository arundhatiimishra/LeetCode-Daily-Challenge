// 1266. Minimum Time Visiting All Points
// Problem Link - https://leetcode.com/problems/minimum-time-visiting-all-points/

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points){
        int answer=0;
        for(int i=1;i<points.size();i++){
            int x=abs(points[i-1][0]-points[i][0]);
            int y=abs(points[i-1][1]-points[i][1]);
            int moves=max(x,y);
            answer+=moves;
        }
        return answer;
    }
};
