// 1903. Largest Odd Number in String
// Problem Link - https://leetcode.com/problems/largest-odd-number-in-string/

// Time Complexity - O(N)
// Space Complexity - O(1)

class Solution {
public:
    string largestOddNumber(string num){
        string largestOdd="";
        int ind=-1;
        for(int i=num.size()-1;i>=0;i--){
            if((num[i]-'0')%2!=0){
                ind=i;
                break;
            }
        }
        for(int i=0;i<=ind;i++){
            largestOdd+=num[i];
        }
        return largestOdd;
    }
};
