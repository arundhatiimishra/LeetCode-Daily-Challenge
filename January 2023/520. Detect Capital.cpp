// 520. Detect Capital
// Problem Link - https://leetcode.com/problems/detect-capital/


class Solution {
public:
    bool detectCapitalUse(string word){
        int countCap=0;
        int countSma=0;
        for(int i=0;i<word.size();i++){
            if(word[i]<='Z' && word[i]>='A'){
                countCap++;
            }else{
                countSma++;
            }
        }
        if(countCap==word.size()||countSma==word.size()){
            return true;
        }
        if(countCap==1 && word[0]<='Z' && word[0]>='A'){
            return true;
        }
        return false;
    }
};
