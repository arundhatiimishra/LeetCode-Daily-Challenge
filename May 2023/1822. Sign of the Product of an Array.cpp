// 1822. Sign of the Product of an Array
// Problem Link - https://leetcode.com/problems/sign-of-the-product-of-an-array/

class Solution {
public:
    int arraySign(vector<int>& nums){
        bool hasZero=false;
        int countNeg=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                hasZero=true;
                break;
            }
            if(nums[i]<0){
                countNeg++;
            } 
        }
        if(hasZero==true){
            return 0;
        }
        if(countNeg%2==0){
            return 1;
        }
        return -1;
    }
};
