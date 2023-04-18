// 1768. Merge Strings Alternately
// Problem Link - https://leetcode.com/problems/merge-strings-alternately/

class Solution {
public:
    string mergeAlternately(string word1, string word2){
        string answer="";
        int ptr1=0;
        int ptr2=0;
        while(ptr1!=word1.size()&&ptr2!=word2.size()){
            answer+=word1[ptr1];
            answer+=word2[ptr2];
            ptr1++;
            ptr2++;
        }
        while(ptr1!=word1.size()){
            answer+=word1[ptr1];
            ptr1++;
        }
        while(ptr2!=word2.size()){
            answer+=word2[ptr2];
            ptr2++;
        }
        return answer;
    }
};
