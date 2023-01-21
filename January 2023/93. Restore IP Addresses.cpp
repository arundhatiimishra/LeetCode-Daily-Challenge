// 93. Restore IP Addresses
// Problem Link - https://leetcode.com/problems/restore-ip-addresses/

class Solution {
public:
    vector<string> answer;
    
    bool checkValidity(string s){
        if(s[0]=='.'){
            return false;
        }
        if(s[s.size()-1]=='.'){
            return false;
        }
        int countDots=0;
        string currString="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='.'){
                countDots++;
                if(currString.size()>3){
                    return false;
                }
                if(currString.size()>1 && currString[0]=='0'){
                    return false;
                }
                if(stoi(currString)>255){
                    return false;
                }
                currString="";  
            }else{
                currString+=s[i];
            }
        }
        if(currString.size()>3){
            return false;
        }
        if(currString.size()>1 && currString[0]=='0'){
            return false;
        }
        if(stoi(currString)>255){
            return false;
        }
        if(countDots!=3){
            return false;
        }
        return true;
    }
    
    vector<string> restoreIpAddresses(string s){
        for(int i=0;i<s.size();i++){
            for(int j=i+1;j<s.size();j++){
                for(int k=j+1;k<s.size();k++){
                    string newIpAdd="";
                    for(int l=0;l<s.size();l++){
                        newIpAdd+=s[l];
                        if(l==i||l==j||l==k){
                            newIpAdd+=".";
                        }
                    }
                    if(checkValidity(newIpAdd)==true){
                        answer.push_back(newIpAdd);
                    }
                }
            }
        }
        return answer;
    }
};