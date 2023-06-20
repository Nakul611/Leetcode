class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int w1 = 2*k+1;
        long long w2 = 0;
        vector<int> v(nums.size(),-1);

        if (nums.size() < w1) {
            return v;
        }

        for (int i=0;i<nums.size();i++) {
            w2 += nums[i];
            if (i-w1 >= 0)
                w2 -= nums[i-w1];
            if (i >= w1-1) 
                v[i-k] = w2/w1;
        }
        return v;
    }
};