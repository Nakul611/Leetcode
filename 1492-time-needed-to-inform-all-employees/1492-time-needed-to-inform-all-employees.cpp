class Solution {
private:
    int dfs(int manager,vector<int>& informTime,unordered_map<int,vector<int>>& adjList) {
        int maxTime = 0;
        if (adjList.find(manager) != adjList.end()) {
            for (int subordinate:adjList[manager]) {
                maxTime = max(maxTime, dfs(subordinate, informTime, adjList));
            }
        }
        return maxTime + informTime[manager];
    }
public:
    int numOfMinutes(int n, int headID,vector<int>& manager,vector<int>& informTime) {
        unordered_map<int,vector<int>> adjList;
        for (int i=0;i<n;i++) {
            if (manager[i] != -1) {
                adjList[manager[i]].push_back(i);
            }
        }

        return dfs(headID, informTime, adjList);
    }
};