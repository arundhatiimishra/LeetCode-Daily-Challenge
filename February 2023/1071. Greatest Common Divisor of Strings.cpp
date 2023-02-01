// 1071. Greatest Common Divisor of Strings
// Problem Link - https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    bool adividesbCompletely(string a,string b){
        string temp=a;
        for(int i=0;i<INT_MAX;i++){
            if(temp==b){
                return true;
            }
            if(temp.size()>b.size()){
                return false;
            }
            temp+=a; 
        }
        return false; 
    }
    
    string gcdOfStrings(string str1, string str2){
        string lastGCD="";
        string temp="";
        for(int i=0;i<str2.size();i++){
            temp+=str2[i];
            if(adividesbCompletely(temp,str1)==true && adividesbCompletely(temp,str2)==true){
                lastGCD=temp;
            }
        }
        return lastGCD;
    }
};