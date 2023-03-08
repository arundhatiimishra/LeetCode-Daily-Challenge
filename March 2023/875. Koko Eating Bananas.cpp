// 875. Koko Eating Bananas
// Problem Link - https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h){
        sort(piles.begin(),piles.end());
        int start=1;
        int end=piles[piles.size()-1];
        int answer=INT_MAX;
        while(start<=end){
            int mid=(start+end)/2;
            long long numberOfHoursReq=0;
            for(int i=0;i<piles.size();i++){
                if(piles[i]%mid==0){
                    numberOfHoursReq+=(piles[i]/mid);
                }else{
                    numberOfHoursReq+=((piles[i]/mid)+1);
                }
            }
            if(numberOfHoursReq<=h){
                answer=min(answer,mid);
                end=mid-1;
            }else{
                start=mid+1;  
            }
        }
        return answer;
    }
};