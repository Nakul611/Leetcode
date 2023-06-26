class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        priority_queue<int,vector<int>,greater<int>> pq1,pq2;
        int c=0;
        int i=0;
        int j=costs.size()-1;
        while(c<k){
            while(pq1.size()<candidates && i<=j){ 
                pq1.push(costs[i++]);
            }
            while(pq2.size()<candidates && j>=i){ 
                pq2.push(costs[j--]);
            }
            int cost1 = 0;
            if(pq1.size()>0)
                cost1=pq1.top();
            else
                cost1=INT_MAX;
            int cost2 = 0;
            if(pq2.size()>0)
                cost2=pq2.top();
            else
                cost2=INT_MAX;
                
            if(cost1<=cost2){
                ans += cost1;
                pq1.pop();
            }
            else{
                ans += cost2;
                pq2.pop();
            }
            c++;
        }
        return ans;
    }
};