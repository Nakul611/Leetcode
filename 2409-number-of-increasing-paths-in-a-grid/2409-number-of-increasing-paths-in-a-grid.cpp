#define ll long long
class Solution {
public:
    ll m,n,mod=1e9+7;
    ll dp[1005][1005],a[1005][1005],visit[1005][1005];
    ll dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    void dfs(ll x,ll y){
        if(visit[x][y])
            return;
        visit[x][y]=1;
        dp[x][y]=1;
        for(ll i=0;i<4;i++){
            ll x1=x+dx[i],y1=y+dy[i];
            if(x1>=0 && x1<m && y1>=0 && y1<n && a[x][y]<a[x1][y1]){
                dfs(x1,y1);
                if(dp[x1][y1]){
                    dp[x][y]=(dp[x][y]+dp[x1][y1])%mod;
                }
            }
        }
    }
    int countPaths(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                dp[i][j]=0;
                a[i][j]=matrix[i][j];
                visit[i][j]=0;
            }
        }
        ll ans=0;
        for(ll i=0;i<m;i++){
            for(ll j=0;j<n;j++){
                if(visit[i][j]==0){
                    dfs(i,j);
                }
                ans=(ans+dp[i][j])%mod;
            }
        }
        return ans;
    }
};