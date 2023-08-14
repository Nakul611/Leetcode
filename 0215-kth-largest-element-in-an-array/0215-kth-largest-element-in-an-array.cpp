class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        int a;
        while(--k){
            pq.pop();
        }
        return pq.top();
    }
    int findKthLargest1(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        vector<int> v;
        for(auto i:m){
            v.push_back(i.first);
        }
        for(auto i:v){
            cout<<i<<' ';
        }
        int a=v.size();
        cout<<a<<endl;
        return v[a-1-k];
    }
};