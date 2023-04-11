// 2390. Removing Stars From a String
// Problem Link - https://leetcode.com/problems/removing-stars-from-a-string/

class Solution {
public:
    string removeStars(string s){
        stack<char> st;
        string answer="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        while(st.empty()==false){
            answer+=st.top();
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
