class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<int> v(amount+1, 0);
        v[0] = 1;
        for(int i=0;i<n;i++){
          for(int j=coins[i];j<=amount;j++){
                int x = j-coins[i];
                v[j] += v[x];
            }
        }
        return v[amount];
    }
};