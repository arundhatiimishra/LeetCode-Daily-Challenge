// 2264. Largest 3-Same-Digit Number in String
// Problem Link - https://leetcode.com/problems/largest-3-same-digit-number-in-string/

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans="";
        for(int i=2;i<num.size();i++){
            if(num[i]==num[i-1] && num[i]==num[i-2]){
                if(ans==""){
                    ans+=num[i];
                    ans+=num[i];
                    ans+=num[i];
                }else{
                    if(ans[0]<num[i]){
                        ans[0]=num[i];
                        ans[1]=num[i];
                        ans[2]=num[i];
                    }
                }
            }
        }
        return ans;
    }
};
