class SeatManager {
public:
    priority_queue<int,vector<int>,greater<int>>minheap;
    SeatManager(int n) {
        for(int i=1;i<=n;i++)
            minheap.push(i);
    }
    
    int reserve() {
        int ans=minheap.top();
        minheap.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        minheap.push(seatNumber);
    }
};