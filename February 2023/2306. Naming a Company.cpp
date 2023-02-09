// 2306. Naming a Company
// Problem Link - https://leetcode.com/problems/naming-a-company/

class Solution {
public:
    long long distinctNames(vector<string>& s) {
        int n=s.size();
        unordered_map<string,bool> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]=true;
        }
        vector<vector<long long>> dict(26,vector<long long>(26,0));
        for(int i=0;i<n;i++){
            string str=s[i].substr(1);
            int in=s[i][0]-'a';
            for(int j=0;j<26;j++){
                char ch=j+'a';
                string res=ch+str;
                if(mp.count(res)==0){
                    dict[in][j]+=1;
                }
            }
        }
        long long cnt=0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(dict[i][j]>0 and i!=j){
                    cnt+=dict[i][j]*dict[j][i];
                }
            }
        }
        return cnt;
    }
};
