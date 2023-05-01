// 1065. Index Pairs of a String
// Problem Link - https://leetcode.com/problems/index-pairs-of-a-string/

class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words){
        vector<vector<int>> answer;
        for(int i=0;i<text.size();i++){
            for(int j=0;j<words.size();j++){
                string temp=text.substr(i,words[j].size());
                if(temp==words[j]){
                    vector<int> toPush;
                    toPush.push_back(i);
                    toPush.push_back(i+words[j].size()-1);
                    answer.push_back(toPush);
                }
            }
        }
        sort(answer.begin(),answer.end());
        return answer;
    }
};
