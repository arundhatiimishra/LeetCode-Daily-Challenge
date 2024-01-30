// 150. Evaluate Reverse Polish Notation
// Problem Link - https://leetcode.com/problems/evaluate-reverse-polish-notation/

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i].size()==1 && (tokens[i][0]=='+'||tokens[i][0]=='-'||tokens[i][0]=='*'||tokens[i][0]=='/')){
                long long firstNum=st.top();
                st.pop();
                long long secondNum=st.top();
                st.pop();
                if(tokens[i][0]=='+'){
                    st.push(firstNum+secondNum);
                }else if(tokens[i][0]=='*'){
                    st.push(firstNum*secondNum);
                }else if(tokens[i][0]=='-'){
                    st.push(secondNum-firstNum);
                }else{
                    st.push(secondNum/firstNum);
                }
            }else{
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};