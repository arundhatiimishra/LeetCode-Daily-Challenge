// 735. Asteroid Collision
// Problem Link - https://leetcode.com/problems/asteroid-collision/

// Time Complexity - O(N)
// Space Complexity - O(N)

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids){
        vector<int> answer;
        stack<int> st;
        for(int i=0;i<asteroids.size();i++){
            if(st.empty()==true||asteroids[i]>0){
                st.push(asteroids[i]);
                continue;
            }
            if(asteroids[i]<0 && st.empty()==false && st.top()>0){
                if(abs(asteroids[i])<st.top()){
                    continue;
                }else if(abs(asteroids[i])==st.top()){
                    st.pop(); 
                }else{
                    while(st.empty()==false && (st.top()>0 && st.top()<abs(asteroids[i]))){
                        st.pop();
                    }
                    if(st.empty()==false && st.top()==abs(asteroids[i])){
                        st.pop();
                        continue;
                    }
                    if(st.empty()==true||st.top()<0){
                        st.push(asteroids[i]);
                    }
                }
            }else if(asteroids[i]<0 && st.top()<0){
                st.push(asteroids[i]);
            }
        }
        while(st.empty()==false){
            answer.push_back(st.top());
            st.pop();
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
