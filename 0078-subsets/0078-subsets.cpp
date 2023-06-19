class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        helper(nums,res,0,nums.size()-1,subset);
        return res;
        }
private:
    void helper(const vector<int>& v,vector<vector<int>>& res, int start,int end,vector<int>& subset){
        if (start >end){
            res.push_back(subset);
            return;
        }
        subset.push_back(v[start]);
        helper(v,res,start+1,end,subset);
        subset.pop_back();
        helper(v,res,start+1,end,subset);
    }
};