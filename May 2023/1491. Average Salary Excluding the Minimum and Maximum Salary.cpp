// 1491. Average Salary Excluding the Minimum and Maximum Salary
// Problem Link - https://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/

class Solution {
public:
    double average(vector<int>& salary){
        int minSal=INT_MAX;
        int maxSal=INT_MIN;
        double salSum=0;
        for(int i=0;i<salary.size();i++){
            salSum+=salary[i];
            minSal=min(minSal,salary[i]);
            maxSal=max(maxSal,salary[i]);
        }
        return (salSum-(minSal+maxSal))/(salary.size()-2);     
    }
};