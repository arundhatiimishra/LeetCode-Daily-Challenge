// 567. Permutation in String
// Problem Link - https://leetcode.com/problems/permutation-in-string/

class Solution {
public:
    bool checkInclusion(string s1, string s2){
        if(s2.size()<s1.size()){
            return false;
        }
        vector<int> charCountOfs1(26,0);
        vector<int> charCountOfs2(26,0);
        for(int i=0;i<s1.size();i++){
            charCountOfs1[s1[i]-'a']++;
            charCountOfs2[s2[i]-'a']++;
        }
        if(charCountOfs1==charCountOfs2){
            return true;
        }
        for(int i=s1.size();i<s2.size();i++){ 
            charCountOfs2[s2[i-s1.size()]-'a']--;
            charCountOfs2[s2[i]-'a']++;
            if(charCountOfs1==charCountOfs2){
                return true;
            }
        }
        return false;  
    }
};
