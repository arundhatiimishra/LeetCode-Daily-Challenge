// 1011. Capacity To Ship Packages Within D Days
// Problem Link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

class Solution {
public:
    int ship(vector<int> &weights,int weight){
        int countDays=0;
        int currWeight=0;
        for(int i=0;i<weights.size();i++){
            if(currWeight+weights[i]<=weight){
                currWeight+=weights[i];
            }else{
                currWeight=weights[i];
                countDays++;
            }  
        }
        countDays++;
        return countDays;
    }
    
    int shipWithinDays(vector<int>& weights,int days){
        int start=0;
        int end=0;
        for(int i=0;i<weights.size();i++){
            start=max(weights[i],start);
            end+=weights[i];
        }
        int minAns=end;
        while(start<=end){
            if(ship(weights,start)<=days){
                minAns=min(minAns,start);
            }
            int mid=(start+end)/2;
            if(ship(weights,mid)>days){
                start=mid+1;
            }else{
                minAns=min(minAns,mid);
                end=mid-1;
            }
        }
        return minAns;
    }
};
