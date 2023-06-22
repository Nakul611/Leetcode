class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN,sell = 0;
        for (auto &i:prices) {
            buy = max(buy,sell-i);
            sell = max(sell,buy+i-fee);
        }
        return sell;
    }
};