// 258. Add Digits
// Problem Link - https://leetcode.com/problems/add-digits/

class Solution {
public:
    int getSum(int num){
        if(num/10==0){
            return num;
        }
        int tempNum=0;
        while(num!=0){
            tempNum+=(num%10);
            num/=10;
        }
        return getSum(tempNum);
    }
    
    int addDigits(int num){
        return getSum(num);
    }
};
