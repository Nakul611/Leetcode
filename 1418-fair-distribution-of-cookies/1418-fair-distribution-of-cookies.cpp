class Solution {
public:
    void solve(int start, const vector<int>& cookies, vector<int>& v, int k, int& ans) {
        int n = cookies.size();
        if (start == n) {
            int maxi = INT_MIN;
            for (int i=0;i<k;i++) {
                maxi = max(maxi,v[i]);
            }
            ans = min(ans,maxi);
            return;
        }
        for (int i=0;i<k;i++) {
            v[i] += cookies[start];
            solve(start + 1, cookies, v, k, ans);
            v[i] -= cookies[start];
        }
    }
    int distributeCookies(vector<int>& cookies, int k) {
        int ans = INT_MAX;
        vector<int> v(k);
        solve(0, cookies, v, k, ans);
        return ans;
    }
};