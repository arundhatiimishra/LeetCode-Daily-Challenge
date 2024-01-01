// 455. Assign Cookies
// Problem Link - https://leetcode.com/problems/assign-cookies/

// Time Complexity -  O(N log N)
// Space Complexity - O(1)

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int countChildren=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int ptrG=g.size()-1;
        int ptrS=s.size()-1;
        while(ptrG>=0 && ptrS>=0){
            if(s[ptrS]>=g[ptrG]){
                ptrG--;
                ptrS--;
                countChildren++;
            }else{
                ptrG--;
            }
        }
        return countChildren;   
    }
};