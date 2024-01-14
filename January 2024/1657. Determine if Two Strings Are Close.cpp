// 1657. Determine if Two Strings Are Close
// Problem Link - https://leetcode.com/problems/determine-if-two-strings-are-close/

// Time Complexity - O(N)
// Space Complexity - O(52)

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }
        vector<int> freqWord1(26,0);
        vector<int> freqWord2(26,0);
        for(int i=0;i<word1.size();i++){
            freqWord1[word1[i]-'a']++;
            freqWord2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freqWord1[i]==0 && freqWord2[i]!=0){
                return false;
            }
            if(freqWord1[i]!=0 && freqWord2[i]==0){
                return false;
            }
        }
        sort(freqWord1.begin(),freqWord1.end());
        sort(freqWord2.begin(),freqWord2.end());
        if(freqWord1==freqWord2){
            return true;
        }
        return false;        
    }
};