// 2405. Optimal Partition of String
// Problem Link - https://leetcode.com/problems/optimal-partition-of-string/

class Solution {
public:
    int partitionString(string s){
        int count=1;
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==0){
                freq[s[i]-'a']++;
            }else{
                count++;
                for(int i=0;i<freq.size();i++){
                    freq[i]=0;
                }
                freq[s[i]-'a']++;
            }
        }
        return count;
    }
};
