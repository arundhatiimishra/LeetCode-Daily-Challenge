// 1443. Minimum Time to Collect All Apples in a Tree
// Problem Link - https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
public:
    int dfs(int node,int parent,vector<vector<int>> &adjList,vector<bool> &hasApple){
        int sumOfTimeTaken=0;
        for(int i=0;i<adjList[node].size();i++){
            if(adjList[node][i]!=parent){
                int timeTakenByChildren=dfs(adjList[node][i],node,adjList,hasApple);
                if(hasApple[adjList[node][i]]==true){
                    sumOfTimeTaken=sumOfTimeTaken+timeTakenByChildren+2;
                    hasApple[node]=true;
                }
            }
        }
        return sumOfTimeTaken; 
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple){
        vector<vector<int>> adjList(hasApple.size());
        for(int i=0;i<edges.size();i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,-1,adjList,hasApple);
    }
};
