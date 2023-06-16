class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto &i:nums){
            m[i]++;
        }
        vector<int> v;
        for(auto &i:m){
            if(i.second == 1)
                v.push_back(i.first);
            else if(i.second > 1){
                v.push_back(i.first);
                v.push_back(i.first);
            }
        }
        nums.clear();
        nums=v;
        sort(nums.begin(),nums.end());
        // for(auto k : v)
        // cout<<k<<" ";
        return nums.size();
    }
};