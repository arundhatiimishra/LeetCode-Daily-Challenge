// 1539. Kth Missing Positive Number
// Problem Link - https://leetcode.com/problems/kth-missing-positive-number/ 

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k){
        arr.push_back(2001);
        int ptr1=1;
        int ptr2=0;
        while(true){
            while(ptr1!=arr[ptr2]){
                ptr1++;
                k--;
                if(k==0){
                    return ptr1-1;
                }
            }
            ptr2++;
            ptr1++;
        }
        return -1; 
    }
};
