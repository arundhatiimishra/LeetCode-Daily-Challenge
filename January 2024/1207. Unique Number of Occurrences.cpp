// 1207. Unique Number of Occurrences
// Problem Link - https://leetcode.com/problems/unique-number-of-occurrences/

// Time Complexity - O(N*log N)
// Space Complexity - O(N)

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int i=0;i<arr.size();i++){
            freq[arr[i]]++;
        }
        unordered_map<int,int> freqOfFreq;
        unordered_map<int,int>::iterator it;
        for(it=freq.begin();it!=freq.end();it++){
            freqOfFreq[it->second]++;
            if(freqOfFreq[it->second]>1){
                return false;
            }
        }
        return true;
    }
};