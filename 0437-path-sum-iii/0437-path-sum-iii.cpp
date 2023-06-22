class Solution {
public:
    unordered_map<long ,long> m;
    int c = 0;
    void countPathSum(TreeNode* root, int target, long sum){
        if(!root)
            return;
        sum += root->val;
        if(sum == target)
            c++;
        if(m.find(sum-target) != m.end())
            c += m[sum-target];
        m[sum]++;
        countPathSum(root->left, target, sum);
        countPathSum(root->right, target, sum);
        m[sum]--;
    }
    int pathSum(TreeNode* root, int sum) {
        countPathSum(root, sum, 0);
        return c;
    }
};