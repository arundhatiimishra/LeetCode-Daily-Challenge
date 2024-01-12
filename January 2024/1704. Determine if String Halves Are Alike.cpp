// 1704. Determine if String Halves Are Alike
// Problem Link - https://leetcode.com/problems/determine-if-string-halves-are-alike/

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    bool halvesAreAlike(string s) {
        int countVowels=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                if(i<s.size()/2){
                    countVowels++;
                }else{
                    countVowels--;
                }
            }
        }
        if(countVowels==0){
            return true;
        }
        return false;
    }
};