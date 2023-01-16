// 57. Insert Interval
// Problem Link - https://leetcode.com/problems/insert-interval/submissions/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end()); 
        intervals.push_back({100001,100002});
        vector<vector<int>> answer;
        int startOfCurrOverlappingInterval=-1;
        int endOfCurrOverlappingInterval=-1;
        for(int i=0;i<intervals.size();i++){
            if(i!=intervals.size()-1 && intervals[i][1]<intervals[i+1][0]){
                answer.push_back(intervals[i]);
            }else{
                startOfCurrOverlappingInterval=intervals[i][0];
                endOfCurrOverlappingInterval=intervals[i][1];
                while(i!=intervals.size()-1 && endOfCurrOverlappingInterval>=intervals[i+1][0]){
                    i++;
                    endOfCurrOverlappingInterval=max(endOfCurrOverlappingInterval,intervals[i][1]);
                }
                answer.push_back({startOfCurrOverlappingInterval,endOfCurrOverlappingInterval});
            }
        }
        answer.pop_back();
        return answer; 
    }
};