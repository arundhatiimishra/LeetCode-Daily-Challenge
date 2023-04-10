// 20. Valid Parentheses
// Problem Link - https://leetcode.com/problems/valid-parentheses/

class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.empty()==false){
                if(st.top()=='(' && s[i]==')'){
                    st.pop();
                }else if(st.top()=='{' && s[i]=='}'){
                    st.pop();
                }else if(st.top()=='[' && s[i]==']'){
                    st.pop();
                }else{
                    st.push(s[i]);
                } 
            }else{
                st.push(s[i]);
            }
        }
        if(st.size()==0){
            return true;
        }
        return false;
    }
};