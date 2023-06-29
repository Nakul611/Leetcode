class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int &i:nums){
            set.insert(i);
        }
        int c = 0;
        for(int &i:nums){
            if(set.find(i-1) == set.end()){
                int temp = i;
                int seq = 1;
                while(set.find(temp+1) != set.end()){
                    temp++;
                    seq++;
                }
                c = max(c, seq);
            }
        }
        return c;
    }
};