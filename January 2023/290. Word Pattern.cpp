// 290. Word Pattern
// Problem Link - https://leetcode.com/problems/word-pattern/


class Solution {
public:
    bool wordPattern(string pattern, string s){
        vector<string> words;
        string currWord="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                words.push_back(currWord);
                currWord="";
            }else{
                currWord+=s[i];
            } 
        }
        words.push_back(currWord);
        if(pattern.size()!=words.size()){
            return false;
        }
        vector<string> mapCharToWords(26,"");
        for(int i=0;i<pattern.size();i++){
            if(mapCharToWords[int(pattern[i]-'a')]==""){
                mapCharToWords[int(pattern[i]-'a')]=words[i];
            }else{
                if(mapCharToWords[int(pattern[i]-'a')]!=words[i]){
                    return false;
                }
            }
        }
        for(int i=0;i<25;i++){
            for(int j=i+1;j<26;j++){
                if(mapCharToWords[i]==mapCharToWords[j] && mapCharToWords[i]!=""){
                    return false;
                }
            }
        }
        return true; 
    }
};
