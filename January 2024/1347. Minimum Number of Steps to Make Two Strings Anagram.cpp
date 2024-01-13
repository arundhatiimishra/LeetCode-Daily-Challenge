// 1347. Minimum Number of Steps to Make Two Strings Anagram
// Problem Link - https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/

// Time Complexity - O(N)
// Space Complexity - O(26)

class Solution {
public:
    int minSteps(string s, string t) {
        int count=0;
        vector<int> sCount(26,0);
        for(int i=0;i<s.size();i++){
            sCount[s[i]-'a']++;
            sCount[t[i]-'a']--;
        }
        for(int i=0;i<26;i++){
            count+=abs(sCount[i]);
        }
        return count/2;
    }
};