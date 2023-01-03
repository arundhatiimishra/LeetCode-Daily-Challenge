// 944. Delete Columns to Make Sorted
// Problem Link - https://leetcode.com/problems/delete-columns-to-make-sorted/

class Solution{
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        int n=strs[0].size();
        for(int i=0;i<n;i++){
            int asciiVal=0;
            for(int j=0;j<strs.size();j++){
                if((int)strs[j][i]<asciiVal){
                    count++;
                    break;
                }else{
                    asciiVal=(int)strs[j][i];
                }
            }
        }
        return count;
    }
};
