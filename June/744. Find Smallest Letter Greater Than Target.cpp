// 744. Find Smallest Letter Greater Than Target
// Problem Link - https://leetcode.com/problems/find-smallest-letter-greater-than-target/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target){
        int answer=INT_MAX;
        for(int i=0;i<letters.size();i++){
            if((int)letters[i]>(int)target){
                answer=min(answer,(int)letters[i]);
            }
        }
        if(answer==INT_MAX){
            return letters[0];
        }
        return (char)(answer);
    }
};
