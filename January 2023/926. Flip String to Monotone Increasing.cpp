// 926. Flip String to Monotone Increasing
// Problem Link - https://leetcode.com/problems/flip-string-to-monotone-increasing/

class Solution {
public:
    int minFlipsMonoIncr(string s){
        int countZero=0;
        int countOne=0;
        int answer=INT_MAX;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                countZero++;
            }
        }
        for(int i=0;i<s.size();i++){
            answer=min(answer,countZero+countOne);
            if(s[i]=='0'){
                countZero--;
            }else{
                countOne++;
            }
        }
        answer=min(answer,countZero+countOne);
        return answer;
    }
};
