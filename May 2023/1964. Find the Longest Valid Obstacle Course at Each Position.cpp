// 1964. Find the Longest Valid Obstacle Course at Each Position
// Problem Link - https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles){
        vector<int> answer;
        vector<int> store;
        for(int i=0;i<obstacles.size();i++){
            if(i==0){
                store.push_back(obstacles[i]);
                answer.push_back(1);
            }else{
                if(obstacles[i]>=store[store.size()-1]){
                    store.push_back(obstacles[i]);
                    answer.push_back(store.size());
                }else{
                    int idx=upper_bound(store.begin(),store.end(),obstacles[i])-store.begin();
                    store[idx]=obstacles[i];
                    answer.push_back(idx+1);
                }   
            }   
        }
        return answer; 
    }
};
