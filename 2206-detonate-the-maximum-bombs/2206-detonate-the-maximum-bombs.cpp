class Solution{
public:
long long dis(int x1, int y1, int x2, int y2)
{
    return pow(x2-x1,2) + pow(y2-y1,2);
}
void dfs(int node, vector<vector<int>> &adj, vector<bool>& visited , int &count){
    if(visited[node]) 
        return;
    visited[node]=true;
    count++;
    for(auto i: adj[node])
        if(!visited[i])
            dfs(i,adj,visited,count);
}
int maximumDetonation(vector<vector<int>>& bomb) {
    
    int n=bomb.size();
    
    vector<vector<int>> adj(n);
    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            long long r =dis(bomb[i][0],bomb[i][1],bomb[j][0],bomb[j][1]);
            if(r<= pow(bomb[i][2],2)) adj[i].push_back(j);
            if(r<= pow(bomb[j][2],2)) adj[j].push_back(i);
        }
    
    int ans=INT_MIN;
    
    vector<bool> visited;
    for(int i=0;i<n;i++){
        visited=vector(n,false);
        int count=0;
        dfs(i,adj,visited,count);
        ans=max(ans,count);
    }
    return ans;
    }
};