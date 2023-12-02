// 1160. Find Words That Can Be Formed by Characters
// Problem Link - https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/

// Time Complexity -  O(N*M)
// Space Complexity - O(N*26)

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> check(26,0);
        for(int i=0;i<chars.size();i++){
            check[chars[i]-'a']++;
        }
        int count=0;
        for(int i=0;i<words.size();i++){
            vector<int> temp(26,0);
            for(int j=0;j<words[i].size();j++){
                temp[words[i][j]-'a']++;
            }
            bool possible=true;
            for(int it=0;it<temp.size();it++){
                if(check[it]<temp[it]){
                    possible=false;
                    break;
                }
            }
            if(possible==true){
                count+=(words[i].size());
            }
        }
        return count;
    }
};
