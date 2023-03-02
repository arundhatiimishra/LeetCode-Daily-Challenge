// 131. Palindrome Partitioning
// Problem Link - https://leetcode.com/problems/palindrome-partitioning/ 

class Solution {
public:
    vector<vector<string>> v;
    
    bool checkPalindrome(string s){
        for(int i=0;i<s.size()/2;i++){
            if(s[i]!=s[s.size()-1-i]){
                return false;
            }
        }
        return true; 
    }
    
    bool isValid(vector<string> x){
        for(int i=0;i<x.size();i++){
            if(checkPalindrome(x[i])==false){
                return false;
            }
        }
        return true; 
    }
    
    void parts(string s,int index,vector<string> temp){
        if(index==s.size()){
            if(isValid(temp)==true){
                v.push_back(temp);
            }
            return;
        }
        if(temp.size()==0){
            string tempo="";
            tempo+=s[0];
            temp.push_back(tempo);
            parts(s,index+1,temp);
        }else{
            string tempo="";
            tempo+=s[index];
            temp.push_back(tempo);
            parts(s,index+1,temp);
            temp.pop_back();
            temp[temp.size()-1]+=s[index];
            parts(s,index+1,temp);  
        }  
    }
    
    vector<vector<string>> partition(string s){
        vector<string> temp;
        parts(s,0,temp);
        return v; 
    }
};
