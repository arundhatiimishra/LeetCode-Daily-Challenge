// 953. Verifying an Alien Dictionary
// Problem Link - https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool isAsmallerthanEqualToB(string a,string b,unordered_map<char,int> &mp){
        for(int i=0;i<a.size();i++){
            if(mp[a[i]]>mp[b[i]]){
                return false;
            }else if(mp[a[i]]<mp[b[i]]){
                return true;
            }
        }
        if(a.size()==b.size()){
            return true;
        }
        if(a.size()<b.size()){
            return true;
        }
        return false;
    }
    
    bool isAlienSorted(vector<string>& words, string order){
        unordered_map<char,int> mp;
        for(int i=0;i<order.size();i++){
            mp[order[i]]=i;
        }
        for(int i=1;i<words.size();i++){
            if(isAsmallerthanEqualToB(words[i-1],words[i],mp)==false){
                return false;
            }
        }
        return true; 
    }
};
