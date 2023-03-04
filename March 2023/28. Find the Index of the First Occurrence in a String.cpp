// 28. Find the Index of the First Occurrence in a String
// Problem Link - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/ 

class Solution {
public:
    int strStr(string haystack, string needle){
        for(int i=0;i<haystack.size();i++){
            string temp=haystack.substr(i,needle.size());
            if(temp==needle){
                return i;
            }
        }
        return -1;
    }
};
