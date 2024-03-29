// 1456. Maximum Number of Vowels in a Substring of Given Length
// Problem Link - https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k){
        int answer=0;
        int currCount=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                currCount++;
            }
        }
        answer=max(answer,currCount);
        for(int i=k;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
                currCount++;
            }
            if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='i'||s[i-k]=='o'||s[i-k]=='u'){
                currCount--;
            }
            answer=max(answer,currCount);
        }
        return answer;
    }
};
