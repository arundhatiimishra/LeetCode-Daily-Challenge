// 77. Combinations
// Problem Link - https://leetcode.com/problems/combinations/

// TC - O(2^N)
// SC - 

class Solution{
public:
    vector<vector<int>> answer;
    
    void getAnswer(int n,int k,vector<int>& temp){
        if(n==0){
            if(k==0){
                answer.push_back(temp);
            }
            return;
        }
        temp.push_back(n);
        getAnswer(n-1,k-1,temp);
        temp.pop_back();
        getAnswer(n-1,k,temp);  
    }
    
    vector<vector<int>> combine(int n, int k){
        vector<int> temp;
        getAnswer(n,k,temp);
        return answer;
    }
};
