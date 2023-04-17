// 1431. Kids With the Greatest Number of Candies
// Problem Link - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies){
        int greatestNum=0;
        for(int i=0;i<candies.size();i++){
            greatestNum=max(greatestNum,candies[i]);
        }
        vector<bool> answer(candies.size(),false);
        for(int i=0;i<candies.size();i++){
            if(candies[i]+extraCandies>=greatestNum){
                answer[i]=true;
            }
        }
        return answer;
    }
};
