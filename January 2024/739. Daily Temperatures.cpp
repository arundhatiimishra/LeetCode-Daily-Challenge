// 739. Daily Temperatures
// Problem Link - https://leetcode.com/problems/daily-temperatures/

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> answer(temperatures.size(),0);
        for(int i=temperatures.size()-1;i>=0;i--){
            if(st.size()==0){
                st.push(i);
            }else{
                int currTemp=temperatures[i];
                while(st.empty()==false && currTemp>=temperatures[st.top()]){
                    st.pop();
                }
                if(st.empty()==false){
                    answer[i]=st.top()-i;
                }
                st.push(i);
            }   
        }
        return answer;
    }
};