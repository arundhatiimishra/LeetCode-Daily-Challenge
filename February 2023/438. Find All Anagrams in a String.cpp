// 438. Find All Anagrams in a String
// Problem Link - https://leetcode.com/problems/find-all-anagrams-in-a-string/

class Solution {
public:
    vector<int> findAnagrams(string s, string p){
        if(s.size()<p.size()){
            return {};
        }
        vector<int> charCountOfp(26,0);
        vector<int> charCountOfs(26,0);
        for(int i=0;i<p.size();i++){
            charCountOfp[p[i]-'a']++;
            charCountOfs[s[i]-'a']++;
        }
        vector<int> answer;
        if(charCountOfs==charCountOfp){
            answer.push_back(0);
        }
        for(int i=p.size();i<s.size();i++){
            charCountOfs[s[i]-'a']++;
            charCountOfs[s[i-p.size()]-'a']--;
            if(charCountOfp==charCountOfs){
                answer.push_back(1+i-p.size());
            }
        }
        return answer; 
    }
};
