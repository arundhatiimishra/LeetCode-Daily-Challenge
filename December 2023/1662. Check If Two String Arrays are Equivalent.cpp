// 1662. Check If Two String Arrays are Equivalent
// Problem Link - https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

// Time Complexity - O(N*M)
// Space Complexity - O(1)

class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2){
        int idx1=0;
        int idx2=0;
        int ptr1=0;
        int ptr2=0;
        bool answer=false;
        while(true){
            if(ptr1==word1[idx1].size()){
                ptr1=0;
                idx1++;
            }
            if(ptr2==word2[idx2].size()){
                ptr2=0;
                idx2++;
            }
            if(idx1==word1.size() && idx2==word2.size()){
                return true;
            }else if(idx1==word1.size()||idx2==word2.size()){
                return false;
            }
            if(word1[idx1][ptr1]!=word2[idx2][ptr2]){
                return false; 
            }else{
                ptr1++;
                ptr2++;
            }
        }
        return true;
    }
};
