// 1688. Count of Matches in Tournament
// Problem Link - https://leetcode.com/problems/count-of-matches-in-tournament/

// Time Complexity - O(log N)
// Space Complexity - O(log N)

class Solution {
public:
    int getAnswer(int teams){
        if(teams==1){
            return 0;
        }
        if(teams%2==0){
            return getAnswer(teams/2)+teams/2;
        }else{
            return getAnswer((teams-1)/2+1)+teams/2;
        }
    }
    
    int numberOfMatches(int n) {
        return getAnswer(n);
    }
};


// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution {
public:
    int numberOfMatches(int n) {
        return n-1;
    }
};