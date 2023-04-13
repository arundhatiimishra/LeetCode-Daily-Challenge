// 946. Validate Stack Sequences
// Problem Link - https://leetcode.com/problems/validate-stack-sequences/

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped){
        stack<int> st;
        int ptr=0;
        for(int i=0;i<pushed.size();i++){
            st.push(pushed[i]);
            if(st.top()==popped[ptr]){
                while(st.top()==popped[ptr]){
                    st.pop();
                    ptr++;
                    if(st.empty()==true){
                        break;
                    }
                }
            }
        }
        if(st.empty()==true){
            return true;
        }
        return false;  
    }
};
