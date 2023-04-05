// 2439. Minimize Maximum of Array
// https://leetcode.com/problems/minimize-maximum-of-array/

// TC - O(N*log N)
// SC - O(1)

class Solution {
public:
    int answer=0;
    
    bool isPossible(vector<int> nums,int num){
        long long extra=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(nums[i]>num){
                extra=extra+(nums[i]-num);
            }else if(nums[i]==num){
                continue;
            }else{
                extra=extra-(num-nums[i]);
                if(extra<0){
                    extra=0;
                }
            }
        }
        if(extra==0){
            return true;
        }
        return false;
    }
    
    void xyz(vector<int> &nums,int start,int end){
        if(start==end){
            if(isPossible(nums,start)==true){
                answer=min(answer,start);
            }
            return;
        }
        if(start>end){
            return;
        }
        int mid=(end+start)/2;
        if(isPossible(nums,start)==true){
            answer=min(answer,start);
            return;
        }
        if(isPossible(nums,mid)==true){
            answer=min(answer,mid);
            xyz(nums,start,mid-1);   
        }else{
            xyz(nums,mid+1,end);
        } 
    }
    
    int minimizeArrayValue(vector<int>& nums){
        long long prefixSum=0;
        int greatestNum=0;
        int mean=0;
        for(int i=0;i<nums.size();i++){
            prefixSum+=nums[i];
            greatestNum=max(nums[i],greatestNum);
        }
        mean=prefixSum/nums.size();
        answer=greatestNum;
        xyz(nums,mean,greatestNum); 
        return answer; 
    }
};

// TC - O(N)
// SC - O(N)

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums){
        vector<long long> prefixSum(nums.size(),0);
        long long answer=0;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                prefixSum[i]=nums[i];
            }else{
                prefixSum[i]=nums[i]+prefixSum[i-1];
            }
            if(prefixSum[i]%(i+1)==0){
                answer=max(answer,prefixSum[i]/(i+1));
            }else{
                answer=max(answer,(prefixSum[i]/(i+1))+1);
            }               
        }
        int myAns=answer;
        return myAns;
    }
};    

// TC - O(N)
// SC - O(1)

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums){
        long long sum=0;
        long long answer=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum%(i+1)==0){
                answer=max(answer,sum/(i+1));
            }else{
                answer=max(answer,(sum/(i+1))+1);
            }               
        }
        return answer;
    }
};    
