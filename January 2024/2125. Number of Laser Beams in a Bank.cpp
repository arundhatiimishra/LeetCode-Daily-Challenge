// 2125. Number of Laser Beams in a Bank
// Problem Link - https://leetcode.com/problems/number-of-laser-beams-in-a-bank/

// Time Complexity -  O(N*M)
// Space Complexity - O(1)

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prevRowDevices=0;
        int countBeams=0;
        int currRowDevices=0;
        for(int i=0;i<bank[0].size();i++){
            prevRowDevices+=(bank[0][i]-'0');
        }
        for(int i=1;i<bank.size();i++){
            currRowDevices=0;
            for(int j=0;j<bank[0].size();j++){
                currRowDevices+=(bank[i][j]-'0');
            }
            if(currRowDevices>0){
                countBeams+=(prevRowDevices*currRowDevices);
                prevRowDevices=currRowDevices; 
            }
        }
        return countBeams;
    }
};