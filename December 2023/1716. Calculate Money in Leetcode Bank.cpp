// 1716. Calculate Money in Leetcode Bank
// Problem Link - https://leetcode.com/problems/calculate-money-in-leetcode-bank/

// Time Complexity - O(1)
// Space Complexity - O(1)

class Solution {
public:
    int totalMoney(int n) { 
        int totalSavings=0;
        int totalFullWeeks=n/7;
        int remainingDays=n%7;
        totalSavings+=(28*totalFullWeeks)+(7*(totalFullWeeks*(totalFullWeeks-1)/2));
        totalSavings+=(remainingDays+totalFullWeeks)*(remainingDays+totalFullWeeks+1)/2;
        totalSavings-=(totalFullWeeks*(totalFullWeeks+1)/2);
        return totalSavings;
    }
};
