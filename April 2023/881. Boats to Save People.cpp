// 881. Boats to Save People
// Problem Link - https://leetcode.com/problems/boats-to-save-people/

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit){
        sort(people.begin(),people.end());
        int countBoats=0;
        int ptr1=0,ptr2=people.size()-1;
        while(ptr1<=ptr2){
            if(ptr2<0){
                break;
            }
            if(ptr1>people.size()-1){
                break;
            }
            if(ptr1==ptr2){
                countBoats++;
                break;
            }
            if(people[ptr1]+people[ptr2]<=limit){
                ptr1++;
                ptr2--;
                countBoats++;
            }else if(people[ptr2]<=limit){
                ptr2--;
                countBoats++;
            }
        }
        return countBoats; 
    }
};
