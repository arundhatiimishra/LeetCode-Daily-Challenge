// 347. Top K Frequent Elements
// Problem Link - https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int>::iterator it;
        for(it=mp.begin();it!=mp.end();it++){
            pq.push(make_pair(it->second,it->first));
        }
        int temp=0;
        vector<int> answer;
        while(true){
            if(temp==k){
                break;
            }
            answer.push_back(pq.top().second);
            pq.pop();
            temp++;
        }
        return answer;
    }
};